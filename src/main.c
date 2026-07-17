#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../include/stack.h"


#define LINE_SIZE 120
#define COMMENT ';'
#define MACRO '?'


#define FormatBool(b) ((b) ? "true" : "false")
#define GetLength(arr) (sizeof(arr)/sizeof(arr[0]))


#define iswhite(str) isspace(str) || str == 0 

#define NextChar do{\
lineIndex++;\
}while(iswhite(line[lineIndex]));\
if(lineIndex >= strlen(line)){lineIndex = -1;}

#define PrintLine for(int _ = lineIndex; _ < strlen(line); _++){\
printf("%c", line[_]);\
}

#define IgnoreComment if(line[lineIndex] == COMMENT){continue;}

FILE *file_ptr;
char *line;
int lineIndex;
char scanned_line[LINE_SIZE];
char scanned[LINE_SIZE];

char* readWord(char* line, int* lineIndex)
{
    char scanned[LINE_SIZE];
    char* result;
    int j = 0;
    for(; *lineIndex < LINE_SIZE && !iswhite(line[*lineIndex]); ++j)
    {
        scanned[j] = line[*lineIndex];       /* update the name of the label */
    }
    result = scanned;    /* updates label */
    result[j] = '\0';    /* end of string */

    return result;
}


int preprocess()
{
    file_ptr = fopen("Input.nd", "r");
    Stack* stack = newStack();
    int inMacro = 0;

    /* scan loop + code inside it. */
    while(fgets(scanned_line, LINE_SIZE, file_ptr) != NULL)
    {
        
        line = scanned_line;
        lineIndex = -1; /* -1 indicates an empty line, would be changed otherwise. */
        NextChar;
        IgnoreComment;


        if(line[lineIndex] == MACRO)
        {
            inMacro = !inMacro;

            // if in macro readword = name
        }

        // if in macro read and add to macro code
        
        PrintLine;
    
    }
    return 0;
}

int main()
{
    preprocess();
    return 0;
}


// push >
// pop <
// call ()
// return ~
// macro ?

// ? a 
// djijijdiwididij
// ?