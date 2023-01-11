/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:31:14 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 06:04:53 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <dirent.h>

void	cd_f_m_no(t_stract *mini, int *iflag, int i, t_mini_shell *minir_shell)
{
	if (minir_shell[i].data.pipe_split[1]
		&& chdir(minir_shell[i].data.pipe_split[1]) != -1)
	{
		cd_func_b(mini, iflag, i, minir_shell);
		g_status = 0;
	}
	else
	{
		write (2, "minishell: cd: ", 16);
		write (2, minir_shell[i].data.pipe_split[1],
			ft_strlen(minir_shell[i].data.pipe_split[1]));
		write (2, ": No such file or directory\n", 28);
		g_status = 1;
	}
}

void	cd_fu_b_n(t_stract *mini, int *iflag, int i, t_mini_shell *minir_shell)
{
	write (2, "cd: error retrieving current ", 30);
	write (2, "directory: getcwd: cannot ", 27);
	write(2, "access parent directories: ", 28);
	write(2, "No such file or directory\n", 28);
	minir_shell[i].pwd_current = ft_strjoin(ft_getenv
			("PWD=", i, minir_shell), "..");
	minir_shell[i].oldpwd = ft_strjoin(ft_getenv
			("PWD=", i, minir_shell), "");
	env_change(mini, "PWD=",
		minir_shell[i].pwd_current, &minir_shell[i]);
	env_change(mini, "OLDPWD=", minir_shell[i].oldpwd, &minir_shell[i]);
	free(minir_shell[i].oldpwd);
	minir_shell[i].oldpwd = 0;
	free(minir_shell[i].pwd_current);
	minir_shell[i].pwd_current = 0;
	if (minir_shell[i].pipe_number == 1)
		*iflag = 1;
}

void	cd_func_n(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	if (chdir(minir_shell[i].pwd_util) != -1)
	{
		env_change(mini, "PWD=", minir_shell[i].pwd_util, &minir_shell[i]);
		env_change(mini, "OLDPWD=", minir_shell[i].pwd_current,
			&minir_shell[i]);
		printf("%s\n", minir_shell[i].pwd_util);
	}
	else
	{
		write (2, "minishell: cd: ", 16);
		write (2, minir_shell[i].pwd_util,
			ft_strlen(minir_shell[i].pwd_util));
		write (2, ": No such file or directory\n", 28);
		g_status = 1;
	}
}

void	cd_func_normin1(t_stract *mini, int *iflag,
	int i, t_mini_shell *minir_shell)
{
	if (*iflag == 0 && minir_shell[i].pipe_number == 1)
		cd_fu_b_n(mini, iflag, i, minir_shell);
	else if (minir_shell[i].pipe_number > 1)
	{
		g_status = 127;
		write(2, " minishell : cd: ..: No such file or directory\n", 47);
	}
	else
		if (minir_shell[i].pipe_number == 1)
			*iflag = 0;
}
