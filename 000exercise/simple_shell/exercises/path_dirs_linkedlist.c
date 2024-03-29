#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a linked list node
typedef struct Node {
    char* directory;
    struct Node* next;
} Node;

// Declare the extern variable environ
extern char** environ;

// Function to build a linked list of PATH directories
Node* build_path_list() {
    // Get the value of the PATH environment variable
    char* path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found\n");
        return NULL;
    }

    // Initialize variables
    Node* head = NULL;
    Node* tail = NULL;

    // Split the PATH string at each colon and create a node for each directory
    char* token = strtok(path, ":");
    while (token != NULL) {
        // Create a new node for the directory
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        new_node->directory = strdup(token);
        if (new_node->directory == NULL) {
            printf("Memory allocation failed\n");
            free(new_node);
            return NULL;
        }
        new_node->next = NULL;

        // Add the node to the linked list
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        // Move to the next token
        token = strtok(NULL, ":");
    }

    return head;
}

// Function to print the linked list of directories
void print_path_list(Node* head) {
    printf("PATH directories:\n");
    while (head != NULL) {
        printf("%s\n", head->directory);
        head = head->next;
    }
}

// Function to free the memory allocated for the linked list
void free_path_list(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp->directory);
        free(temp);
    }
}

int main() {
    // Build the linked list of PATH directories
    Node* path_list = build_path_list();
    if (path_list != NULL) {
        // Print the linked list
        print_path_list(path_list);
        // Free the memory allocated for the linked list
        free_path_list(path_list);
    }
    return 0;
}
