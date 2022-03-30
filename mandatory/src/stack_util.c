/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:19:59 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/30 20:16:24 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_node(t_stack **stk, int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (*stk == NULL)
	{	
		*stk = node;
		(*stk)->prev = node;
		return;
	}
	node->next = *stk;
	node->prev = (*stk)->prev;
	(*stk)->prev = node;
	*stk = node;
}

int		pop_node(t_stack **stk)
{
	t_stack	*delNode;
	int	data;

	if (get_stack_size(*stk) == 1)
	{
		data = (*stk)->data;
		free(*stk);
		*stk = NULL;
		return (data);
	}
	delNode = *stk;
	(*stk)->next->prev = (*stk)->prev;
	*stk = (*stk)->next;
	data = delNode->data;
	free(delNode);
	return (data);
}

int		get_stack_size(t_stack *stk)
{
	int	idx;

	idx = 0;
	while (stk)
	{
		idx++;
		stk = stk->next;
	}
	return (idx);
}
void	stack_init(t_stack **a, t_stack **b)
{
	*a = NULL;
	*b = NULL;
}