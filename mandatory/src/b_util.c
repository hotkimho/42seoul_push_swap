/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_util.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:57 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/02 21:16:58 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	b_check_two(t_stack **b)
{
	if (check_descending(*b, 2))
		return;
	sb(b);
}


void	b_check_three(t_stack **a, t_stack **b)
{
	int	max;

	if (check_descending(*b, 3))
		return ;
	max = get_max_data(*b, 3);
	
	if ((*b)->data == max)
	{
		if (check_descending(*b, 3))
			return;
		rb(b);
		sb(b);
		rrb(b);
	}
	if ((*b)->next->data == max)
	{
		sb(b);
		if (check_descending(*b, 3))
			return;
		pa(a, b);
		sb(b);
		pb(b, a);
	}
	else
	{
		if ((*b)->data < (*b)->next->data)
			sb(b);
		rb(b);
		rb(b);
		pa(a, b);
		rrb(b);
		rrb(b);
		pb(b, a);
	}
	(*a)->data = (*a)->data;
	return ;
}