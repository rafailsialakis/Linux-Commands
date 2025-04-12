#include <stdio.h>
#include <stdlib.h>

void argchecker(int argc, char* argv[]);

int main(int argc, char* argv[]){
    argchecker(argc,argv);
    int newlines = 0, bytes = 0, words = 1;
    int ok = 0;
    char* name = argv[1];
    FILE* fIn = fopen(name, "r");
    if (fIn == 0){  //Error handling.
        //fopen returns 0, the NULL pointer, on failure
        perror("Cannot open input file\n");
        exit(EXIT_FAILURE);
    }
    char ch;
    while ((ch = getc(fIn)) != EOF)
    {
        ok = 1;
        if(ch == '\n'){
            newlines++;
        }
        else if(ch == ' '){
            words++;
        }
        bytes++;
    }
    if(ok == 0){
        words = 0;
    }
    printf("  %d   %d %d %s\n",newlines, words, bytes, name);
    return(EXIT_SUCCESS);
}

void argchecker(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
}
