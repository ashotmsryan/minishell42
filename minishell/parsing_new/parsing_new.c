/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:47:37 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 03:51:11 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_len_doeble_pars(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

void	parsing_new_redirect1(int i, t_mini_shell *minir_shell, int len)
{
	int		j;

	j = 0;
	while (j < len)
	{
		if (minir_shell[i].command && minir_shell[i].command[j])
		{
			if (ft_strncmp_pars_new(minir_shell[i].command[j], "<<", 2) == 0)
				;
			else if (ft_strncmp_pars_new(minir_shell[i].command[j],
					">>", 2) == 0)
				pars_redirect2(i, j, minir_shell, minir_shell[i].command);
			else if (ft_strncmp_pars_new(minir_shell[i].command[j],
					"<", 1) == 0)
				pars_redirect3(i, j, minir_shell, minir_shell[i].command);
			else if (ft_strncmp_pars_new(minir_shell[i].command[j],
					">", 1) == 0)
				pars_redirect4(i, j, minir_shell, minir_shell[i].command);
			else
				pars_redirect_not(i, j, minir_shell, minir_shell[i].command);
		}
		j++;
	}
}

int	parsing_new_r(int i, t_mini_shell *minir_shell)
{
	int	len;
	int	j;

	len = ft_len_doeble_pars(minir_shell[i].command);
	j = 0;
	parsing_new_redirect1(i, minir_shell, len);
	return (0);
}
