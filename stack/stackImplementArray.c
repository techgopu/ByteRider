// Stack Implementation using array
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//a structure to represent stack
struct stack
{
    unsigned capacity;
    int top;
    int *array;
};

// a function to create stack of given capacity. it initialize the size of stack as 0
struct stack * createStack(unsigned size)
{
    struct stack *Stack = (struct stack*)malloc(sizeof(struct stack));
    Stack->capacity = size;
    Stack->top = -1;
    Stack->array = (int*)malloc(sizeof(int)*Stack->capacity);
    return Stack;
}

// stack is full when top is reached to capacity
int isFull(struct stack *Stack)
{
    return (Stack->top == Stack->capacity-1);
}

// stack is empty when top is equal to -1
int isEmpty(struct stack *Stack)
{
    return (Stack->top == -1);
}

// a function to push data on to stack
void push(struct stack *Stack, int data)
{
    if(isFull(Stack))
    {
        printf("\n Overflow!!");
        return;
    }
    Stack->array[++Stack->top] = data;
}

// a function to pop data form stack
int pop(struct stack *Stack)
{
    if(isEmpty(Stack))
    {
        printf("\n Underflow!!");
        return INT_MIN;
    }
    return (Stack->array[Stack->top--]);

}
// function to peep the top of stack
int peek(struct stack *Stack)
{
    if(isEmpty(Stack))
    {
        printf("\n Underflow!!");
        return;
    }
    return(Stack->array[Stack->top]);

}

// Driver function to check above functions
int main()
{
    struct stack *Stack = createStack(10);
    push(Stack,10);
    push(Stack,20);
    push(Stack,30);
    push(Stack,40);
    push(Stack,50);
    pop(Stack);
    pop(Stack);
    printf("\n%d is the third popped element", pop(Stack));
    printf("\n%d is the top of the stack now",peek(Stack));
    return 0;
}
