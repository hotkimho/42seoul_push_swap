/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:35 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 21:10:26 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		init_sorting(t_stack *stk, int size, int *a_count, int *b_count)
{
	if (!stk)
		error_msg("Error\n");
	*a_count = 0;
	*b_count = 0;
	return get_pivot(stk, size);
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
	{
		pa(a, b);
		return (1);
	}
	if (size == 2)
	{
		b_check_two(b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	else if (size == 3 && get_stack_size(*b) == 3)
	{
		b_three_optimize_sort(b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	else if (size == 3)
	{
		b_check_three(a, b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	else if (size == 4)
	{
		if (b_four_optimize_sort(a, b) == 1)
			return (0);
		return (1);
	}
	else if (size > 3)
	{
		if (check_descending(*b, size))
		{
			while (size--)
				pa(a, b);
			return (1);
		}
	}
	return (0);
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
void	B_to_A(t_stack **a, t_stack **b, int size)
{
	int	i;
	int a_count;
	int b_count;
	int pivot;

	pivot = init_sorting(*b, size, &a_count, &b_count);
//	printf("B - pivot : %d, size : %d\n", pivot, size);
	if (b_check_sorting(a, b, size))
		return ;
	i = -1;
	while (++i < size)
	{
		if (b_check_push(*b, pivot))
			break;
		if ((*b)->data >= pivot)
		{
			pa(a, b);
			a_count++;
		}
		else
		{
			rb(b);
			b_count++;
		}
	}
	i = -1;
	while (++i < b_count)
		rrb(b);
//	print(*a, *b);
	A_to_B(a, b, a_count);
	B_to_A(a, b, size - a_count);
}

int		a_check_sorting(t_stack **a, t_stack **b, int size)
{
	if (check_ascending(*a, size))
		return (1);
	if (size == 1)
		return (1);
	if (size == 2)
	{
		a_check_two(a);
		return (1);
	}
	else if (size == 3 && get_stack_size(*a) == 3)
	{
		a_three_optimize_sort(a);
		return (1);
	}
	else if (size == 3)
	{
		a_check_three(a, b);
		return (1);
	}
	else if (size == 4 && get_stack_size(*a) == 4)
	{
		a_four_optimize_sort2(a, b);
		return (1);
	}
	else if (size == 4)
	{
		if (a_four_optimize_sort(a, b))
			return (0);
		return (1);
	}
	else if (size == 5 && get_stack_size(*a) == 5)
	{
		a_five_optimize_sort2(a, b);
		return (1);
	}
	else if (size == 5)
	{
		if (a_five_optimize_sort(a, b))
			return (0);
		return (1);
	}
	return (0);
}

int		a_check_push(t_stack *stk, int pivot)
{
	while (stk)
	{
		if (stk->data < pivot)
			return (0);
		stk = stk->next;
	}
	return (1);
}

void	A_to_B(t_stack **a, t_stack **b, int size)
{
	int	i;
	int a_count;
	int b_count;
	int pivot;

	pivot = init_sorting(*a, size, &a_count, &b_count);
	//pivot = get_pivot(*a, size);
//	printf("A - pivot : %d, size : %d\n", pivot, size);
	if (a_check_sorting(a, b, size))
		return ;
	i = 0;
	while (i < size)
	{
		if (a_check_push(*a, pivot))
			break;
		if ((*a)->data >= pivot)
		{
			ra(a);
			a_count++;
		}
		else
		{
			pb(b, a);
			b_count++;
		}
		i++;
	}
	//printf("A - aCount : %d, bCount : %d size : %d\n", a_count, b_count, get_stack_size(*a));
	i = -1;
	while (++i < a_count)
		rra(a);
	
	//print(*a, *b);

	A_to_B(a, b, size - b_count);
	B_to_A(a, b, b_count);
}
