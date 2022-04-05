/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:24:54 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/03 17:23:22 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	if (get_stack_size(*a) <= 1)
		return ;
	tmp = (*a)->next;
	(*a)->prev->next = *a;
	(*a)->next = NULL;
	tmp->prev = *a;
	*a = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	if (get_stack_size(*b) <= 1)
		return ;
	tmp = (*b)->next;
	(*b)->prev->next = *b;
	(*b)->next = NULL;
	tmp->prev = *b;
	*b = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
