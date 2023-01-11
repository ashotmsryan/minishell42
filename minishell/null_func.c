/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:24:38 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 23:53:25 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_shell_null_norm(t_stract *mini, t_mini_shell *mini_shell, int j)
{
	mini_shell[j].end = mini->end;
	mini_shell[j].path = mini->path;
	mini_shell[j].forks = mini->forks;
	mini_shell[j].when_pipe_error = mini->when_pipe_error;
	mini_shell[j].data2.env = mini->env;
	mini_shell[j].data2.index = 0;
}

void	mini_shell_null(t_stract *mini, t_mini_shell *mini_shell)
{
	int	j;

	j = -1;
	while (mini && mini_shell && mini->pipe_number > ++j)
	{
		mini_shell[j].flag_quote = 0;
		mini_shell[j].data2 = mini->data2;
		mini_shell[j].id = j;
		mini_shell[j].flag = 0;
		mini_shell[j].env = mini->env;
		mini_shell[j].path_split = mini->path_split;
		mini_shell[j].segmenf_error = 0;
		mini_shell[j].index_sintex = 0;
		mini_shell[j].pwd_util = 0;
		mini_shell[j].oldpwd = 0;
		mini_shell[j].string_return = 0;
		mini_shell[j].pwd_current = 0;
		mini_shell[j].error_char = 0;
		mini_shell[j].error = 0;
		mini_shell[j].segmenf_error = 0;
		mini_shell[j].shell_line_split_pipe = mini->line_split_pipe[j];
		mini_shell[j].pipe_number = mini->pipe_number;
		mini_shell_null_norm(mini, mini_shell, j);
	}
	mini->ep_flag = 1;
}

void	write_null_data2(t_data2 *s)
{
	s->line = 0;
	*s->end = 0;
	s->built.hd_data = 0;
	s->built.s = 0;
}

void	write_null_minishell_norm(t_mini_shell *mini_shell, int j)
{
	mini_shell[j].data.pipe_split = 0;
	mini_shell[j].data.old_pipe_split = 0;
	mini_shell[j].data.redirect_have = 0;
	mini_shell[j].verified_path = 0;
	mini_shell[j].data.redirect_output = 0;
	mini_shell[j].data.redirect_input = 0;
	mini_shell[j].data.boable_redirect_output = 0;
	mini_shell[j].data.heredoc = 0;
	mini_shell[j].data.utils = 0;
	mini_shell[j].shell_for_herdoc = 0;
	mini_shell[j].data.left = 0;
	mini_shell[j].data.right = 0;
	mini_shell[j].data.double_right = 0;
	mini_shell[j].new_len_util = 0;
}

void	write_null_minishell(t_mini_shell *mini_shell, int number)
{
	int	j;

	j = -1;
	while (++j < number)
	{
		mini_shell[j].data.x = 0;
		mini_shell[j].data.y = 0;
		mini_shell[j].command = 0;
		mini_shell[j].data.left_index = 0;
		mini_shell[j].data.right_index = 0;
		mini_shell[j].data.doubl_left_index = 0;
		mini_shell[j].data.doubl_right_index = 0;
		mini_shell[j].data.flag_for_input = 0;
		mini_shell[j].data.flag_for_output = 0;
		mini_shell[j].shell_line_split_pipe_old = 0;
		write_null_minishell_norm(mini_shell, j);
		write_null_data2(&mini_shell[j].data2);
	}
}
