/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:07:39 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/01 05:28:35 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlen_1(char *str)
{
	int	i;

	i = 2;
	if (!str)
		return (1);
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

size_t	hd_strlen(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '<' && s1[i] != '>' && s1[i] != ' ')
		i++;
	while (s2[j] && s2[j] != '<' && s2[j] != '>' && s2[j] != ' ')
		j++;
	if (i > j)
		return (i);
	else
		return (j);
}

int	ft_strlen_double(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str && str[i])
	{
		i++;
	}
	return (i);
}
