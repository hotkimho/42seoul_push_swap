/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:24:54 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/30 19:28:37 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
		return;
	tmp = (*a)->next;
	(*a)->prev->next = *a;
	(*a)->next = NULL;
	tmp->prev = *a;
	*a = tmp;
	write(1, "ra\n", 4);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return;
	tmp = (*b)->next;
	(*b)->prev->next = *b;
	(*b)->next = NULL;
	tmp->prev = *b;
	*b = tmp;
	write(1, "rb\n", 4);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}