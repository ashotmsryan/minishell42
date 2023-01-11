/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   that_cammand_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:46:56 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 23:35:11 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

int	diyrectory(int i, t_mini_shell *minir_shell)
{
	DIR	*pdir;

	pdir = opendir(minir_shell[i].data.pipe_split[0]);
	if (pdir)
	{
		write (2, "minishell :", 12);
		write (2, minir_shell[i].data.pipe_split[0],
			ft_strlen(minir_shell[i].data.pipe_split[0]));
		write (2, "is a directory\n", 15);
		closedir(pdir);
		return (0);
	}
	return (1);
}

void	check_for_command_norm(int i, t_mini_shell *minir_shell)
{
	minir_shell[i].error_char = minir_shell[i].data.pipe_split[0];
	g_status = 127;
}

int	check_for_command(t_stract *mini,
	int i, t_mini_shell *minir_shell)
{
	pipe_and_dup(mini, i, minir_shell);
	for_that_cammand_number(mini, i, minir_shell);
	if (minir_shell[i].data.that_cammand_number == 12
		&& ft_getenv("PATH=", i, minir_shell))
	{
		g_status = 0;
		execve(minir_shell[i].verified_path,
			minir_shell[i].data.pipe_split, mini->env);
		g_status = 1;
		minir_shell[i].error = 8;
		exit (1);
	}
	else if (minir_shell[i].data.that_cammand_number == 14)
		check_for_command_norm(i, minir_shell);
	else if (minir_shell[i].data.that_cammand_number == 15)
	{
		minir_shell[i].error = 15;
		minir_shell[i].error_char = minir_shell[i].data.pipe_split[0];
	}
	error_for(i, minir_shell);
	return (1);
}

int	command_have(t_stract *mini,
	int i, t_mini_shell *minir_shell)
{
	if (ft_strncmp2(minir_shell[i].data.pipe_split[0], "env", 3) == 0)
	{
		minir_shell[i].data.that_cammand_number = 5;
		env_func(i, minir_shell);
		return (1);
	}
	else if (ft_strncmp2(minir_shell[i].data.pipe_split[0], "cd", 2) == 0)
	{
		minir_shell[i].data.that_cammand_number = 6;
		cd_func(mini, i, minir_shell);
		return (1);
	}
	else if (ft_strncmp2(minir_shell[i].data.pipe_split[0], "pwd", 3) == 0)
	{
		minir_shell[i].data.that_cammand_number = 7;
		pwd_func(mini, i, minir_shell);
		return (1);
	}
	else if (ft_strncmp2(minir_shell[i].data.pipe_split[0], "echo", 4) == 0)
	{
		minir_shell[i].data.that_cammand_number = 8;
		echo_func(i, minir_shell);
		return (1);
	}
	return (0);
}

void	for_that_cammand_number(t_stract *mini,
		int i, t_mini_shell *minir_shell)
{
	if (minir_shell[i].data.pipe_split && minir_shell[i].data.pipe_split[0])
	{
		if (command_have(mini, i, minir_shell) == 1)
			return ;
		else if (ft_strncmp2(minir_shell[i].data.pipe_split[0], "exit", 4) == 0)
		{
			minir_shell[i].data.that_cammand_number = 9;
			if_exit(minir_shell, i, mini);
		}
		else if (ft_strncmp2(minir_shell[i].data.pipe_split[0],
				"export", 6) == 0)
		{
			minir_shell[i].data.that_cammand_number = 10;
			if_export(minir_shell, i, mini);
		}
		else if (ft_strncmp2(minir_shell[i].data.pipe_split[0],
				"unset", 5) == 0)
		{
			minir_shell[i].data.that_cammand_number = 11;
			ft_unset(i, minir_shell, mini);
		}
		else
			func_call_accsess(i, minir_shell);
	}
}
