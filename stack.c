#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "quick_sort.c"
#include <string.h>
#include <limits.h>
#include <time.h>

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

struct Counter
{
	int value;
};

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

void increment(struct Counter* c)
{
	c->value++;
}

void swap(struct stack_node *head, struct Counter* c)
{
	struct stack_node *current;
	int temp;

	if(head == NULL && head->next == NULL)
		return ;
	current = head;
	temp = current-> data;
	current->data = current->next->data;
	current->next->data = temp;
	
	increment(c);
	
}

void rotate(struct stack_node **stack, struct Counter* c)
{
	struct stack_node *node = *stack;
	int data;

	if (node == NULL)
		return ;
	data = node->data;
	*stack = node->next;
	free(node);
	add_last(*stack,data);
	increment(c);
}

void reverse_rotate(struct stack_node **stack, struct Counter* c)
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
	increment(c);
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

void push_b(struct stack_node **a, struct stack_node **b, struct Counter* c)
{
	struct stack_node *current;
	int data;

	current = *a;
	if (*a == NULL)
		return ; 
	data = current->data;
	pop(a);    
	push(b, data);
	increment(c);
}

void push_a(struct stack_node **b, struct stack_node **a, struct Counter* c)
{
	struct  stack_node *current;
	int     data;

	current = *b;
	if (*b == NULL)
		return ;
	data = current->data;
	pop(b);
	push(a, data);
	increment(c);
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
	// printf("Second = %d\n",value);
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

// void sortThree(struct stack_node **stack)
// {
// 	if (getStackSize(stack) != 3 || sorted(stack) == true)
// 		return ;
// 	if (getLastValue(stack) == getHighest(stack))
// 	{
// 		if (getSecondValue(stack) == getLowest(stack))
// 		{
// 			swap(*stack);
// 			printf("ra\t");
// 			return ;
// 		}
// 	}
// 	if (getFirstValue(stack) == getHighest(stack))
// 	{
// 		if (getLastValue(stack) == getLowest(stack))
// 		{
// 			rotate(stack);
// 			swap(*stack);
// 			printf("ra\tsa\t");
// 			return ;
// 		}
// 	}
// 	if(getFirstValue(stack) == getLowest(stack))
// 	{
// 		if (getSecondValue(stack) == getHighest(stack))
// 		{
// 			reverse_rotate(stack);
// 			swap(*stack);
// 			printf("rra\tsa\t");
// 			return;
// 		}
// 	}
// 	if(getSecondValue(stack) == getHighest(stack))
// 	{
// 		if (getLastValue(stack) == getLowest(stack))
// 		{
// 			reverse_rotate(stack);
// 			printf("rra\t");
// 			return ;
// 		}
// 	}
// 	if (getFirstValue(stack) == getHighest(stack))
// 	{
// 		if (getSecondValue(stack) == getLowest(stack))
// 		{
// 			rotate(stack);
// 			printf("ra\t");
// 			return ;
// 		}
// 	}
	
// }

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

// void sortFive(struct stack_node **a, struct stack_node **b)
// {
// 	if (getStackSize(a) != 5 || *b != NULL || sorted(a) == true)
// 		return ;

// 	while (getStackSize(a) != 3)
// 	{
// 		while(getLowest(a) != getFirstValue(a))
// 		{
// 			if (getIndexPosition(a, getLowest(a)) > 3)
// 			{
// 				printf("rra\t");
// 				reverse_rotate(a);
// 			}
// 			else
// 			{
// 				printf("ra\t");
// 				rotate(a);
// 			}

// 		}
// 		if (getLowest(a) == getFirstValue(a))
// 		{
// 			printf("pb\t");
// 			push_b(a, b);
// 		}
// 	}
// 	sortThree(a);
// 	int test = 2;
// 	while (*b != NULL)
// 	{
// 		printf("pa\t");
// 		push_a(b, a);
// 	}
// 	printf("\n");				
// }

void reverseSortThree(struct stack_node **stack, struct Counter* c)
{
	if (getStackSize(stack) != 3 || reverseSorted(stack) == true)
		return ;
	if (getLastValue(stack) == getHighest(stack))
	{
		if (getSecondValue(stack) == getLowest(stack))
		{
			reverse_rotate(stack, c);
			printf("rrb\t");
			return ;
		}
	}
	if (getFirstValue(stack) == getLowest(stack))
	{
		if (getLastValue(stack) == getHighest(stack))
		{
			rotate(stack, c);
			swap(*stack, c);
			printf("rb\tsb\t");
			return ;
		}
	}
	if(getFirstValue(stack) == getLowest(stack))
	{
		if (getSecondValue(stack) == getHighest(stack))
		{
			
			rotate(stack, c);
			printf("rb\t");
			return;
		}
	}
	if(getSecondValue(stack) == getHighest(stack))
	{
		if (getLastValue(stack) == getLowest(stack))
		{
			swap(*stack, c);
			printf("sb\t");
			return ;
		}
	}
	if (getFirstValue(stack) == getHighest(stack))
	{
		if (getSecondValue(stack) == getLowest(stack))
		{
			reverse_rotate(stack, c);
			swap(*stack, c);
			printf("rrb\t");
			return ;
		}
	}
	
}


void reverseSortFive(struct stack_node **a, struct stack_node **b, struct Counter* c)
{
	int		counter;

	counter = 2;
	if (reverseSorted(b) == true)
		return ;

	while (getStackSize(b) > 3)
	{
		while(getHighest(b) != getFirstValue(b))
		{
			if (getIndexPosition(b, getHighest(b)) > 3)
			{
				printf("rrb\t");
				reverse_rotate(b, c);
			}
			else
			{
				printf("rb\t");
				rotate(b, c);
			}

		}
		if (getHighest(b) == getFirstValue(b))
		{
			printf("pa\t");
			push_a(b, a, c);
		}
	}
	reverseSortThree(b, c);
	
	while (counter-- != 0)
	{
		printf("pb\t");
		push_b(a, b, c);
	}
	printf("\n");				
}

int *createArray(struct stack_node **a)
{
	struct stack_node *current;
	static int *arr;
	int j;

	current = *a;
	if (current == NULL)
		return NULL;
	
	j = 0;
	arr = malloc(getStackSize(a) * sizeof(int));
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

int *slice(int *arr, int start, int end)
{
	int i;
	static int *output;

	i = start;
	output = malloc((end - start) * sizeof(int));

	while (i < end)
	{
		output[i - start] = arr[i];
		i++;
	}
	return output; //REMEMBER TO FREE THIS*/
}

void sortAscending(int*	arr, int size)
{
	int j;
	int	k;
	int temp;

	j = 0;
	k = 0;
	for (int i = 0; i < size - 1; i ++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
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



int *getNearestIndex(struct stack_node **a, int arr[], int begin, int end)
{
	int value;
	int j;
	int span;
	int *row;
	static int *values;
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
	values = malloc(counter * sizeof(int));
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
	
	k = 0;
	sortAscending(row, j);
	int q = 0;
	while(q < j)
	{
		printf("%d ", row[q]);
		q++;
	}
	printf("\n");
	while (k < j)
	{
		values[k] = *getIndexValue(a, row[k]);
		k++;
	}
	

	

	free(row);
	return values;
}



// void sortTen(struct stack_node **a, struct stack_node **b)
// {
// 	int *arr;
// 	int start;
// 	int end;
// 	if (*a == NULL || *b != NULL)
// 		return ;

// 	arr = createArray(a);
	
// 	start = 0;
// 	end = getStackSize(a);

// 	quickSort(arr, start, (end - 1));
// 	int j = 0;
// 	while(j < end)
// 	{
// 		printf("%d ", arr[j]);
// 		j++;
// 	}

	
// 	int n = getStackSize(a) - 1;
// 	int k = n - 4;
// 	int *row;
// 	int span;
// 	printf("\n");
// 	int g = 2;
// 	while (k >= 0)
// 	{
		
// 		row = getNearestIndex(a, arr, k, n);
// 		span = 0;
		
// 		while (span <= n - k)
// 		{
// 			while (getFirstValue(a) != row[span])
// 				{
// 					if (getIndexPosition(a, row[span]) - 1 < getStackSize(a) - getIndexPosition(a, row[span]))
// 						rotate(a);
// 					else
// 					{
// 						reverse_rotate(a);
// 					}
					
// 				}
// 				push_b(a, b);
// 				span++;
			
// 		}
// 		reverseSortFive(a, b);
// 		span = 0;
// 		while (span <= n - k)
// 		{
// 			push_a(b, a);
// 			span++;
// 		}
// 		k = k - 5;
// 		n = n - 5;
// 		g--;
// }



// 	free(row);
// 	free(arr);




// 	// getNearestIndex(a, arr, 8, 9);
// 	printf("\n");
// 	// printf("XX value = %d\n", getNearestIndex(a, arr, 5, 9));
// }

void sort100(struct stack_node **a, struct stack_node **b, struct Counter* c)
{
	int *arr;
	int start;
	int end;
	if (*a == NULL || *b != NULL)
		return ;

	arr = createArray(a);
	
	start = 0;
	end = getStackSize(a);

	quickSort(arr, start, (end - 1));
	int j = 0;
	while(j < end)
	{
		printf("%d ", arr[j]);
		j++;
	}

	int n = getStackSize(a) - 1;
	int k = n - 4;
	int *row;
	int span;
	printf("\n");
	int g = 3;
	
	while (k >= 0)
	{
		
		row = getNearestIndex(a, arr, k, n);
		span = 0;
		
		while (span <= n - k)
		{
			while (getFirstValue(a) != row[span])
				{
					if (getIndexPosition(a, row[span]) - 1 < getStackSize(a) - getIndexPosition(a, row[span]))
						rotate(a, c);
					else
					{
						reverse_rotate(a, c);
					}
					
				}
				push_b(a, b, c);
				span++;
		}
		reverseSortFive(a, b, c);
		span = 0;
		while (span <= n - k)
		{
			push_a(b, a, c);
			span++;
		}
		k = k - 5;
		n = n - 5;
		g--;
}
	printf("\n");

	if (sorted(a) == true)
		printf("STACK SORTED CONGRATULATIONS\n");
	else
		printf("TRY AGAIN\n");


	free(row);
	free(arr);

	printf("\n");
}

void arrange_100(struct stack_node **a, struct stack_node **b, int arr[], struct Counter* c, int n)
{
	// if (*b != NULL)
	// 	return;
	int counter;
	// counter = 80;
	// printf("\n");
	// printf("Begin arrange :  ");
	// while (counter <= 99)
	// {
	// 	printf(" %d",arr[counter]);
	// 	counter++;
	// }
	printf("\n");


	counter = n;
	while (counter >= n - 24)
	{
	while (getFirstValue(b) != arr[counter])
	{
		if (getIndexPosition(b, arr[counter]) <= 12)
			rotate(b, c);
		else 
			reverse_rotate(b, c);
	}
	push_a(b, a, c);
	counter--;
	}
}

void new_strat_100(struct stack_node **a, struct stack_node **b, struct Counter* c)
{
	int *arr;
	int start;
	int end;
	if (*a == NULL || *b != NULL)
		return ;

	arr = createArray(a);
	
	start = 0;
	end = getStackSize(a);

	quickSort(arr, start, (end - 1));
	int j = 0;
	while(j < end)
	{
		printf("%d ", arr[j]);
		j++;
	}

	int n = getStackSize(a) - 1;
	int k = n - 24;
	int *row;
	int span;
	printf("\n");
	int g = 3;
	
	while (k >= 0)
	{
		
		row = getNearestIndex(a, arr, k, n);
		span = 0;
		
		while (span <= n - k)
		{
			while (getFirstValue(a) != row[span])
				{
					if (getIndexPosition(a, row[span]) - 1 < getStackSize(a) - getIndexPosition(a, row[span]))
						rotate(a, c);
					else
					{
						reverse_rotate(a, c);
					}
					
				}
				push_b(a, b, c);
				span++;
		}
		// reverseSortFive(a, b, c);
		// span = 0;
		// while (span <= n - k)
		// {
		// 	push_a(b, a, c);
		// 	span++;
		// }
		arrange_100(a, b, arr, c, n);
		k = k - 25;
		n = n - 25;
		g--;
		
	}
	printf("\n");
	// arrange_100(a, b, arr, c);
	// printf("\n");

	if (sorted(a) == true)
		printf("STACK SORTED CONGRATULATIONS\n");
	else
		printf("TRY AGAIN\n");


	free(row);
	free(arr);

	printf("\n");
	
}

void arrange_500(struct stack_node **a, struct stack_node **b, int arr[], struct Counter* c, int n)
{
	int counter;
	printf("\n");


	counter = n;
	while (counter >= n - 49)
	{
	while (getFirstValue(b) != arr[counter])
	{
		if (getIndexPosition(b, arr[counter]) <= 25)
			rotate(b, c);
		else 
			reverse_rotate(b, c);
	}
	push_a(b, a, c);
	counter--;
	}
}

void new_strat_500(struct stack_node **a, struct stack_node **b, struct Counter* c)
{
	int *arr;
	int start;
	int end;
	if (*a == NULL || *b != NULL)
		return ;

	arr = createArray(a);
	
	start = 0;
	end = getStackSize(a);

	quickSort(arr, start, (end - 1));
	int j = 0;
	while(j < end)
	{
		printf("%d ", arr[j]);
		j++;
	}

	int n = getStackSize(a) - 1;
	int k = n - 49;
	int *row;
	int span;
	printf("\n");
	int g = 3;
	
	while (k >= 0)
	{
		
		row = getNearestIndex(a, arr, k, n);
		span = 0;
		
		while (span <= n - k)
		{
			while (getFirstValue(a) != row[span])
				{
					if (getIndexPosition(a, row[span]) - 1 < getStackSize(a) - getIndexPosition(a, row[span]))
						rotate(a, c);
					else
					{
						reverse_rotate(a, c);
					}
					
				}
				push_b(a, b, c);
				if (getStackSize(b) > 1)
				{
					if (getFirstValue(b) < getSecondValue(b))
						swap(*b, c);
				}
				span++;
		}
		arrange_500(a, b, arr, c, n);
		k = k - 50;
		n = n - 50;
		g--;
		
	}
	printf("\n");

	if (sorted(a) == true)
		printf("STACK SORTED CONGRATULATIONS\n");
	else
		printf("TRY AGAIN\n");


	free(row);
	free(arr);

	printf("\n");
	
}

int* randomNumberGenarator(int size)
{
	int* values;
	int value;

	// srand(time(NULL));
	srand(time(NULL));
	values = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		value = rand() % 4001 - 2000;
		values[i] = value;
	}
	return values;
}



int main()
{
	struct Counter c;
	c.value = 0;

	struct stack_node *a = NULL;
	struct stack_node *b = NULL;
	int* randomValues;
	int size = 500;
	int j;

	// push(&a, 1);
	// push(&a, 32);
	// push(&a, -3);
	// push(&a, -500);
	// push(&a, 8);
	// push(&a, 9);
	// push(&a, 20000);
	// push(&a, 21);
	// push(&a, 30);
	// push(&a, 0);
	// push(&a, 100);
	// push(&a, -25);
	// push(&a, 2210);
	// push(&a, 31);
	// push(&a, 90);
	// push(&a, 111);
	// push(&a, -215);
	// push(&a, 210);
	// push(&a, 331);
	// push(&a, 97);
	// push(&a, 711);
	// push(&a, -2015);
	// push(&a, 55);
	// push(&a, 621);
	// push(&a, 565);
	
	randomValues = randomNumberGenarator(size);
	j = 0;
	while(j < size)
	{
		push(&a, randomValues[j]);
		j++;
	}

	double_print(a, b);
	printf("________________________\n");
	new_strat_500(&a, &b, &c);
	double_print(a, b);
	free(randomValues);
	printf("\n");
	printf("Operation count = %d\n", c.value);

}