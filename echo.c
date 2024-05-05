#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if ((strcmp(argv[argc-2],">>") == 0) || (strcmp(argv[argc-2], ">") == 0))
    {   
        FILE* file;
        if (strcmp(argv[argc-2], ">") == 0)
        {
            file = fopen(argv[argc-1], "w");
        }
        else if (strcmp(argv[argc-2], ">>") == 0)
        {
            file = fopen(argv[argc-1], "a");
        }
        for (int i=1; i < argc - 2; i++)
        {
            fprintf(file,"%s ", argv[i]);
        }
        fprintf(file, "\n");
        fclose(file);
    }
    else
    {
        for (int i=1; i < argc; i++)
            printf("%s ", argv[i]);
        printf("\n");
    }    
}



