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

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}						t_stack;

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
char	**ft_split(char *s, char c, int start, int s_size);
void	ft_init(int *start, int *s_size, int *i);

//pivot
int		get_pivot(t_stack *stk, int size);
void	init_i_count(int *i, int *count);
int		return_pivot(int *arr);

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
void	all_push_b_to_a(t_stack **a, t_stack **b, int size);
int		three_sort(t_stack **a, t_stack **b);

//a_sort
void	a_to_b(t_stack **a, t_stack **b, int size);
int		a_check_sorting(t_stack **a, t_stack **b, int size);
int		a_check_push(t_stack *stk, int pivot);
int		a_to_b_loop(t_stack **a, t_stack **b, int *b_count, int pivot);
int		a_more_than_four(t_stack **a, t_stack **b, int size);

//b_sort
void	b_to_a(t_stack **a, t_stack **b, int size);
int		b_to_a_loop(t_stack **a, t_stack **b, int *a_count, int pivot);
int		b_check_sorting(t_stack **a, t_stack **b, int size);
int		b_check_push(t_stack *stk, int pivot);
int		b_more_than_four(t_stack **a, t_stack **b, int size);

//a_optimization
void	a_three_optimize_sort(t_stack **a);
void	a_exec_three_sort(t_stack **a, t_stack **b);
void	a_exec_four_sort(t_stack **a, t_stack **b);
void	a_four_optimize_sort(t_stack **a, t_stack **b);
void	a_five_optimize_sort(t_stack **a, t_stack **b);

//b_optimization
void	b_three_optimize_sort(t_stack **b);
void	b_exec_four_sort(t_stack **a, t_stack **b);
void	b_exec_three_sort(t_stack **a, t_stack **b);
void	b_four_optimize_sort(t_stack **a, t_stack **b);
void	b_five_optimize_sort(t_stack **a, t_stack **b);

//operation_util
void	exec_num_ra(t_stack **a, int num);
void	exec_num_sa_rra(t_stack **a, int num);
void	exec_num_rb(t_stack **b, int num);
void	exec_num_sb_rrb(t_stack **b, int num);

#endif