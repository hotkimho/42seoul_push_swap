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
#include<stdio.h>

int count;

void print_stack(t_stack *stk)
{
	while(stk)
	{
		printf("%d\n", stk->data);
		stk = stk->next;
	}
	printf("\n");
}

void	print(t_stack *a, t_stack *b)
{
	int len;
	int i;

	if (get_stack_size(a) > get_stack_size(b))
		len = get_stack_size(a);
	else
		len = get_stack_size(b);
	for (i = 0; i < len; i++)
	{
		if (a)
		{
			printf("%d ", a->data);
			a = a->next;
		}
		else
			printf("  ");
		if (b)
		{
			printf("%d", b->data);
			b = b->next;
		}
		else
			printf("  ");
		printf("\n");
	}
	printf("- -\n");
	printf("a b\n");
}

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
	{
		exit(0);
	}
	//1 0 3 6 7 5 4 2
	init_stack(&a, &b);
	parse_argv(argc, argv, &b);
	init_push_a(&a, &b);
	check_duplicate(a, get_stack_size(a));
	A_to_B(&a, &b, get_stack_size(a));
	print(a, b);//2  2 3 5 1 4
	//free_stk(&a);
	//free_stk(&b);
	exit(0);
}