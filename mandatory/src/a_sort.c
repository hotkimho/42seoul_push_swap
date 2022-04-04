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

int		a_more_than_four(t_stack **a, t_stack **b, int size)
{
	if (size == 4)
	{
		if (get_stack_size(*a) == 4)
			a_four_optimize_sort(a, b);
		else
			a_four_sort(a, b);
	}
	else if (size == 5)
	{
		if (get_stack_size(*a) == 5)
			a_five_optimize_sort(a, b);
		else
			a_five_sort(a, b);
	}
	return (1);
}
int		a_check_sorting(t_stack **a, t_stack **b, int size)
{
	if (check_ascending(*a, size))
		return (1);
	if (size == 1)
		return (1);
	else if (size == 2)
		a_check_two(a);
	else if (size == 3)
		if(get_stack_size(*a) == 3)
			a_three_optimize_sort(a);
		else
			a_check_three(a, b);
	else if (size == 4 || size == 5)
		return (a_more_than_four(a, b, size));
	else
		return (0);
	return (1);
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
int		A_to_B_loop(t_stack **a, t_stack **b, int *b_count, int pivot)
{
	if ((*a)->data >= pivot)
	{
		ra(a);
		return (1);
	}
	else
	{
		pb(b, a);
		*b_count += 1;
	}
	return (0);
}

void	A_to_B(t_stack **a, t_stack **b, int size)
{
	int	i;
	int a_count;
	int b_count;
	int pivot;

	pivot = init_sorting(*a, size, &a_count, &b_count);
	if (a_check_sorting(a, b, size))
		return ;
	i = -1;
	while (++i < size)
	{
		if (a_check_push(*a, pivot))
			break;
		a_count += A_to_B_loop(a, b, &b_count, pivot);
	}
	i = -1;
	while (++i < a_count)
		rra(a);
	A_to_B(a, b, size - b_count);
	B_to_A(a, b, b_count);
}
