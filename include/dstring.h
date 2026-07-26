#ifndef DSTR_H
#define DSTR_H
#include <ctype.h>
#include <string.h>


#define DSTR_SIZE 1024

typedef struct 
{
    size_t size;
    int index;
    char* string;
}Dstring;


Dstring* newDstring();
void freeString(Dstring* dstr);
void append(Dstring* dstr, char* str);
void enlargeString(Dstring* str);

#endif