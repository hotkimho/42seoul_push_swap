/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:15:32 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/31 20:35:00 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_pivot(t_stack *stk, int size)
{
	int	arr[size];
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{
		arr[i++] = stk->data;
		stk = stk->next;
	}
	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
			if (arr[i] < arr[j++])
				count++;
		if (count == (size / 2))
			return (arr[i]);
		i++;
	}
	return (arr[size / 2]);
}