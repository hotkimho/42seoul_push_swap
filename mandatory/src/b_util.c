/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_util.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:57 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/03 20:05:09 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	b_check_two(t_stack **b)
{
	if (check_descending(*b, 2))
		return;
	sb(b);
}

void	all_push_B_to_A(t_stack **a, t_stack **b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pa(a, b);
		i++;
	}
}

void	b_check_three(t_stack **a, t_stack **b)
{
	if (check_descending(*b, 3))
		return ;
	if ((*b)->data == get_max_data(*b, 3))
	{
		if (check_descending(*b, 3))
			return;
		rb(b);
		sb(b);
		rrb(b);
	}
	else if ((*b)->next->data == get_max_data(*b, 3))
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
		pa(a, b);
		sb(b);
		pb(b, a);
		sb(b);
	}
	return ;
}