#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void argchecker(int argc, char* argv[]);

int main(int argc, char* argv[]){
    argchecker(argc, argv);
    char ch;
    char* name = argv[1];  
    char* pattern = argv[2];
    char* buffer = (char*) malloc(sizeof(char)); //Points to an array of characters that the file has.
    int* indices = (int*) malloc(sizeof(int)); //Points to an array of integers that represent the indices where the buffer matches the pattern.
    FILE* fIn = fopen(name, "r");  //Make the file pointer show to our file defined by argv[1].

    if (fIn == 0){  //Error handling.
        //fopen returns 0, the NULL pointer, on failure
        perror("Cannot open input file\n");
        exit(-1);
    }

    int bSize = 0;  //bSize used to track the buffer size.
    while((ch = fgetc(fIn)) != EOF){ //Loop through the file until EOF
        buffer[bSize] = ch;
        bSize++;
        buffer = (char*) realloc(buffer, sizeof(char) * (1+bSize)); //Reallocate the size of the buffer for dynamic memory allocation.
        if(!buffer){  //Error handling.
            //Catch memory reallocation failure.
            free(buffer);
            perror("Memory reallocation failed\n");
            exit(-2);
        }
    }

    size_t psize = strlen(pattern); //Length of the pattern  
    int fFlag;  //Flag that is used in order to check if a pattern is found. If found fFlag = 1. 
    int cFound = 0; //Counts how many times the pattern was found.

    clock_t before = clock();
    for(int i = 0; i < bSize; i++){ //Loop through the buffer.
        fFlag = 1;  //Assume that it is found.
        for(int j = 0; j < psize; j++){ //Loop through the indices where it is found.
            if(buffer[i+j] != pattern[j]){  //If the character does not match.
                fFlag = 0;  //Change the flag value to notFound 0.
                break;  //Exit the inner loop.
            }
        }
        if(fFlag){  //If we passed through without entering the if inside the inner loop that means we have a match.
            printf("Found at index %d\n", i); //Debug message
            indices[cFound] = i; //Append the index to the array
            cFound++; //Increment the counter of the matches found.
            indices = (int*) realloc(indices, sizeof(int)*(1+cFound)); //Reallocate the size of the indices array for dynamic memory allocation. 
            if(!indices){ //Error handling
                //Catch memory reallocation failure.
                free(indices);
                perror("Memory reallocation failed\n");
                exit(-2);
            }
        }
    }
    clock_t after = clock();
    
    if(cFound == 0) //If nothing is found just exit.
        return 1;

    /*
    The below code is just being used in order to print the output to the screen
    The pattern matching implementation ends here. The format remains.
    */
    int rFlag = 0;  //rFlag is the red flag for output that must be printed red. If rflag = 1 then the text must not be printed again white.
    /*lambda is used to iterate less times through the array.
     *Lets say that we find a match as we iterate through the buffer and it is the first match. Then for sure it would be indices[0]. We don't need to iterate
     *again through this value because we found it. Now we are searching for the index of indices[1] etc...
     */
    
    int lambda = 0; 
    for(int i = 0; i < bSize; i++){ //Iterate through the buffer
        for(int j = lambda; j < cFound; j++){ //Lambda iteration through the found values
            if(i == indices[j]){ //If a match is found.
                printf("\x1B[31m%s",pattern);  //Print the whole pattern in red
                i+=(psize-1); //Increment i as much as to continue reading the buffer without the buffer.
                rFlag = 1;  //Declare that the print was a red print with rFlag = 1;
                lambda++; //Lambda is used in order to have less iterations with j
                break;
            }
        }
        if(!rFlag) //If it was not a red flag just continue printing characters
            printf("\x1B[0m%c", buffer[i]); //print white characters
        rFlag = 0; //Reinitialize the red flag value to 0
    }
    
    printf("Total matches: %d\n", cFound);  
    printf("Time taken: %fs\n", (double)(after - before)/CLOCKS_PER_SEC); //Calculate time taken
    free(buffer); //Free memory to prevent memory leaks 
    free(indices);
    fclose(fIn); //Close the file stream.
    return 0;
}

/* This procedure checks if the program has 3 arguments,  
 * arg[0] the program name, arg[1] the file name, arg[2] the char* pattern.
 * Returns an error message and exits the program if not the expected behaviour happens.
 */
void argchecker(int argc, char* argv[]){
    if(argc != 3){
        printf("Usage: %s <file> <pattern>\n", argv[0]);
        exit(1);
    }
}
