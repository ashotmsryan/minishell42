/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:56:47 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:52:29 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_it(char ***ptr)
{
	int	i;

	i = -1;
	while (*ptr && (*ptr)[++i])
	{
		free ((*ptr)[i]);
		(*ptr)[i] = 0;
	}
	free (*ptr);
	*ptr = 0;
}

int	norm_dup1(char *s1, int *i, int *flag, char *a)
{
	int	j;
	int	fl;

	j = -1;
	fl = 0;
	while (s1 && s1[++j])
	{
		if (fl == 0 && j > 1 && s1[j - 1] && s1[j - 2] != '='
			&& s1[j - 1] == '=' && s1[j] && s1[j] != '"')
		{
			fl = 1;
			*flag = 1;
			a[*i] = '"';
			(*i)++;
		}
		else if (j != 0 && s1[j - 1] && s1[j - 1] == '='
			&& s1[j] && s1[j] == '"')
			*flag = 2;
		a[*i] = s1[j];
		(*i)++;
	}
	return (j);
}

char	*norm_dup(char *s1, char *a, int i)
{
	int	j;
	int	flag;

	flag = 0;
	j = -1;
	j = norm_dup1(s1, &i, &flag, a);
	if (s1[j] == '\0' && s1[j - 1] == '=' && flag != 2)
	{
		a[i] = '"';
		a[i + 1] = '\0';
		return (a);
	}
	if (flag == 1)
	{
		a[i] = '"';
		a[i + 1] = '\0';
	}
	else
		a[i] = '\0';
	return (a);
}

char	*ep_strdup(char *s1)
{
	int		i;
	char	*a;
	char	*b;

	i = ft_strlen0(s1);
	b = "declare -x ";
	a = malloc((i + 14) * sizeof(char));
	i = -1;
	if (!a)
		return (NULL);
	while (b[++i])
		a[i] = b[i];
	a[i] = 0;
	a = norm_dup(s1, a, i);
	a = del_plus(&a, 1);
	return (a);
}

void	find_asddbl(char **s1, int flag, int *i)
{
	if (flag == 1)
	{
		while (*s1 && (*s1)[++(*i)])
			if ((*s1)[*i] == '+')
				(*s1)[*i] = '\0';
	}
	else if (flag == 0)
		while (*s1 && (*s1)[++(*i)])
			if ((*s1)[*i] == '=')
				(*s1)[*i] = '\0';
}
