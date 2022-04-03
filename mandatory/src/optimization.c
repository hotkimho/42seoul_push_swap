/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:20:24 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/03 20:24:23 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


/*
//1 3 2
//3 2 1
//2 3 1 
*/
void	a_three_optimize_sort(t_stack **a)
{
	if (check_ascending(*a, 3))
		return ;
	if ((*a)->data == get_max_data(*a, 3))
	{
		ra(a);
		if (!check_ascending(*a, 3))
			sa(a);
	}
	else if ((*a)->next->data == get_max_data(*a, 3))
	{
		if ((*a)->data < (*a)->next->next->data)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
	else
		if (!check_ascending(*a, 3))
			sa(a);
	return ;
}



void	b_three_optimize_sort(t_stack **b)
{
	if (check_descending(*b, 3))
		return ;
	if ((*b)->data == get_max_data(*b, 3))
	{
		if (check_descending(*b, 3))
			return;
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