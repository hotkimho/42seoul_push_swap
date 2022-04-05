/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:20:13 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 19:32:37 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
typedef struct		s_stack
{
	int		data;
	struct 	s_stack *next;
	struct	s_stack *prev;
}					t_stack;

//error
void	error_msg(char *message);
int		ft_strlen(char *str);

//stack_util
void	push_node(t_stack **stk, int data);
int		pop_node(t_stack **stk);
int		get_stack_size(t_stack *stk);
void	init_stack(t_stack **a, t_stack **b);
void	free_stk(t_stack **stk);

//operation_swap
void	sa(t_stack **a);
void	sb(t_stack **b);

//oeration_push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//operation_rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//operation_reverse_rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//parse
void	init_push_a(t_stack **a, t_stack **b);
void	parse_argv(int argc, char **argv, t_stack **b);

//parse_util
int		is_space(char c);
int		is_digit(char ch);
int		ft_atoi(const char *str);
void	validate(char *str);

//ft_split
char	**ft_error(char **s);
int		find_size(char *s, char c);
void	ft_strcpy(char *dest, char *src, int start, int end);
char	**ft_split(char *s, char c);
void	ft_init(int *start, int *s_size);

//pivot
int		get_pivot(t_stack *stk, int size);

//check
int		check_ascending(t_stack *stk, int size);
int		check_descending(t_stack *stk, int size);
void	check_duplicate(t_stack *stk, int size);

//a_util
void	a_check_two(t_stack **a);
void	a_check_three(t_stack **a, t_stack **b);
int		get_max_data(t_stack *stk, int size);
int		get_min_data(t_stack *stk, int size);
int		init_sorting(t_stack *stk, int size, int *a_count, int *b_count);

//b_util
void	b_check_two(t_stack **b);
void	b_check_three(t_stack **a, t_stack **b);
void	all_push_B_to_A(t_stack **a, t_stack **b, int size);

//a_sort
void	A_to_B(t_stack **a, t_stack **b, int size);
int		a_check_sorting(t_stack **a, t_stack **b, int size);
int		a_check_push(t_stack *stk, int pivot);
int		A_to_B_loop(t_stack **a, t_stack **b, int *b_count, int pivot);
int		a_more_than_four(t_stack **a, t_stack **b, int size);

//b_sort
void	B_to_A(t_stack **a, t_stack **b, int size);
int		b_check_sorting(t_stack **a , t_stack **b, int size);
int		b_check_push(t_stack *stk, int pivot);
int		b_more_than_four(t_stack **a, t_stack **b, int size);

//a_optimization
void	a_three_optimize_sort(t_stack **a);
void	a_exec_three_sort(t_stack **a, t_stack **b);
void	a_exec_four_sort(t_stack **a, t_stack **b);
int		a_four_sort(t_stack **a, t_stack **b);
int		a_four_optimize_sort(t_stack **a, t_stack **b);

//a_optimization_sub
int		a_five_sort(t_stack **a, t_stack **b);
int		a_five_optimize_sort(t_stack **a, t_stack **b);
void	five_last_case(t_stack **a, t_stack **b);

//b_optimization
void	b_three_optimize_sort(t_stack **b);
void	b_four_optimize_sort(t_stack **a, t_stack **b);
void	five_last_case(t_stack **a, t_stack **b);

//operation_util
void	exec_num_ra(t_stack **a, int num);
void	exec_num_sa_rra(t_stack **a, int num);
void	exec_num_rb(t_stack **b, int num);
void	exec_num_sb_rrb(t_stack **b, int num);
//test
void	print(t_stack *a, t_stack *b);
#endif