#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256

char **split_path(char *path, int *num_dirs) {
    char **dirs = NULL;
    int i = 0;
    char *token;

    *num_dirs = 0;
    while ((token = strsep(&path, ":")) != NULL) {
        if (i >= *num_dirs) {
            dirs = realloc(dirs, (i + 1) * sizeof(char *));
            if (dirs == NULL) {
                perror("malloc");
                return NULL;
            }
        }
        dirs[i++] = strdup(token);
        if (dirs[i - 1] == NULL) {
            perror("strdup");
            for (int j = 0; j < i - 1; j++) {
                free(dirs[j]);
            }
            free(dirs);
            return NULL;
        }
        *num_dirs = i;
    }
    return dirs;
}

void find_file(const char *filename, char **dirs, int num_dirs) {
    for (int i = 0; i < num_dirs; i++) {
        char *filepath = malloc(MAX_PATH_LENGTH);
        if (filepath == NULL) {
            perror("malloc");
            return;
        }
        snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", dirs[i], filename);
        if (access(filepath, F_OK) == 0) {
            printf("%s\n", filepath);
            free(filepath);
            return;
        }
        free(filepath);
    }
    printf("%s not found in PATH\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found\n");
        return EXIT_FAILURE;
    }

    int num_dirs;
    char **dirs = split_path(path, &num_dirs);
    if (dirs == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        find_file(argv[i], dirs, num_dirs);
    }

    for (int i = 0; i < num_dirs; i++) {
        free(dirs[i]);
    }
    free(dirs);

    return EXIT_SUCCESS;
}
