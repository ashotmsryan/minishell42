/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_set_unset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:43:22 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:43:26 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	if_gig_only(char *str, int *k, t_mini_shell *minir_shell, int i)
{
	int	j;

	j = 0;
	if (str[*k] && str[*k] == '>' && str[*k + 1] && str[*k + 1] != '>')
	{
		if (*k - 1 > 0 && str[*k - 1] != 32)
			j++;
		*k += 1;
		j += 1;
		while (str[*k] && str[*k] == ' ')
			(*k)++;
		syntax_error_search2(str, &minir_shell[i], j, *k);
		while (str[*k] && str[*k] != '<' && str[*k] != '>' && str[*k] != ' '
			&& str[*k] != 39 && str[*k] != 34 && str[*k] != '$')
		{
			j++;
			(*k)++;
		}
	}
	return (j);
}

int	if_smol_only(char *str, int *k, t_mini_shell *minir_shell, int i)
{
	int	j;

	j = 0;
	if (str[*k] && str[*k] == '<' && str[*k + 1] && str[*k + 1] != '<')
	{
		if (*k - 1 > 0 && str[*k - 1] != 32)
			j++;
		*k += 1;
		j += 1;
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

void	if_34_39_32_topass(char *str, int *k, int *j)
{
	if (str[*k] && str[*k] == '$')
	{
		(*j)++;
		(*k)++;
		if (str[*k] && str[*k] == 32)
		{
			(*j)++;
			while (str[*k] && str[*k] == ' ')
			(*k)++;
		}
	}
	if (str[*k] && str[*k] != '<' && str[*k] != '>'
		&& str[*k] != 32 && str[*k] != '$' && str[*k] != 34 && str[*k] != 39)
	{
		(*k)++;
		(*j)++;
	}
	if (str[*k] && (str[*k] == '<' || str[*k] == '>' || str[*k] == 32
			|| str[*k] == '$' || str[*k] == 34
			|| str[*k] == 39) && !str[*k + 1])
	{
		(*k)++;
		(*j)++;
	}
}

char	*spease_set_unset(char *str,
	t_stract *mini, t_mini_shell *minir_shell, int i)
{
	int		k;
	int		j;
	char	*s;

	k = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[k])
	{
		j += if_39_str(str, mini, &minir_shell[i], &k);
		if_34_str(str, &k, &j);
		syntax_error_search1(str, &minir_shell[i], j, k);
		j += if_smol_smol(str, &k, minir_shell, i);
		j += if_big_big(str, &k, minir_shell, i);
		j += if_gig_only(str, &k, minir_shell, i);
		j += if_smol_only(str, &k, minir_shell, i);
		if_34_39_32_topass(str, &k, &j);
	}
	s = parsing_one_pipe(str, j);
	return (s);
}
