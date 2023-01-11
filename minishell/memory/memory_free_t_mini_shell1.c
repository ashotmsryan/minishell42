/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_t_mini_shell1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:40:09 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:05:47 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	memory_free_mini_shell_doeble_int2(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		free(mini_shell[i].flag_quote);
		mini_shell[i].flag_quote = 0;
		i++;
	}
}

void	memory_free_mini_shell_char3(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		free(mini_shell[i].pwd_util);
		mini_shell[i].pwd_util = 0;
		free(mini_shell[i].oldpwd);
		mini_shell[i].oldpwd = 0;
		free(mini_shell[i].pwd_current);
		mini_shell[i].pwd_current = 0;
		free(mini_shell[i].path);
		mini_shell[i].path = 0;
		free(mini_shell[i].pwd);
		mini_shell[i].pwd = 0;
	}
}

void	memory_free_mini_shell_char4(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		free(mini_shell[i].string_return);
		mini_shell[i].string_return = 0;
		free(mini_shell[i].shell_line_split_pipe);
		mini_shell[i].shell_line_split_pipe = 0;
		free(mini_shell[i].shell_line_split_pipe_old);
		mini_shell[i].shell_line_split_pipe_old = 0;
		free(mini_shell[i].shell_for_herdoc);
		mini_shell[i].shell_for_herdoc = 0;
		free(mini_shell[i].error_char);
		mini_shell[i].error_char = 0;
		free(mini_shell[i].verified_path);
		mini_shell[i].verified_path = 0;
	}
}

void	memory_free_mini_shell_char_doeble5(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		if (mini_shell[i].env)
		{
			doeble_point_free(mini_shell[0].env);
			free(mini_shell[0].env);
			mini_shell[0].env = 0;
		}
		if (mini_shell[i].path_split)
		{
			doeble_point_free(mini_shell[0].path_split);
			free(mini_shell[0].path_split);
			mini_shell[0].path_split = 0;
		}
	}
}
