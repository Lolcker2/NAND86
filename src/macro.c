#include "../include/macro.h"
#include "../include/defines.h"
#include <malloc.h>
#include <stdio.h>


// add the whole allocate 10 lines for the code

MacroList* newMacroList()
{
    MacroList* list = (MacroList*)malloc(sizeof(MacroList));
    list->size = MACRO_LIST_SIZE;
    list->list = (MacroEntry*)calloc(MACRO_LIST_SIZE, sizeof(MacroEntry));
    list->last = -1;
    return list;
}

void freeList(MacroList* list)
{
    free(list->list);
    free(list);
}


void insert(MacroList* list, char* name, char* code)
{
    if(list->last == list->size - 1)
    {
        list->size += 1;
        list->list = realloc(list->list, list->size*sizeof(MacroEntry));
    }
    
    list->list[++list->last].name = name;
    list->list[++list->last].code = code;
}

// add insert for just a name?
