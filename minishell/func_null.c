/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:43:36 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:43:38 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_null_new_for_start1(t_stract *mini)
{
	mini->fork_main = 0;
	mini->syntax_error = 0;
	mini->when_pipe_error = 0;
	mini->error = 0;
	mini->ep_flag = 0;
	mini->pipe_number = 0;
	mini->flag_write = 0;
	mini->end = 0;
}

void	func_null_new_for_start2(t_stract *mini)
{
	mini->access_if = 0;
	mini->flag = 0;
	mini->forks = 0;
	mini->error_char = 0;
	mini->pwd_current = 0;
	mini->pwd_util = 0;
	mini->oldpwd = 0;
	mini->line = 0;
	mini->path = 0;
	mini->line_split_pipe = 0;
	mini->line_split_pipe_mini_shell = 0;
	mini->cmd = 0;
	mini->env = 0;
	mini->path_split = 0;
	mini->data._stdout = 1;
	mini->data._stdin = 1;
}

void	func_null_new_for_data2_start3(t_stract *mini)
{
	mini->data2.fork_for_hd = 0;
	mini->data2.index = 0;
	mini->data2.flag_for_paths = 0;
	mini->data2.pipe_count = 0;
	mini->data2.export_number = 0;
	mini->data2.doubl_left_index = 0;
	mini->data2.line = 0;
	mini->data2.env = 0;
	mini->data2.heredoc = 0;
	mini->data2.built.hd_data = 0;
	mini->data2.built.ep_data = 0;
	mini->data2.built.s = 0;
}

void	func_null(t_stract *mini, char **env)
{
	func_null_new_for_start1(mini);
	func_null_new_for_start2(mini);
	func_null_new_for_data2_start3(mini);
	mini->path = getenv("PATH=");
	mini->env = env_new(env);
	mini->data2.env = mini->env;
	mini->path_split = ft_split(mini->path, ':');
}
