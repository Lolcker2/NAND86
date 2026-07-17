#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define STACK_SIZE 256

typedef struct
{
    unsigned int data :1;
}bit;

typedef struct
{   
    bit* stack;
    int head;
    size_t size;
}Stack;


Stack* newStack();
void freeStack(Stack *stack);
void enlargeStack(Stack* stack);
void push(Stack* stack, int x) ;
int pop(Stack* stack);

#endif