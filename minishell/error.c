/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:41:31 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:42:00 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_search_error1(t_mini_shell *minir_shell, int *j, char *str, int *i)
{
	if (str[*i] == 39)
	{
		*j = *i;
		while (str[++(*i)] != 39 && str[*i] != '\0')
			;
		if (!str[*i])
		{
			minir_shell->segmenf_error = 1;
			minir_shell->index_sintex = *j;
			minir_shell->error = 5;
			return (0);
		}
		if (str[*i])
			(*i)++;
	}
	if (str[*i] != '\0' && str[*i] != 34 && str[*i] != 39)
		(*i)++;
	return (1);
}

void	search_error_for_norm1(t_mini_shell *minir_shell, int i_index, int j)
{
	minir_shell[i_index].segmenf_error = 1;
	minir_shell[i_index].index_sintex = j;
	minir_shell[i_index].error = 5;
}

int	search_error(char *str, t_mini_shell *minir_shell, int i_index)
{
	int	i;
	int	j;

	minir_shell->data.z = i_index;
	(void)minir_shell->data.z;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 34)
		{
			j = i;
			while (str[++i] != 34 && str[i] != '\0')
				;
			if (!str[i])
			{
				search_error_for_norm1(minir_shell, i_index, j);
				return (0);
			}
			if (str[i])
				i++;
		}
		else if (error_search_error1(&minir_shell[i], &j, str, &i) == 0)
			return (0);
	}
	return (1);
}

void	ft_putstr_2(char *err, char *arg)
{
	write(2, err, ft_strlen0(err));
	if (arg)
		write(2, arg, ft_strlen0(arg));
}
