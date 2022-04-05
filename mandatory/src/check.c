/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:17:02 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 20:00:09 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_duplicate(t_stack *stk, int size)
{
	int	i;
	int	j;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * size);
	if (!stk || size == 0 || !arr)
		error_msg("Error\n");
	i = -1;
	while (++i < size)
	{
		arr[i] = stk->data;
		stk = stk->next;
	}
	i = -1;
	while (++i < (size - 1))
	{
		j = i;
		while (++j < size)
			if (arr[i] == arr[j])
			{
				free(arr);
				error_msg("Error\n");
			}
	}
	free(arr);
}

int	check_ascending(t_stack *stk, int size)
{
	int	i;
	int	data;

	if (!stk)
		error_msg("Error\n");
	i = 0;
	data = stk->data;
	while (i < size)
	{
		if (data > stk->data && i != 0)
			return (0);
		data = stk->data;
		stk = stk->next;
		i++;
	}
	if (i == size)
		return (1);
	return (0);
}

int	check_descending(t_stack *stk, int size)
{
	int	i;
	int	data;

	if (!stk)
		error_msg("Error\n");
	i = 0;
	data = stk->data;
	while (i < size)
	{
		if (data < stk->data && i != 0)
			return (0);
		data = stk->data;
		stk = stk->next;
		i++;
	}
	if (i == size)
		return (1);
	return (0);
}
