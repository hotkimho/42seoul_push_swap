/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:19:59 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 16:40:30 by hkim2            ###   ########.fr       */
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
		return ;
	}
	node->next = *stk;
	node->prev = (*stk)->prev;
	(*stk)->prev = node;
	*stk = node;
}

int	pop_node(t_stack **stk)
{
	t_stack	*del_node;
	int		data;

	if (get_stack_size(*stk) == 1)
	{
		data = (*stk)->data;
		free(*stk);
		*stk = NULL;
		return (data);
	}
	del_node = *stk;
	(*stk)->next->prev = (*stk)->prev;
	*stk = (*stk)->next;
	data = del_node->data;
	free(del_node);
	return (data);
}

int	get_stack_size(t_stack *stk)
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

void	init_stack(t_stack **a, t_stack **b)
{
	*a = NULL;
	*b = NULL;
}

void	free_stk(t_stack **stk)
{
	t_stack	*tmp;
	int		i;
	int		size;

	if (*stk == NULL)
		return ;
	i = 0;
	size = get_stack_size(*stk);
	while (i < size)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = tmp;
	}
}
