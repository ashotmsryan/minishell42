/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pars_dollar_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:13:16 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/21 17:11:55 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	new_pars_dolar_s_norm(int i,
	t_mini_shell *minir_shell, int len)
{
	if (minir_shell[i].shell_line_split_pipe)
	{
		len = set_dolar(minir_shell[i].shell_line_split_pipe, &minir_shell[i]);
		set_dolar_new(minir_shell[i].shell_line_split_pipe,
			&minir_shell[i], len);
		minir_shell[i].shell_line_split_pipe = ft_strdup(minir_shell
			[i].data.utils);
		free(minir_shell[i].data.utils);
		minir_shell[i].data.utils = 0;
	}
}

void	new_pars_dolar_s(int i, t_mini_shell *minir_shell)
{
	int	len;

	len = 0;
	new_pars_dolar_s_norm(i, minir_shell, len);
}
