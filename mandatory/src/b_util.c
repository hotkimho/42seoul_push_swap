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
		return ;
	sb(b);
}

void	all_push_b_to_a(t_stack **a, t_stack **b, int size)
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
		rb(b);
		exec_num_sb_rrb(b, 1);
	}
	else if ((*b)->next->data == get_max_data(*b, 3))
	{
		sb(b);
		if (check_descending(*b, 3))
			return ;
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
}

int	three_sort(t_stack **a, t_stack **b)
{
	if (get_stack_size(*b) == 3)
		b_three_optimize_sort(b);
	else
		b_check_three(a, b);
	all_push_b_to_a(a, b, 3);
	return (1);
}
