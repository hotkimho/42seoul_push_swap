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

/*
4 3 2 1
3 4 2 1


*/
int	b_four_optimize_sort(t_stack **a, t_stack **b)
{	
	
	if ((*b)->data == get_max_data(*b, 4))
	{
		pa(a, b);
		b_check_three(a, b);
		pb(b, a);
		return (0);
	}
	else if ((*b)->next->data == get_max_data(*b, 4))
	{
		sb(b);
		pa(a, b);
		b_check_three(a, b);
		pb(b, a);
		return (0);
	}
	else 
		return (1);
	return (0);
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