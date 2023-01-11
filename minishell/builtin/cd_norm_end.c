/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:19:23 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 22:19:25 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_func_tilda_notarg_cd_new_norm(t_stract *mini, int i,
	t_mini_shell *minir_shell)
{
	env_change(mini, "PWD=", minir_shell[i].pwd_util, &minir_shell[i]);
	env_change(mini, "OLDPWD=",
		minir_shell[i].pwd_current, &minir_shell[i]);
	free(minir_shell[i].pwd_current);
	minir_shell[i].pwd_current = 0;
	minir_shell[i].pwd_current = ft_getenv("PWD=", i, minir_shell);
	if (chdir(minir_shell[i].pwd_current) == -1)
	{
		write(2, "minishell: cd: HOME not set\n", 28);
		g_status = 1;
	}
}
