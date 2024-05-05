#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void grep(const char *search_string, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("grep: %s: No such file or directory\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found_flag = 0; 

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, search_string) != NULL) {
            found_flag = 1; 
            char *ptr = line;
            char *found_ptr;
            while ((found_ptr = strstr(ptr, search_string)) != NULL) {
                
                printf("%.*s", (int)(found_ptr - ptr), ptr);
                printf("\033[0;31m%s\033[0m", search_string);
                ptr = found_ptr + strlen(search_string); 
            }
            printf("%s", ptr);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s search_string filename\n", argv[0]);
        return 1;
    }

    const char *search_string = argv[1];
    const char *filename = argv[2];

    grep(search_string, filename);

    return 0;
}

