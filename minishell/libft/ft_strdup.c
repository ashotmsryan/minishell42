/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:20:25 by hvardany          #+#    #+#             */
/*   Updated: 2022/11/29 22:13:55 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *) s1;
	while (*s++ != '\0')
		i++;
	d = malloc(sizeof(char) * (i + 1));
	if (d == NULL)
		return (NULL);
	s = (char *) s1;
	i = 0;
	while (*s != '\0')
	{
		d[i] = *s++;
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_str_n_dup(const char *s, int x)
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	str = malloc(sizeof(char) * (x + 1));
	while (i < x && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_str_n_dup1(char *s, int x)
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	str = malloc(sizeof(char) * (x + 1));
	while (i < x && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
