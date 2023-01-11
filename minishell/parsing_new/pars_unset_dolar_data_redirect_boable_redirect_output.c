/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_unset_dolar_data_redirect_boable_red          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:10:30 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 02:10:33 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pars_unset_dolar_data_redirect_boable_redirect_output_norm(int i,
	t_mini_shell *minir_shell, int len, int j)
{
	if (minir_shell && minir_shell[i].data.boable_redirect_output
		&& minir_shell[i].data.boable_redirect_output[j])
	{
		len = set_dolar(minir_shell[i].data.boable_redirect_output[j],
				&minir_shell[i]);
		if (len > 0)
		{
			set_dolar_new(minir_shell[i].data.boable_redirect_output[j],
				&minir_shell[i], len);
			free(minir_shell[i].data.boable_redirect_output[j]);
			minir_shell[i].data.boable_redirect_output[j] = ft_strdup(
					minir_shell[i].data.utils);
			free(minir_shell[i].data.utils);
			minir_shell[i].data.utils = 0;
		}
	}
}

void	pars_unset_dolar_data_redirect_boable_redirect_output(int i,
	t_mini_shell *minir_shell)
{
	int		j;
	int		len;
	int		number;

	number = 0;
	j = 0;
	number = ft_len_doeble_pars(minir_shell[i].data.boable_redirect_output);
	if (number > j)
	{
		while (number > j)
		{
			len = 0;
			pars_unset_dolar_data_redirect_boable_redirect_output_norm(i,
				minir_shell, len, j);
			j++;
		}
	}
}
