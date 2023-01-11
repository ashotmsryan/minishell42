/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_unset_quots.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:04:46 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 04:05:48 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	go_for_double_qout_malloc(char	*str, char search, char *new_str, int *l)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	i++;
	while (str[i] && str[i] != '\0' && str[i] != search)
	{
		new_str[*l] = str[i];
		(*l)++;
		i++;
	}
	if (str[i] == search)
		i++;
	return (i);
}

void	pndh_norm1(int *l, int *k, char *new_str, char *s)
{
	new_str[*l] = s[*k];
	(*k)++;
	(*l)++;
}

char	*pars_new_data_heredoc(int i, t_mini_shell *minir_shell, int a, int l)
{
	char	*new_str;
	int		k;

	k = 0;
	new_str = malloc(sizeof(char) * (l + 1));
	if (!new_str)
		exit (1);
	l = 0;
	while (minir_shell && minir_shell[i].data.heredoc
		&& minir_shell[i].data.heredoc[a]
		&& minir_shell[i].data.heredoc[a][k] != '\0')
	{
		if (minir_shell[i].data.heredoc[a][k] == 34)
			k += go_for_double_qout_malloc(&minir_shell[i].data.heredoc
				[a][k], 34, new_str, &l);
		else if (minir_shell[i].data.heredoc[a][k] == 39)
			k += go_for_double_qout_malloc(&minir_shell[i].data.heredoc
				[a][k], 39, new_str, &l);
		else
			pndh_norm1(&l, &k, new_str, minir_shell[i].data.heredoc[a]);
	}
	new_str[l] = '\0';
	return (new_str);
}

void	pars_unset_qouts_herdoc(int i, t_mini_shell *minir_shell)
{
	int		l;
	int		a;
	int		quote_have;
	char	*new_str;

	a = 0;
	while (minir_shell[i].data.heredoc && minir_shell[i].data.heredoc[a])
	{
		quote_have = 0;
		l = 0;
		l = pars_unset_qouts_norm(minir_shell[i].data.heredoc[a], &quote_have);
		if (l && quote_have == 1)
		{
			new_str = pars_new_data_heredoc(i, minir_shell, a, l);
			if (new_str)
			{
				free(minir_shell[i].data.heredoc[a]);
				minir_shell[i].data.heredoc[a] = new_str;
				new_str = 0;
			}
		}
		a++;
	}
	minir_shell[i].data.quote_have = quote_have;
}
