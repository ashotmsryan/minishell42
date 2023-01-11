/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_unset_dollar_data_pipe_split.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:13:16 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 02:13:18 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pars_unset_dolar_data_pipe_split_norm(int i,
	t_mini_shell *minir_shell, int len, int j)
{
	if (minir_shell && minir_shell[i].data.old_pipe_split
		&& minir_shell[i].data.pipe_split && minir_shell[i].data.pipe_split[j])
	{
		len = set_dolar(minir_shell[i].data.pipe_split[j], &minir_shell[i]);
		set_dolar_new(minir_shell[i].data.pipe_split[j], &minir_shell[i], len);
		minir_shell[i].data.old_pipe_split[j] = minir_shell
		[i].data.pipe_split[j];
		minir_shell[i].data.pipe_split[j] = ft_strdup(minir_shell
			[i].data.utils);
		free(minir_shell[i].data.utils);
		minir_shell[i].data.utils = 0;
	}
}

void	pars_unset_dolar_data_pipe_split(int i, t_mini_shell *minir_shell)
{
	int		j;
	int		len;
	int		number;

	number = 0;
	j = 0;
	number = ft_len_doeble_pars(minir_shell[i].data.pipe_split);
	if (number > j)
	{
		minir_shell[i].data.old_pipe_split = (char **)
			malloc(sizeof(char *) * (number + 1));
		if (!minir_shell[i].data.old_pipe_split)
			exit(1);
		while (number > j)
		{
			len = 0;
			pars_unset_dolar_data_pipe_split_norm(i, minir_shell, len, j);
			j++;
		}
		minir_shell[i].data.old_pipe_split[j] = 0;
	}
}
