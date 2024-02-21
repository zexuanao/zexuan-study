#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_MODE_NEW "-1"
#define FILE_MODE_APPEND "-2"
#define FILE_MODE_DELETE "-3"

void createFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void appendToFile(const char* filename, const char* data) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error appending to file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n", data);
    fclose(file);
}

void deleteFile(const char* filename) {
    if (remove(filename) != 0) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [-1 | -2 | -3] <filename> <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* mode = argv[1];
    const char* filename = argv[2];
    const char* data = argv[3];

    if (strcmp(mode, FILE_MODE_NEW) == 0) {
        createFile(filename);
    }
    else if (strcmp(mode, FILE_MODE_APPEND) == 0) {
        appendToFile(filename, data);
    }
    else if (strcmp(mode, FILE_MODE_DELETE) == 0) {
        deleteFile(filename);
    }
    else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
