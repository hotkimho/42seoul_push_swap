/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:20:12 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/03 17:23:20 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	if (get_stack_size(*a) <= 1)
		return ;
	tmp = (*a)->prev;
	tmp->prev->next = NULL;
	tmp->next = *a;
	*a = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	if (get_stack_size(*b) <= 1)
		return ;
	tmp = (*b)->prev;
	tmp->prev->next = NULL;
	tmp->next = *b;
	*b = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
