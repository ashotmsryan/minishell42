/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_search_norm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 05:32:59 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 06:35:29 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	when_find_tokin(t_stract *mini, char *str, int *i, int j)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (!str[*i])
	{
		str = ft_str_n_dup(mini->line, j);
		free(mini->line);
		mini->line = str;
		return (1);
	}
	else if (char_tokin1(str, i) != 0)
	{
		str = ft_str_n_dup(mini->line, j);
		free(mini->line);
		mini->line = str;
		return (1);
	}
	j = 0;
	return (0);
}

int	pipe_last(t_stract *mini, char *str, int j)
{
	int	l;

	l = j;
	if (str[l] == '|')
	{
		while (str[l] && str[++l] == 32)
			;
		if (!str[l])
		{
			str = ft_str_n_dup(mini->line, j);
			free(mini->line);
			mini->line = str;
			mini->syntax_error = 1;
			return (1);
		}
	}
	return (0);
}

void	syntax_last_nothing(t_stract *mini, int i, int j)
{
	char	*str;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str = mini->line;
	while (mini && str && str[i])
	{
		j = i;
		if (pipe_last(mini, str, j) == 1)
			return ;
		k = char_tokin2(str, &i);
		if (k != 0)
		{
			if (when_find_tokin(mini, str, &i, j) != 0)
			{
				mini->syntax_error = k;
				return ;
			}
			k = 0;
		}
		else
			i++;
	}
}

void	syntacs_error_search_2(t_stract *mini, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (str[i] == '|')
		{
			j = i;
			i++;
			while (str && str[i] && str[i] == 32)
			i++;
			if (!str[i] || (str[i] && str[i] == '|'))
			{
				mini->syntax_error = 1;
				new_line(mini, j - 1, 1);
			}
		}
		i++;
	}
}

int	syntax_error_search(t_stract *mini)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = mini->line;
	if (mini && str)
	{
		if (str && str[i] && char_tokin(str[i]) != 0)
		{
			mini->syntax_error = char_tokin(str[i]);
			return (1);
		}
		if (syntacs_error_search_5(str, mini, i) == 1)
			return (1);
		syntacs_error_search_2(mini, str);
		search_error2(mini);
		syntax_last_nothing(mini, i, j);
	}
	return (0);
}
