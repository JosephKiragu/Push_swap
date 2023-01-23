#include "stack.c"
#include "quick_sort.c"

/* push_all_save_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
void    push_all_save_three(struct stack_node **a, struct stack_node **b, struct Counter* c)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = getStackSize(a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
        if (getFirstValue(a) <= stack_size / 2)
		{
			push_b(a, b, c);
			pushed++;
		}
		else
			rotate(a, c);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push_b(a, b, c);
		pushed++;
	}
}

/* shift_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
void	shift_stack(struct stack_node **a, struct Counter* c)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = getStackSize(a);
	lowest_pos = getIndexPosition(a, getLowest(a));
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rotate(a, c);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate(a, c);
			lowest_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
void	sort(struct stack_node **a, struct stack_node **b, struct Counter* c)
{
	push_all_save_three(a, b, c);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}