/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:18:08 by hvardany          #+#    #+#             */
/*   Updated: 2022/11/11 14:16:12 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sm;
	size_t	n;
	size_t	l;
	size_t	i;

	n = ft_strlen0((char *)s1);
	l = ft_strlen0((char *)s2);
	sm = (char *)malloc(sizeof(char) * (n + l + 1));
	if (!sm)
		return (NULL);
	i = 0;
	while (s1 && *s1 != '\0')
	{
		sm[i] = *s1++;
		i++;
	}
	while (s2 && *s2 != '\0')
	{
		sm[i] = *s2++;
		i++;
	}
	sm[i] = '\0';
	return (sm);
}

char	*ft_strjoin1(char *s1, char const *s2)
{
	char	*sm;
	size_t	n;
	size_t	i;

	n = 0;
	n = ft_strlen0(s1) + 1;
	sm = malloc(sizeof(char) * (n + ft_strlen0((char *)s2) + 1));
	if (!sm)
		return (NULL);
	i = -1;
	while (s1 && *s1 != '\0')
		sm[++i] = *s1++;
	if (n > 0)
		sm[i++] = ' ';
	while (s2 && *s2 != '\0')
		sm[++i] = *s2++;
	if (s1 && *s1)
	{
		free(s1);
		s1 = 0;
	}
	sm[i + 1] = '\0';
	return (sm);
}

char	*ft_strjoin2(char *s1, char const *s2)
{
	char	*sm;
	size_t	l;
	size_t	i;

	l = 0;
	sm = 0;
	if (!s1 && !s2)
		return (NULL);
	l = ft_strlen0((char *)s2);
	if ((s1 && *s1) && (s2 && *s2))
		l++;
	sm = malloc(sizeof(char) * (ft_strlen0(s1) + l + 1));
	if (!sm)
		return (NULL);
	i = -1;
	while (s1 && *s1 != '\0')
		sm[++i] = *s1++;
	if (s1 && s2)
		sm[i++] = ' ';
	while (s2 && *s2 != '\0')
		sm[++i] = *s2++;
	sm[i + 1] = '\0';
	return (sm);
}
