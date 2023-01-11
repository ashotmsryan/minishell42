/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:15:08 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/17 00:02:43 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp_pars_new(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (!s1[j] || !s2[j])
			return (1);
		else if (s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	j;
	size_t	s1_size;
	size_t	s2_size;

	j = 0;
	if (!s1 || !s2)
		return (1);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (s1_size != s2_size)
		return (1);
	while (j < s1_size)
	{
		if (s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	return (0);
}

int	ft_strncmp1(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	if (!s1[j] || (s1[j] && s1[j] == 32))
		return (0);
	return (1);
}

int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	if (!s1[j])
		return (0);
	return (1);
}

int	ft_strncmp111(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	if (!s1[j] || (s1[j] && (s1[j] == 32 || s1[j] == s1[j - 1])))
		return (1);
	return (0);
}
