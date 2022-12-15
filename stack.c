#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "quick_sort.c"
#include <string.h>
#include <limits.h>

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
	if (*top == NULL)
		return ;
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

	if (node == NULL)
		return ;
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
	if (current == NULL)
		return ;
	while(current->next->next != NULL)
		current = current->next;
	data = current->next->data;
	free(current->next);
	current->next = NULL;
	// free(current);
	// printf("Last value is = %d\n", data);

	push(stack, data);
}

void double_print(struct stack_node *a, struct stack_node *b)
{
   while(a != NULL && b != NULL)
   {
	   printf("%d\t%d\n", a->data, b->data);
	   a = a->next;
	   b = b->next;
   }
   if (a != NULL)
	{
		while(a != NULL)
			{
				printf("%d\t\n", a->data);
				a = a-> next;
			}
	}
	else if (b != NULL)
	{
		while (b != NULL)
		{
			printf("\t%d\n", b->data);
			b = b-> next;
		}
	}
	printf("_\t_\na\tb\n");
}

void push_b(struct stack_node **a, struct stack_node **b)
{
	struct stack_node *current;
	int data;

	current = *a;
	if (*a == NULL)
		return ; 
	data = current->data;
	pop(a);    
	push(b, data);
}

void push_a(struct stack_node **b, struct stack_node **a)
{
	struct  stack_node *current;
	int     data;

	current = *b;
	if (*b == NULL)
		return ;
	data = current->data;
	pop(b);
	push(a, data);
}

int getStackSize(struct stack_node **stack)
{
	struct  stack_node *current;
	int     counter;
	
	current = *stack;
	counter = 0;
	if (current == NULL)
		return 1;
	while(current != NULL)
	{
		current = current->next;
		counter++;
	}
	// printf("Size = %d\n", counter);
	return counter;
}

bool sorted(struct stack_node **stack)
{
	struct  stack_node *current;
	int     temp;

	current = *stack;
	if (current == NULL)
		return 1;
	temp = current->data;
	while (current!= NULL && (current->next) != NULL)
	{
		if ((current->data) > (current->next->data))
		{
			// printf("NOT IN ORDER\n");
			return false;
		}
		current = current->next;
	}
	// printf("SORTED\n");
	return true;
}

bool reverseSorted(struct stack_node **stack)
{
	struct  stack_node *current;
	int     temp;

	current = *stack;
	if (current == NULL)
		return 1;
	temp = current->data;
	while (current!= NULL && (current->next) != NULL)
	{
		if ((current->data) < (current->next->data))
		{
			// printf("NOT IN ORDER\n");
			return false;
		}
		current = current->next;
	}
	// printf("REVERSE SORTED\n");
	return true;
}

int getFirstValue(struct stack_node **stack)
{
	struct  stack_node *current;
	int     value;

	current = *stack;
	if(current == NULL)
		return 1;
	value = current->data;
	// printf("Value = %d\n", value);
	return value;

}

int getLastValue(struct stack_node **stack)
{
	struct  stack_node *current;
	int     value;

	current = *stack;
	if(current == NULL)
		return 1;
	while(current->next!= NULL)
		current = current->next;
	value = current->data;
	// printf("Value = %d\n", value);
	return value;
}

int getSecondValue(struct stack_node **stack)
{
	struct	stack_node *current;
	int		value;

	current = *stack;
	if(current == NULL)
		return 1;
	value = current->next->data;
	// printf("Value = %d\n",value);
	return value;
}

int getHighest(struct stack_node **stack)
{
	struct stack_node *current;
	int		highest;

	current = *stack;
	if (current == NULL)
		return 1;
	highest = current->data;
	while(current != NULL)
	{
		if (current->data > highest)
			highest = current->data;
		current = current->next;
	}
	// printf("Highest = %d\n", highest);
	return highest;
}

int getLowest(struct stack_node **stack)
{
	struct	stack_node *current;
	int		lowest;

	current = *stack;
	if(current == NULL)
		return 1;
	lowest = current->data;
	while(current != NULL)
	{
		if (current->data < lowest)
			lowest = current->data;
		current = current->next;
	}
	// printf("Lowest = %d\n", lowest);
	return lowest;
}

void sortThree(struct stack_node **stack)
{
	if (getStackSize(stack) != 3 || sorted(stack) == true)
		return ;
	if (getLastValue(stack) == getHighest(stack))
	{
		if (getSecondValue(stack) == getLowest(stack))
		{
			swap(*stack);
			printf("ra\t");
			return ;
		}
	}
	else if (getFirstValue(stack) == getHighest(stack))
	{
		if (getLastValue(stack) == getLowest(stack))
		{
			rotate(stack);
			swap(*stack);
			printf("ra\tsa\t");
			return ;
		}
	}
	else if(getFirstValue(stack) == getLowest(stack))
	{
		if (getSecondValue(stack) == getHighest(stack))
		{
			reverse_rotate(stack);
			swap(*stack);
			printf("rra\tsa\t");
			return;
		}
	}
	if(getSecondValue(stack) == getHighest(stack))
	{
		if (getLastValue(stack) == getLowest(stack))
		{
			reverse_rotate(stack);
			printf("rra\t");
			return ;
		}
	}
	if (getFirstValue(stack) == getHighest(stack))
	{
		if (getSecondValue(stack) == getLowest(stack))
		{
			rotate(stack);
			printf("ra\t");
			return ;
		}
	}
	
}

int getIndexPosition(struct stack_node **stack, int value)
{
	struct	stack_node *current;
	int		counter;

	current = *stack;
	counter = 1;
	if (current == NULL)
		return EXIT_FAILURE;
	while(current!= NULL)
	{
		if (current->data == value)
		{
			// printf("Index = %d\n", counter);
			return counter;
		}
		counter++;
		current = current->next;
	}
	return -1;

}

void sortFive(struct stack_node **a, struct stack_node **b)
{
	if (getStackSize(a) != 5 || *b != NULL || sorted(a) == true)
		return ;

	while (getStackSize(a) != 3)
	{
		while(getLowest(a) != getFirstValue(a))
		{
			if (getIndexPosition(a, getLowest(a)) > 3)
			{
				printf("rra\t");
				reverse_rotate(a);
			}
			else
			{
				printf("ra\t");
				rotate(a);
			}

		}
		if (getLowest(a) == getFirstValue(a))
		{
			printf("pb\t");
			push_b(a, b);
		}
	}
	sortThree(a);
	int test = 2;
	while (*b != NULL)
	{
		printf("pa\t");
		push_a(b, a);
	}
	printf("\n");				
}

void reverseSortThree(struct stack_node **stack)
{
	if (getStackSize(stack) != 3 || reverseSorted(stack) == true)
		return ;
	if (getLastValue(stack) == getHighest(stack))
	{
		if (getSecondValue(stack) == getLowest(stack))
		{
			reverse_rotate(stack);
			printf("rrb\t");
			return ;
		}
	}
	else if (getFirstValue(stack) == getLowest(stack))
	{
		if (getLastValue(stack) == getHighest(stack))
		{
			reverse_rotate(stack);
			swap(*stack);
			printf("rrb\tsb\t");
			return ;
		}
	}
	else if(getFirstValue(stack) == getLowest(stack))
	{
		if (getSecondValue(stack) == getHighest(stack))
		{
			rotate(stack);
			printf("rb\t");
			return;
		}
	}
	if(getSecondValue(stack) == getHighest(stack))
	{
		if (getLastValue(stack) == getLowest(stack))
		{
			swap(*stack);
			printf("sb\t");
			return ;
		}
	}
	if (getFirstValue(stack) == getHighest(stack))
	{
		if (getSecondValue(stack) == getLowest(stack))
		{
			reverse_rotate(stack);
			swap(*stack);
			printf("rrb\t");
			return ;
		}
	}
	
}


void reverseSortFive(struct stack_node **a, struct stack_node **b)
{
	int		counter;

	counter = 2;
	if (getStackSize(b) != 5 || reverseSorted(b) == true)
		return ;

	while (getStackSize(b) != 3)
	{
		while(getHighest(b) != getFirstValue(b))
		{
			if (getIndexPosition(b, getHighest(b)) > 3)
			{
				printf("rrb\t");
				reverse_rotate(b);
			}
			else
			{
				printf("rb\t");
				rotate(b);
			}

		}
		if (getHighest(b) == getFirstValue(b))
		{
			printf("pa\t");
			push_a(b, a);
		}
	}
	reverseSortThree(b);
	
	while (counter-- != 0)
	{
		printf("pb\t");
		push_b(a, b);
	}
	printf("\n");				
}

int *createArray(struct stack_node **a)
{
	struct stack_node *current;
	static int arr[10];
	int j;

	current = *a;
	if (current == NULL)
		return NULL;
	
	j = 0;
	while(current != NULL)
		{
			arr[j] = current->data;
			j++;
			current = current->next;
		}
	return arr;
}

int getMin(int *arr, int size)
{
	int min;
	int j;

	min = INT_MAX;
	j = 0;

	while(j < size)
	{
		if(arr[j] < min)
			min = arr[j];
		j++;
	}
	return min;
}

int getMax(int *arr, int size)
{
	int max;
	int j;

	max = INT_MIN;
	j = 0;
	while (j < size)
	{
		if (arr[j] > max)
			max = arr[j];
		j++;
	}
	return max;
}



int getNearest(struct stack_node **a, int arr[], int begin, int end)
{
	int value;
	int j;
	int span;
	int *row;
	int counter;

	int start;
	
	start = begin;
	counter = 0;
	while (start <= end)
	{
		if (getIndexPosition(a, arr[start]) != -1)
			counter++;
		start++;
	}
	j = counter;
	start = begin;
	// printf("Value of span = %d\n", counter);
	
	row = malloc(counter * sizeof(int));
	int k = 0;
	while(k < counter)
	{
		if (getIndexPosition(a, arr[start]) != -1)
		{
			row[k] = getIndexPosition(a, arr[start]);
			printf("(%d, %d),", getIndexPosition(a, arr[start]), row[k]);
		}
		start++;
		k++;
	}
	printf("\n");
	if (j > 0)
	{
		if (getMin(row, j) - 0 < getStackSize(a) - getMax(row, j))
			value = getMin(row, j);
		else
			value = getMax(row, j);
	}
	if (j == 0)
	{
		printf("size of row = %d\n", j);
		value = 1;
	}
		// value = row[0];
	// value = getMin(row, j);

	printf("size of row = %d\n", j);
	printf("Value of Nearest index = %d\n", value);
	free(row);
	return value;
}

int *getIndexValue(struct stack_node **a, int index)
{
	struct stack_node *current;
	int counter;
	static int *value;
	

	current = *a;
	counter = 1;
	if (index > getStackSize(a))
		return NULL;
	while (current != NULL)
	{
		if (counter == index)
			value = &current->data;
		current = current->next;
		counter++;
	}
	return value;
}

void sortTen(struct stack_node **a, struct stack_node **b)
{
	int *arr;
	if (*a == NULL || *b != NULL)
		return ;

	arr = createArray(a);
	
	
	quickSort(arr, 0, 9);
	int j = 0;
	while(j < 10)
	{
		printf("%d ", arr[j]);
		j++;
	}

	int k = 5;
	int n = 9;
	int value;
	while(k <= n)
	{
		value = getNearest(a, arr, k, n);
		// if(getFirstValue(a) != *getIndexValue(a, value))
		// {
		// 	printf("Nearest = %d\n", value);
		// 	printf("Value %d != index value %d\n", getFirstValue(a), *getIndexValue(a, value));
		// 	return;
		// }
		if (getFirstValue(a) != *getIndexValue(a, value))
		{
			while(getFirstValue(a) != *getIndexValue(a, value))
			{
				if (value < (getStackSize(a) / 2 + 1))
				{
					// printf("Here");
					rotate(a);
				}
				else
					reverse_rotate(a);
			}
		}
		push_b(a, b);
		// return ;
		k++;
	}



	// getNearest(a, arr, 8, 9);
	printf("\n");
	// printf("XX value = %d\n", getNearest(a, arr, 5, 9));
}



int main()
{
	struct stack_node *a = NULL;
	struct stack_node *b = NULL;

	push(&a, 1);
	push(&a, 32);
	push(&a, 3);
	push(&a, 5);
	push(&a, 8);
	push(&a, 9);
	push(&a, 20);
	push(&a, 21);
	push(&a, 30);
	push(&a, 0);
	
	// printf("Printing stack\n");
	// double_print(a, b);
	// printf("________________________\n");
	// printf("Exec sa\n");
	// swap(a);
	// double_print(a, b);
	// printf("________________________\n");
	// printf("Exec ra\n");
	// rotate(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// printf("Exec rra \n");
	// reverse_rotate(&a);
	// double_print(a, b);
	// double_print(a, b);
	// printf("________________________\n");
	// printf("Exec pa \n");
	// push_b(&a, &b);
	// double_print(a, b);
	// printf("________________________\n");
	// printf("Exec pb \n");
	// push_a(&b, &a);
	// double_print(a, b);
	// printf("________________________\n");
	// sorted(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// getFirstValue(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// getLastValue(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// getStackSize(&b);
	// double_print(a, b);
	// printf("________________________\n");
	// getHighest(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// getLowest(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// getSecondValue(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// sortThree(&a);
	// double_print(a, b);
	// printf("________________________\n");
	// getIndexPosition(&a, 5);
	// double_print(a, b);
	// printf("________________________\n");
	// sortFive(&a, &b);
	// double_print(a, b);
	// printf("________________________\n");
	// reverseSortThree(&b);
	// double_print(a, b);
	// printf("________________________\n");
	// reverseSortFive(&a, &b);
	double_print(a, b);
	printf("________________________\n");
	sortTen(&a, &b);
	double_print(a, b);

}