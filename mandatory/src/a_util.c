/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_util.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:52 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/03 17:51:21 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_max_data(t_stack *stk, int size)
{
	int	data;
	int	i;

	if (!stk)
		error_msg("Error\n");
	data = stk->data;
	i = 0;
	while (i < size)
	{
		if (data < stk->data)
			data = stk->data;
		stk = stk->next;
		i++;
	}
	return (data);
}

void	a_check_two(t_stack **a)
{
	if (check_ascending(*a, 2))
		return;
	sa(a);
}

void	a_check_three(t_stack **a, t_stack **b)
{
	if (check_ascending(*a, 3))
		return ;
	if ((*a)->data == get_max_data(*a, 3))
	{

		if ((*a)->next->data > (*a)->next->next->data)
			sa(a);
		pb(b, a);
		sa(a);
		pa(a, b);
		if ((*a)->next->data > (*a)->next->next->data)
			sa(a);
	}
	if ((*a)->next->data == get_max_data(*a, 3))
	{
		pb(b, a);
		sa(a);
		pa(a, b);
		if (!check_ascending(*a, 3))
			sa(a);
	}
	else
		if (!check_ascending(*a, 3))
			sa(a);
	return ;
}