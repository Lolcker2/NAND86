#ifndef DEFS_H
#define DEFS_H

#include <string.h>


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
printf("%c", line[_]);}

#define IgnoreComment if(line[lineIndex] == COMMENT){continue;}



#endif