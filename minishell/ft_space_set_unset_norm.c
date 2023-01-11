/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_set_unset_norm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:43:16 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:43:17 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	if_39_str_norm(t_stract *mini,
	t_mini_shell *minir_shell, int *k)
{
	mini->error = 1;
	minir_shell->segmenf_error = 1;
	minir_shell->error = 3;
	minir_shell->index_sintex = *k - 1;
}

int	if_39_str(char *str, t_stract *mini,
	t_mini_shell *minir_shell, int *k)
{
	int	j;

	j = 0;
	if (str[*k] && str[*k] == 39)
	{
		(*k)++;
		j++;
		while (str[*k] && str[*k] != 39)
		{
			(*k)++;
			j++;
		}
		if (str[*k])
		{
			(*k)++;
			j++;
		}
		else
			if_39_str_norm(mini, minir_shell, k);
	}
	return (j);
}

void	if_34_str(char *str, int *k, int *j)
{
	if (str[*k] && str[*k] == 34)
	{
		(*k)++;
		(*j)++;
		while (str[*k] && str[*k] != 34)
		{
			(*k)++;
			(*j)++;
		}
		if (str[*k])
		{
			(*k)++;
			(*j)++;
		}
	}
	if (str[*k] && str[*k] == 32)
	{
		(*j)++;
		while (str[*k] && str[*k] == 32)
			(*k)++;
	}
}

int	if_smol_smol(char *str, int *k, t_mini_shell *minir_shell, int i)
{
	int	j;

	j = 0;
	if (str[*k] && str[*k] == '<' && str[*k + 1] && str[*k + 1] == '<')
	{
		if (*k - 1 > 0 && str[*k - 1] != 32)
			j++;
		*k += 2;
		j += 2;
		while (str[*k] && str[*k] == ' ')
			(*k)++;
		syntax_error_search2(str, &minir_shell[i], j, *k);
		while (str[*k] && str[*k] != '<' && str[*k] != '>'
			&& str[*k] != ' ' && str[*k] != 39
			&& str[*k] != 34 && str[*k] != '$')
		{
			j++;
			(*k)++;
		}
	}
	return (j);
}

int	if_big_big(char *str, int *k, t_mini_shell *minir_shell, int i)
{
	int	j;

	j = 0;
	if (str[*k] && str[*k] == '>' && str[*k + 1] && str[*k + 1] == '>')
	{
		if (*k - 1 > 0 && str[*k - 1] != 32)
			j++;
		*k += 2;
		j += 2;
		while (str[*k] && str[*k] == ' ')
			(*k)++;
		syntax_error_search2(str, &minir_shell[i], j, *k);
		while (str[*k] && str[*k] != '<' && str[*k] != '>'
			&& str[*k] != ' ' && str[*k] != 39
			&& str[*k] != 34 && str[*k] != '$')
		{
			j++;
			(*k)++;
		}
	}
	return (j);
}
