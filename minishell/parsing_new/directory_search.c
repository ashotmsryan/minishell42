/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:34:30 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 00:59:17 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pars_have_redirect(int i, int j,
	t_mini_shell *minir_shell, char	**command)
{
	char	**str;

	str = 0;
	str = ft_strjoin_double_point
		(minir_shell[i].data.redirect_have, command[j]);
	if (str && *str)
	{
		free(minir_shell[i].data.redirect_have);
		minir_shell[i].data.redirect_have = 0;
		minir_shell[i].data.redirect_have = str;
		str = 0;
	}
}
