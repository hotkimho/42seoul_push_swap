/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:20:12 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/30 20:26:45 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
		return;
	tmp = (*a)->prev;
	tmp->prev->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return;
	tmp = (*b)->prev;
	tmp->prev->next = NULL;
	tmp->next = *b;
	*b = tmp;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}