#include "../include/stack.h"
#include <stdio.h>
#include <malloc.h>

Stack* newStack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->size = STACK_SIZE;
    stack->stack = (bit*)malloc(STACK_SIZE * sizeof(bit));
    stack->head = -1;
    return stack;
}

void freeStack(Stack *stack)
{
    free(stack->stack);
    free(stack);
}

void enlargeStack(Stack* stack)
{
    bit* new_stack = realloc(stack->stack, stack->size + STACK_SIZE);
    stack->stack = new_stack;
}

void push(Stack* stack, int x) 
{
    // stack overflow
    if(stack->head == stack->size - 1)
    {enlargeStack(stack);}

    bit new;
    new.data = x;
    stack->stack[++stack->head] = new;
}


int pop(Stack* stack)
{
    if (stack->head == -1) // stack underflow
    {
        fprintf(stderr, "Fatal Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    return stack->stack[stack->head--].data;
}