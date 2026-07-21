#ifndef DSTR_H
#define DSTR_H
#include <ctype.h>

typedef struct 
{
    size_t size;
    int index;
    char* string;
}Dstring;


Dstring* newDstring();
void freeString(Dstring* dstr);
void append(Dstring* dstr, char* str);
// enlarge string

#endif