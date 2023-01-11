/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_nev_func_8i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:02:04 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 04:48:17 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pars_unset_quots_data_redirect_input(int i, t_mini_shell *minir_shell)
{
	int		l;
	int		a;
	int		quote_have;
	char	*new_str;

	a = 0;
	while (minir_shell[i].data.redirect_input
		&& minir_shell[i].data.redirect_input[a])
	{
		quote_have = 0;
		l = 0;
		l = pars_unset_qouts_norm(minir_shell[i].data.redirect_input[a],
				&quote_have);
		if (l && quote_have == 1)
		{
			new_str = pars_unset_quots_data_redirect_input_norm(i,
					minir_shell, a, l);
			if (new_str)
				for_puqdri_1(a, new_str, i, minir_shell);
		}
		a++;
	}
}

void	for_puqdri_1(int a, char *new_str, int i, t_mini_shell *minir_shell)
{
	free(minir_shell[i].data.redirect_input[a]);
	minir_shell[i].data.redirect_input[a] = new_str;
	new_str = 0;
}

void	new_str_puq(char *new_str, int a, int i, t_mini_shell *minir_shell)
{
	if (new_str)
	{
		free(minir_shell[i].data.boable_redirect_output[a]);
		minir_shell[i].data.boable_redirect_output[a] = new_str;
		new_str = 0;
	}
}
