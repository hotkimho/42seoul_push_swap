/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:20:05 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 20:42:00 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(0);
	init_stack(&a, &b);
	parse_argv(argc, argv, &b);
	init_push_a(&a, &b);
	check_duplicate(a, get_stack_size(a));
	a_to_b(&a, &b, get_stack_size(a));
	exit(0);
}
