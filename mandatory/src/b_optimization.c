/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_optimization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:20:24 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 19:21:29 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	b_exec_three_sort(t_stack **a, t_stack **b)
{
	if (check_descending((*b)->next, 3))
		return ;
	pa(a, b);
	if (get_stack_size(*b) == 3)
		b_three_optimize_sort(b);
	else
		b_check_three(a, b);
	pb(b, a);
}

void	b_exec_four_sort(t_stack **a, t_stack **b)
{
	if (check_descending((*b)->next, 4))
		return ;
	pa(a, b);
	b_four_optimize_sort(a, b);
	pb(b, a);
}

void	b_three_optimize_sort(t_stack **b)
{
	if (check_descending(*b, 3))
		return ;
	if ((*b)->data == get_max_data(*b, 3))
	{
		if (check_descending(*b, 3))
			return ;
		rrb(b);
		sb(b);
	}
	else if ((*b)->next->data == get_max_data(*b, 3))
	{
		if ((*b)->data < (*b)->next->next->data)
			rb(b);
		else
			sb(b);
	}
	else
	{
		if ((*b)->data < (*b)->next->data)
			sb(b);
		rrb(b);
	}
	return ;
}

void	b_four_optimize_sort(t_stack **a, t_stack **b)
{
	if ((*b)->data == get_max_data(*b, 4))
		b_exec_three_sort(a, b);
	else if ((*b)->next->data == get_max_data(*b, 4))
	{
		sb(b);
		b_exec_three_sort(a, b);
	}
	else if ((*b)->next->next->data == get_max_data(*b, 4))
	{
		rb(b);
		sb(b);
		b_exec_three_sort(a, b);
	}
	else
	{
		rrb(b);
		b_exec_three_sort(a, b);
	}
}

void	b_five_optimize_sort(t_stack **a, t_stack **b)
{
	if ((*b)->data == get_max_data(*b, 5))
		b_exec_four_sort(a, b);
	else if ((*b)->next->data == get_max_data(*b, 5))
	{
		sb(b);
		b_exec_four_sort(a, b);
	}
	else if ((*b)->next->next->data == get_max_data(*b, 5))
	{
		rb(b);
		sb(b);
		b_exec_four_sort(a, b);
	}
	else if ((*b)->next->next->next->data == get_max_data(*b, 5))
	{
		rrb(b);
		rrb(b);
		b_exec_four_sort(a, b);
	}
	else
	{
		rrb(b);
		b_exec_four_sort(a, b);
	}
}
