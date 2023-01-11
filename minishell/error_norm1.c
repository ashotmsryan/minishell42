/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_norm1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:41:17 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:43:29 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_line(t_stract *mini, int j, int k)
{
	char	*str;

	str = ft_str_n_dup(mini->line, j);
	free(mini->line);
	mini->line = str;
	str = 0;
	mini->syntax_error = k;
}

int	error_search_error2(t_stract *mini, char *str, int *i)
{
	int	j;

	if (str[*i] == 39)
	{
		j = *i;
		if (j > 0)
			j--;
		while (str[*i] != '\0' && str[++(*i)] != 39)
			;
		if (!str[*i])
		{
			new_line(mini, j, 9);
			return (1);
		}
		else
			(*i)++;
	}
	if (str[*i] != '\0' && str[*i] != 34 && str[*i] != 39)
		(*i)++;
	return (0);
}

void	search_error2_norm2(char *str, int *j, int *i)
{
	*j = *i;
	if (*j > 0)
		(*j)--;
	while (str[++(*i)] != 34 && str[*i] != '\0')
		;
}

int	search_error2(t_stract *mini)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = mini->line;
	while (str[i] != '\0')
	{
		if (str[i] == 34)
		{
			search_error2_norm2(str, &j, &i);
			if (!str[i])
			{
				new_line(mini, j, 10);
				return (1);
			}
			else
				i++;
		}
		else if (error_search_error2(mini, str, &i) != 0)
			return (1);
	}
	return (1);
}
