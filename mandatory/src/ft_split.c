/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:05:56 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/31 15:10:42 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**ft_error(char **s)
{
	int			i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

int		find_size(char *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

void	ft_strcpy(char *dest, char *src, int start, int end)
{
	int			i;

	i = 0;
	while (start < end)
		dest[i++] = src[start++];
	dest[i] = 0;
}

void	ft_init(int *start, int *s_size)
{
	*start = 0;
	*s_size = 0;
}

char	**ft_split(char *s, char c)
{
	char			**split_s;
	int				s_size;
	int			i;
	int				start;

	if (!s)
		return (NULL);
	s_size = find_size(s, c) + 1;
	split_s = (char **)malloc(sizeof(char *) * s_size);
	if (!split_s)
		return NULL;
	i = -1;
	ft_init(&start, &s_size);
	while (++i < ft_strlen(s))
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			split_s[s_size] = (char *)malloc(i - start + 1);
			if (!split_s)
				return (ft_error(split_s));
			ft_strcpy(split_s[s_size++], s, start, i);
		}
	split_s[s_size] = 0;
	return (split_s);
}