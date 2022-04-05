/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:15:32 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/02 18:35:26 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_i_count(int *i, int *count)
{
	*i = 0;
	*count = 0;
}

int	return_pivot(int *arr, int i)
{
	int	pivot;

	if (i == -1)
		pivot = 0;
	else
		pivot = arr[i];
	free(arr);
	return (pivot);
}

int	get_pivot(t_stack *stk, int size)
{
	int	*arr;
	int	i;
	int	j;
	int	count;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr || size == 0)
		error_msg("Error\n");
	i = 0;
	while (i < size)
	{
		arr[i++] = stk->data;
		stk = stk->next;
	}
	i = -1;
	while (++i < size)
	{
		init_i_count(&j, &count);
		while (j < size)
			if (arr[i] < arr[j++])
				count++;
		if (count == (size / 2))
			return (return_pivot(arr, i));
	}
	return (return_pivot(arr, -1));
}
