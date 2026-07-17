#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../include/stack.h"


#define LINE_SIZE 120
#define COMMENT ';'


#define FormatBool(b) ((b) ? "true" : "false")
#define GetLength(arr) (sizeof(arr)/sizeof(arr[0]))


#define NextChar do{\
lineIndex++;\
}while(isspace(line[lineIndex]) || line[lineIndex] == 0);\
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


int main()
{
    ah();
    return 0;
    file_ptr = fopen("Input.nd", "r");
    /* scan loop + code inside it. */
    while(fgets(scanned_line, LINE_SIZE, file_ptr) != NULL)
    {
        
        line = scanned_line;
        lineIndex = -1; /* -1 indicates an empty line, would be changed otherwise. */
        NextChar;
        IgnoreComment;
        

        printf("%d \n", lineIndex);

        PrintLine;
    }
    return 0;
}