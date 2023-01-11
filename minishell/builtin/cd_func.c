/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:36:55 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/16 22:11:23 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <dirent.h>

void	cd_func_tilda_notarg(t_stract *mini, int i,
		t_mini_shell *minir_shell)
{
	minir_shell[i].pwd_util = ft_strjoin(ft_getenv
			("HOME=", i, minir_shell), "");
	minir_shell[i].pwd_current = ft_strjoin(ft_getenv
			("PWD=", i, minir_shell), "");
	if (minir_shell[i].pwd_util && minir_shell[i].pwd_current)
	{
		if (ft_getenv("HOME=", i, minir_shell))
		{
			cd_func_tilda_notarg_cd_new_norm(mini, i, minir_shell);
		}
		else
		{
			write(2, "minishell: cd: HOME not set\n", 28);
			g_status = 1;
		}
		minir_shell[i].pwd_current = 0;
	}
	free(minir_shell[i].pwd_util);
	minir_shell[i].pwd_util = 0;
	free(minir_shell[i].pwd_current);
	minir_shell[i].pwd_current = 0;
}

void	cd_func_line(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	minir_shell[i].pwd_util = ft_getenv("OLDPWD=", i, minir_shell);
	minir_shell[i].pwd_current = ft_getenv("PWD=", i, minir_shell);
	if (minir_shell[i].pwd_util && minir_shell[i].pwd_util[0]
		&& minir_shell[i].pwd_current && minir_shell[i].pwd_current[0])
	{
		minir_shell[i].pwd_current = ft_strjoin(
				ft_getenv("PWD=", i, minir_shell), "");
		minir_shell[i].pwd_util = ft_strjoin(
				ft_getenv("OLDPWD=", i, minir_shell), "");
		cd_func_n(mini, i, minir_shell);
		free(minir_shell[i].pwd_util);
		minir_shell[i].pwd_util = 0;
		free(minir_shell[i].pwd_current);
		minir_shell[i].pwd_current = 0;
	}
	else
	{
		g_status = 1;
		write(2, "minishell: cd: OLDPWD not set\n", 30);
	}
}

void	cd_func_b(t_stract *mini, int *iflag, int i, t_mini_shell *minir_shell)
{
	char	s[256];

	minir_shell[i].pwd_current = getcwd(s, sizeof(s));
	if (minir_shell[i].pwd_current)
	{
		minir_shell[i].oldpwd = ft_strjoin(ft_getenv("PWD=",
					i, minir_shell), "");
		env_change(mini, "PWD=", minir_shell[i].pwd_current, &minir_shell[i]);
		env_change(mini, "OLDPWD=", minir_shell[i].oldpwd, &minir_shell[i]);
		free(minir_shell[i].oldpwd);
		minir_shell[i].oldpwd = 0;
		if (minir_shell[i].pipe_number == 1)
			*iflag = 0;
	}
	else
	{
		cd_func_normin1(mini, iflag, i, minir_shell);
	}
}

void	cd_func_m(t_stract *mini, int *iflag, int i, t_mini_shell *minir_shell)
{
	if (!minir_shell[i].data.pipe_split[1] || (minir_shell[i].data.pipe_split[1]
			&& ft_strcmp(minir_shell[i].data.pipe_split[1], "~") == 0))
	{
		cd_func_tilda_notarg(mini, i, minir_shell);
		g_status = 0;
	}
	else if (minir_shell[i].data.pipe_split[1] && ft_strcmp
		(minir_shell[i].data.pipe_split[1], "-") == 0)
	{
		cd_func_line(mini, i, minir_shell);
		g_status = 0;
	}
	else
		cd_f_m_no(mini, iflag, i, minir_shell);
}

void	cd_func(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	static int	iflag;

	iflag = 0;
	minir_shell[i].pwd_util = 0;
	minir_shell[i].pwd_current = 0;
	minir_shell[i].oldpwd = 0;
	cd_func_m(mini, &iflag, i, minir_shell);
}
