/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_unset_quots7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:45:02 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/17 00:06:17 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pars_unset_quots_data_pipe_split(int i, t_mini_shell *minir_shell)
{
	int		l;
	int		a;
	int		quote_have;
	char	*new_str;

	a = 0;
	while (minir_shell[i].data.pipe_split
		&& minir_shell[i].data.pipe_split[a])
	{
		quote_have = 0;
		l = 0;
		l = pars_unset_qouts_norm(minir_shell
			[i].data.pipe_split[a], &quote_have);
		if (l && quote_have == 1)
		{
			new_str = pars_unset_quots_data_pipe_split_norm(i,
					minir_shell, a, l);
			if (new_str)
				pars_3(new_str, a, i, minir_shell);
		}
		else if (l == 0)
			pars_set_zro(i, minir_shell, a);
		a++;
	}
}

void	pars_set_zro(int i, t_mini_shell *minir_shell, int a)
{
	char	*new_str;

	free(minir_shell[i].data.pipe_split[a]);
	new_str = malloc(sizeof(char) * 2);
	new_str[0] = ' ';
	new_str[1] = '\0';
	minir_shell[i].data.pipe_split[a] = new_str;
	new_str = 0;
}

void	puqdro9_norm(int i, t_mini_shell *minir_shell, int a, char *new_str)
{
	free(minir_shell[i].data.redirect_output[a]);
	minir_shell[i].data.redirect_output[a] = new_str;
	new_str = 0;
}

void	pars_unset_quots_data_redirect_output(int i, t_mini_shell *minir_shell)
{
	int		l;
	int		a;
	int		quote_have;
	char	*new_str;

	a = 0;
	while (minir_shell[i].data.redirect_output
		&& minir_shell[i].data.redirect_output[a])
	{
		quote_have = 0;
		l = 0;
		l = pars_unset_qouts_norm(minir_shell[i].data.redirect_output[a],
				&quote_have);
		if (l && quote_have == 1)
		{
			new_str = pars_unset_quots_data_redirect_output_norm(i,
					minir_shell, a, l);
			if (new_str)
				puqdro9_norm(i, minir_shell, a, new_str);
		}
		a++;
	}
}
