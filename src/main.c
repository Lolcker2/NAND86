#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#include "../include/stack.h"
#include "../include/macro.h"
#include "../include/defines.h"


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
    //Stack* stack = newStack();
    MacroList* list = newMacroList();
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

            if(inMacro)
            {
                NextChar;
                char* name = readWord(line, lineIndex);
            }
            // if in macro readword = name
        }

        // if in macro read and add to macro code
        if(inMacro)
        {
            // add to macro code
        }
        
        PrintLine;
    
    }
    return 0;
}

int main()
{
    MacroList* l = newMacroList();
    printf("hello \n");
    insert(l, "eyal", "locker");

    printf("%s\n", l->list->name);

    freeList(l);
    return 0;

    
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