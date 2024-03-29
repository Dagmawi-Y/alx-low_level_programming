#include <stdio.h>
#include <sys/stat.h>
#include <time.h> // Include the <time.h> header for ctime function

int main() {
    // Declare a structure to hold file information
    struct stat file_info;

    // Get the status of the file "my_document.txt"
    int result = stat("fork.c", &file_info);

    // Check if stat was successful
    if (result == 0) {
        // Print file size
        printf("File size: %lld bytes\n", (long long)file_info.st_size);

        // Print file owner
        printf("File owner: %d\n", file_info.st_uid);

        // Print last modification time
        printf("Last modified: %s", ctime((const time_t*)&file_info.st_mtime)); // Cast st_mtime to time_t
    } else {
        // Print an error message if stat failed
        perror("stat");
    }

    return 0;
}
