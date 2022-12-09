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

void swap(struct stack_node *head)
{
	struct stack_node *current;
	int temp;

	if(head == NULL && head->next == NULL)
		return ;
	current = head;
	temp = current-> data;
	current->data = current->next->data;
	current->next->data = temp;
	
}

void rotate(struct stack_node **stack)
{
	struct stack_node *node = *stack;
	int data;


	data = node->data;
	*stack = node->next;
	free(node);
	add_last(*stack,data);
}

void reverse_rotate(struct stack_node **stack)
{
	struct stack_node *current;
	struct stack_node *first;
	int data;

	current = *stack;
	while(current->next->next != NULL)
		current = current->next;
	data = current->next->data;
	free(current->next);
	current->next = NULL;
	// free(current);
	printf("Last value is = %d\n", data);

	push(stack, data);
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
    swap(stack);
    print_stack(stack);
    printf("Rotating stack\n");
    rotate(&stack);
	print_stack(stack);
	printf("Reverse Rotate \n");
    reverse_rotate(&stack);
	print_stack(stack);
    
}
