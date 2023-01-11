/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_unset_dolar_data_redirect_input.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:11:45 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 02:11:47 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	pars_unset_dolar_data_redirect_input_norm(int i,
	t_mini_shell *minir_shell, int len, int j)
{
	if (minir_shell && minir_shell[i].data.redirect_input
		&& minir_shell[i].data.redirect_input[j])
	{
		len = set_dolar(minir_shell[i].data.redirect_input[j], &minir_shell[i]);
		if (len > 0)
		{
			set_dolar_new(minir_shell[i].data.redirect_input[j],
				&minir_shell[i], len);
			free(minir_shell[i].data.redirect_input[j]);
			minir_shell[i].data.redirect_input[j] = ft_strdup(
					minir_shell[i].data.utils);
			free(minir_shell[i].data.utils);
			minir_shell[i].data.utils = 0;
		}
	}
}

void	pars_unset_dolar_data_redirect_input(int i, t_mini_shell *minir_shell)
{
	int		j;
	int		len;
	int		number;

	number = 0;
	j = 0;
	number = ft_len_doeble_pars(minir_shell[i].data.redirect_input);
	if (number > j)
	{
		while (number > j)
		{
			len = 0;
			pars_unset_dolar_data_redirect_input_norm(i, minir_shell, len, j);
			j++;
		}
	}
}
