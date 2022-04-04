/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:27:09 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/03 18:09:08 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	if (get_stack_size(*b) == 0)
		return ;
	push_node(a, (*b)->data);
	pop_node(b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	if (get_stack_size(*a) == 0)
		return ;
	push_node(b, (*a)->data);
	pop_node(a);
	write(1, "pb\n", 3);
}