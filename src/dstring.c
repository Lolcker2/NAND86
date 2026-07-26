#include "../include/dstring.h"
#include <stdio.h>
#include <malloc.h>

Dstring* newDstring()
{
    Dstring* str = (Dstring*)malloc(sizeof(Dstring));
    str->size = DSTR_SIZE;
    str->string = (char*)malloc(str->size * sizeof(char));
    str->index = 0;
    return str;
}

void freeString(Dstring* str)
{
    free(str->string);
    free(str);
}

void enlargeString(Dstring* str)
{   
    str->size += DSTR_SIZE;
    char* new = (char*)malloc(str->size * sizeof(char));

    if (new == NULL) // mem allocation error
    {
        fprintf(stderr, "Fatal Error: Unable to allocate memory for Dstring\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(str->string, new); // from string to new
    
    free(str->string);
    str->string = new;
}

void append(Dstring* dstr, char* str)
{
    // string overflow
    if(dstr->index + strlen(str) >= dstr->size)
    {enlargeString(dstr);}
    
    dstr->index--; // overwrite null terminator
    for(int j = 0;j < strlen(str);dstr->index++, j++)
    {
        dstr->string[dstr->index] = str[j];
    }
    dstr->string[++dstr->index] = '\0'; // add back the null terminator
}
