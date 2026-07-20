#ifndef MACRO_H
#define MACRO_H
#include <stddef.h>

#define MACRO_LIST_SIZE 10

#define MACRO_DEFAULT_LINE_NUMBER 10

typedef struct
{
    char* name;
    char* code;
}MacroEntry;

typedef struct
{
    size_t size;
    int last;
    MacroEntry* list;
    /* data */
}MacroList;


MacroList* newMacroList();
void freeList(MacroList* list);
void insert(MacroList* list, char* name, char* code);

#endif