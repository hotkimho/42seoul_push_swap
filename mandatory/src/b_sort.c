/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:20:05 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 20:42:00 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	b_more_than_four(t_stack **a, t_stack **b, int size)
{
	if (get_stack_size(*b) == 4)
	{
		b_four_optimize_sort(a, b);
		all_push_b_to_a(a, b, size);
		return (1);
	}
	else if (get_stack_size(*b) == 5)
	{
		b_five_optimize_sort(a, b);
		all_push_b_to_a(a, b, size);
		return (1);
	}
	return (0);
}

int	b_check_sorting(t_stack **a, t_stack **b, int size)
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
		all_push_b_to_a(a, b, size);
	}
	else if (size == 3)
		return (three_sort(a, b));
	else if (size == 4 || size == 5)
		return (b_more_than_four(a, b, size));
	else
		return (0);
	return (1);
}

int	b_check_push(t_stack *stk, int pivot)
{
	while (stk)
	{
		if (stk->data > pivot)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int	b_to_a_loop(t_stack **a, t_stack **b, int *a_count, int pivot)
{
	if ((*b)->data > pivot)
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

void	b_to_a(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	a_count;
	int	b_count;
	int	pivot;

	pivot = init_sorting(*b, size, &a_count, &b_count);
	if (b_check_sorting(a, b, size))
		return ;
	i = -1;
	while (++i < size)
	{
		if (b_check_push(*b, pivot))
			break ;
		b_count += b_to_a_loop(a, b, &a_count, pivot);
	}
	i = -1;
	while (++i < b_count)
		rrb(b);
	a_to_b(a, b, a_count);
	b_to_a(a, b, size - a_count);
}
