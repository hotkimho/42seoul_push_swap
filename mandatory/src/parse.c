/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:25:45 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/03 19:21:17 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_push_a(t_stack **a, t_stack **b)
{
	int	i;
	int stk_length;

	i = 0;
	stk_length = get_stack_size(*b);
	while (i < stk_length)
	{
		push_node(a, (*b)->data);
		pop_node(b);
		i++;
	}
}
void	parse_argv(int argc, char **argv, t_stack **b)
{
	int		idx;
	int		split_idx;
	char	**split_str;
	
	idx = 1;
	while (idx < argc)
	{
		validate(argv[idx]);
		split_str = ft_split(argv[idx], ' ');
		if (!split_str)
			error_msg("Error\n");
		split_idx = 0;
		while (split_str[split_idx])
		{
			push_node(b, ft_atoi(split_str[split_idx]));
			split_idx++;
		}
		//split_idx = 0;
		//while (split_str[split_idx])
		//{
		//	free(split_str[split_idx]);
		//	split_idx++;
		//}
		split_str = NULL;
		idx++;
	}
	
	if (idx == 5000)
		b = NULL;
	
}