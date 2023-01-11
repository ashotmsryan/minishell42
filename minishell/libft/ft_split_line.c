/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:37:40 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/09 15:16:08 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*norm_sets(const char *s, char c, char *sm)
{
	size_t	j;

	j = 0;
	while (*s && *s != c)
	{
		if (*s && *s == 39)
		{
			sm[j++] = *s++;
			while (*s && *s != 39)
				sm[j++] = *s++;
		}
		if (*s && *s == 34)
		{
			sm[j++] = *s++;
			while (*s && *s != 34)
				sm[j++] = *s++;
		}
		if (s && *s)
			sm[j++] = *s++;
	}
	sm[j] = '\0';
	return (sm);
}

static char	*sets(char const *s, size_t *n, char c)
{
	size_t	i;
	size_t	k;
	char	*sm;

	i = len_till(s, c);
	k = *n;
	if (!s)
		return (NULL);
	sm = malloc((i + 1) * sizeof(char));
	if (!sm)
		return (0);
	sm = norm_sets(s, c, sm);
	*n = i + k - 1;
	return (sm);
}

void	l_nlen_norm(char const *s, size_t *j)
{
	if (s[*j] && s[*j] == 34)
		while (s[++(*j)] && s[*j] != 34)
			;
	if (s[*j] == 39)
		while (s[++(*j)] && s[*j] != 39)
			;
}

size_t	l_nlen(char const *s, char c)
{
	size_t	k;
	size_t	j;
	size_t	n;

	n = 0;
	k = 1;
	j = 0;
	while (s[j] != '\0')
	{
		l_nlen_norm(s, &j);
		if (s[j] && s[j] != c && k > 0)
		{
			n++;
			k = 0;
		}
		else if (s[j] && s[j] == c)
			k = 1;
		if (s[j] != '\0')
			j++;
	}
	return (n);
}

char	**ft_split_line(char const	*s, char c)
{
	char	**sm;
	size_t	i;
	size_t	j;

	if (!s && !*s && c)
		return (NULL);
	sm = malloc(sizeof(char *) * (l_nlen(s, c) + 1));
	if (!sm)
		return (NULL);
	j = 0;
	i = -1;
	while (s && s[++i] != '\0')
	{
		if (s && s[i] != '\0' && s[i] != c)
		{
			sm[j] = sets(&s[i], &i, c);
			if (!sm[j++])
			{
				clearfree(sm, --j);
				return (NULL);
			}
		}
	}
	sm[j] = 0;
	return (sm);
}
