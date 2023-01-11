/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_new_r_for_herdoc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:47:37 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 22:06:10 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parsing_new_redirect11(int i, t_mini_shell *minir_shell, int len)
{
	int		j;

	j = 0;
	while (j < len)
	{
		if (minir_shell[i].command && minir_shell[i].command[j])
		{
			if (ft_strncmp_pars_new(minir_shell[i].command[j], "<<", 2) == 0)
				pars_redirect1(i, j, minir_shell, minir_shell[i].command);
		}
		j++;
	}
}

int	parsing_new_r_for_herdoc(int i, t_mini_shell *minir_shell)
{
	int	len;
	int	j;

	len = ft_len_doeble_pars(minir_shell[i].command);
	j = 0;
	parsing_new_redirect11(i, minir_shell, len);
	return (0);
}
