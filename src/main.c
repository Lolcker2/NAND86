#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#include "../include/stack.h"
#include "../include/macro.h"
#include "../include/defines.h"
#include "../include/dstring.h"


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
    for(; *lineIndex < LINE_SIZE && !iswhite(line[*lineIndex]); ++j, ++(*lineIndex))
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
    //Stack* stack = newStack();
    MacroList* list = newMacroList();

    Dstring* MacroLines;
    char* name;
    int inMacro = 0;

    /* scan loop + code inside it. */
    while(fgets(scanned_line, LINE_SIZE, file_ptr) != NULL)
    {
        
        line = scanned_line;
        lineIndex = -1; /* -1 indicates an empty line, would be changed otherwise. */
        NextChar;
        IgnoreComment;

        // begining and end of the macro's definition
        if(line[lineIndex] == MACRO)
        {
            printf("macro\n");
            inMacro = !inMacro;

            if(inMacro)
            {
                NextChar;
                name = readWord(line, &lineIndex);
                printf("macro name %s\n", name);
                MacroLines = newDstring();
            }
            else 
            {
                
                printf("macro code\n");
                insert(list, name, MacroLines->string);
                // reset macrolines
                // reset name
            }

            continue; // skip to the next line
        }

        // if in macro read and add to macro code
        if(inMacro)
        {
            append(MacroLines, line);
        }
        
        PrintLine;
    
    }

    printf("[name]: %s \n [code]: %s \n", list->list->name, list->list->code);
    return EXIT_SUCCESS;
}

int main()
{
    
    preprocess();
    return EXIT_SUCCESS;
}


// push >
// pop <
// call ()
// return ~
// macro ?

// ? a 
// djijijdiwididij
// ?