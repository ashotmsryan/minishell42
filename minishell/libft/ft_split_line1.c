/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:37:40 by hvardany          #+#    #+#             */
/*   Updated: 2022/11/12 19:40:03 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

int	go_when_no_ecuals_c(char *s, int *i, char c)
{
	if (!s)
		return (0);
	while (s[*i] && s[*i] != c)
		i++;
	return (1);
}

int	malloc_line(char *s, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen0(s))
	{
		if (s[i] && s[i] == 34)
		{
			i++;
			while (s[i] && s[i] != 34)
				i++;
		}
		if (s[i] && s[i] == 39)
		{
			i++;
			while (s[i] && s[i] != 39)
				i++;
		}
		if (s[i] && s[i] == c)
		{
			return (i);
		}
		if (s[i])
			i++;
	}
	return (i);
}

static char	*sets1(char *s, size_t *n, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*sm;

	j = 0;
	i = 0;
	k = *n;
	i = malloc_line(s, c);
	sm = malloc((i + 1) * sizeof(char));
	if (!sm)
		return (0);
	sm = norm_sets(s, c, sm);
	*n = i + k;
	return (sm);
}

char	**split_norm_1(char **sm, char c, size_t i, char *s)
{
	size_t	j;

	j = 0;
	while (s && s[i])
	{
		sm[j] = sets1(&s[i], &i, c);
		if (!sm[j++])
		{
			clearfree(sm, --j);
			return (NULL);
		}
		if (s[i])
			i++;
	}
	sm[j] = 0;
	return (sm);
}

char	**ft_split_line1(char *s, char c)
{
	char	**sm;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	sm = malloc(sizeof(char *) * (l_nlen(s, c) + 1));
	if (!sm)
		return (NULL);
	i = 0;
	while (s && s[i] && s[i] == 32)
		i++;
	split_norm_1(sm, c, i, s);
	return (sm);
}
