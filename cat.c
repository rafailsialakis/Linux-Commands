#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void manual()
{
    FILE *manual;
    char ch;

    manual = fopen(".man.txt", "r");
    while(ch != EOF)
    {
        ch = fgetc(manual);
        if (ch != EOF)
            printf("%c", ch);
    }
    fclose(manual);
}

int main(int argc, char* argv[])
{
    FILE *file;
    char *filename = argv[1];
    char ch;
    char str[100];
   
    if (argc == 1){
        while(true)
        {
            fgets(str, sizeof(str), stdin);
            printf("%s",str);
        }    
    }
    else if (argc == 2){
        if (!strcmp(argv[1],"--help")){          
            manual();
            exit(1);
        }
        
        if (access(filename, F_OK) == 0){
        
            file = fopen(filename, "r");
            while (ch != EOF)
            {
                ch = fgetc(file);
                if (ch != EOF)
                    printf("%c", ch);
            }
            fclose(file);
        }
        
        else
        {
            printf("cat: %s: No such file or directory\n", argv[1]);
        }
    }
    else if (argc == 3){
        printf("To be built...\n");
    }
}
