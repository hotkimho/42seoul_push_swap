
#include "../include/push_swap.h"

int		b_more_than_four(t_stack **a, t_stack **b, int size)
{
	if (size == 4)
		b_four_optimize_sort(a, b);
	return (1);
}

int		b_check_sorting(t_stack **a , t_stack **b, int size)
{
	if (check_descending(*b, size))
	{
		while (size--)
			pa(a, b);
		return (1);
	}
	if (size == 1)
		pa(a, b);
	else if (size == 2)
	{
		b_check_two(b);
		all_push_B_to_A(a, b, size);
	}
	else if (size == 3)
	{
		if (get_stack_size(*b) == 3)
			b_three_optimize_sort(b);
		else
			b_check_three(a, b);
		all_push_B_to_A(a, b, size);
	}
	else if (size == 4)
		return b_more_than_four(a, b, size);
	else
		return (0);
	return (1);
}

int		b_check_push(t_stack *stk, int pivot)
{
	while (stk)
	{
		if (stk->data > pivot)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int		B_to_A_loop(t_stack **a, t_stack **b, int *a_count, int pivot)
{
	if ((*b)->data >= pivot)
	{
		pa(a, b);
		*a_count += 1;
	}
	else
	{
		rb(b);
		return (1);
	}
	return (0);
}

void	B_to_A(t_stack **a, t_stack **b, int size)
{
	int	i;
	int a_count;
	int b_count;
	int pivot;

	pivot = init_sorting(*b, size, &a_count, &b_count);
	if (b_check_sorting(a, b, size))
		return ;
	i = -1;
	while (++i < size)
	{
		if (b_check_push(*b, pivot))
			break;
		b_count += B_to_A_loop(a, b, &a_count, pivot);
	}
	i = -1;
	while (++i < b_count)
		rrb(b);
	A_to_B(a, b, a_count);
	B_to_A(a, b, size - a_count);
}
