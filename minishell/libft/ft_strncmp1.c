/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:50:26 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/16 14:24:25 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp0(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && s2)
		return (-1);
	else if (s1 && !s2)
		return (1);
	else if (!s1 && !s2)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != '\0' && s2[i] == '\0')
			return (1);
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (!s1[j] || !s2[j] || s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	return (0);
}
