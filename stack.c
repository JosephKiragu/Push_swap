#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct stack_node
{
    int data;
    struct stack_node *next;
};

void push(struct stack_node **stack, int data)
{
    struct stack_node *node = malloc(sizeof(struct stack_node));
    node->data = data;
    node->next = *stack;
    *stack = node;
}

void pop(struct stack_node **stack)
{
    struct stack_node *node = *stack;
    *stack = node->next;
    free(node);
}

void print_stack(struct stack_node *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->data);
        stack = stack->next;
    }
}

int main()
{
    struct stack_node *stack = NULL;

    push(&stack, 5);
    push(&stack, 11);
    push(&stack, 13);

    print_stack(stack);
}
