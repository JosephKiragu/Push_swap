#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct stack_node
{
    int data;
    struct stack_node *next;
};

struct stack_node *create_node(int data)
{
    struct stack_node *new_node = malloc(sizeof(struct stack_node));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void add_last(struct stack_node *head, int data)
{
    struct stack_node *current;

    current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    struct stack_node *newNode = (struct stack_node*) malloc(sizeof(struct stack_node));
    newNode->next = NULL;
    newNode->data = data;
    current->next = newNode;
}

void add_first(struct stack_node *head, int data)
{
    struct stack_node *current;
    struct stack_node *newNode;

    // current = head;
    head = head->next;
    newNode = (struct stack_node*) malloc(sizeof(struct stack_node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    

    
}

void push(struct stack_node **top, int data)
{
    struct stack_node *node = malloc(sizeof(struct stack_node));
    node->data = data;
    node->next = *top;
    *top = node;
}

void pop(struct stack_node **top)
{
    struct stack_node *node = *top;
    *top = node->next;
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

void swap_a(struct stack_node *stack)
{
    int data;
    // struct stack_node *current;
    
    // current = stack;
    if (stack == NULL || stack->next == NULL)
        return ;
    data = stack->next->data;
    free(stack->next);
    stack->next = stack->next->next;
    printf("The first element =%d\n second = %d\n", stack->data, stack->next->data);
    push(&stack, data);
    // struct stack_node *first = malloc(sizeof(struct stack_node));
    // first->data = data;
    // first->next = current;
    // current = first;
    // print_stack(stack);
    //  stack = current;
}

void rotate_a(struct stack_node *stack)
{
    struct  stack_node *current;
    int     data;

    current = stack;
    // if (stack == NULL)
    //     return ;
    // data = current->data;
    // pop(&current);
    add_last(stack, 7);
    
    // current->next = malloc(sizeof(struct stack_node));
    // current->next->data = data;
    // current->next->next = NULL;
    // printf("last element = %d\n", current->next->data);
    
}



int main()
{
    struct stack_node *stack = NULL;

    push(&stack, 5);
    push(&stack, 11);
    push(&stack, 13);
    push(&stack, 15);
    // pop(&stack);
    printf("Printing stack\n");
    print_stack(stack);
    printf("Swapping first two elements of stack\n");
    swap_a(stack);
    print_stack(stack);
    printf("Rotating stack\n");
    // rotate_a(stack);
    
}
