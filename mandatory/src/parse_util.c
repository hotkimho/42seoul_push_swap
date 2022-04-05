/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:42:08 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/31 16:18:47 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	is_digit(char ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	return (0);
}

int	check_int_max_value(long long value)
{
	if (value < -2147483648)
		error_msg("Error\n");
	else if (value > 2147483647)
		error_msg("Error\n");
	return (value);
}

int	ft_atoi(const char *str)
{
	long long	value;
	int			sign;

	sign = 1;
	value = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) == '+' || *(str + 1) == '-' || *(str + 1) == 0)
			error_msg("Error\n");
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10;
		value = value + *str - '0';
		str++;
	}
	return (check_int_max_value(value * sign));
}

void	validate(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_digit(str[i]))
			continue ;
		else if (is_space(str[i]))
			continue ;
		else if (str[i] == '+' || str[i] == '-')
			continue ;
		error_msg("Error\n");
	}
}
