/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:37:40 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 22:17:31 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

size_t	len_till(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) && s[i] != c)
	{
		if (s[i] && s[i] == 39)
			while (s && s[++i] && s[i] != 39)
				;
		if (s[i] == 34)
			while (s && s[++i] && s[i] != 34)
				;
		if (s[i])
			i++;
	}
	return (i);
}

static char	*sets(char const *s, size_t *n, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*sm;

	j = 0;
	i = 0;
	k = *n;
	while (i < ft_strlen(s) && s[i] != c)
		i++;
	sm = malloc((i + 1) * sizeof(char));
	if (!sm)
		return (0);
	while (*s != c && *s != '\0')
		sm[j++] = *s++;
	*n = i + k;
	sm[j] = '\0';
	return (sm);
}

static size_t	nlen(char const *s, char c)
{
	size_t	k;
	size_t	j;
	size_t	n;

	n = 0;
	k = 1;
	j = 0;
	while (s && s[j] != '\0')
	{
		if (s[j] != c && k > 0)
		{
			n++;
			k = 0;
		}
		else if (s[j] == c)
			k = 1;
		j++;
	}
	return (n);
}

void	clearfree(char **sm, size_t j)
{
	while (j >= 0)
		free(sm[j--]);
	free(sm);
}

char	**ft_split(char const *s, char c)
{
	char	**sm;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	sm = malloc(sizeof(char *) * (nlen(s, c) + 1));
	if (!sm)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] != c)
		{
			sm[j] = sets(&s[--i], &i, c);
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
