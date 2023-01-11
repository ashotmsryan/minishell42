/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_mini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:39:09 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:39:10 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	t_data_free_char_doeble_point(t_stract *mini)
{
	if (mini->line_split_pipe)
	{
		doeble_point_free(mini->line_split_pipe);
		free(mini->line_split_pipe);
		mini->line_split_pipe = 0;
	}
	if (mini->line_split_pipe_mini_shell)
	{
		doeble_point_free(mini->line_split_pipe_mini_shell);
		free(mini->line_split_pipe_mini_shell);
		mini->line_split_pipe_mini_shell = 0;
	}
	if (mini->cmd)
	{
		doeble_point_free(mini->cmd);
		free(mini->cmd);
		mini->cmd = 0;
	}
}

void	t_data_free_char_doeble_point_norm(t_stract *mini)
{
	if (mini->env)
	{
		doeble_point_free(mini->env);
		free(mini->env);
		mini->env = 0;
	}
	if (mini->path_split)
	{
		doeble_point_free(mini->path_split);
		free(mini->path_split);
		mini->path_split = 0;
	}
}

void	t_data_data2_int(t_stract *mini)
{
	mini->data2.index = 0;
	mini->data2.flag_for_paths = 0;
	mini->data2.pipe_count = 0;
	mini->data2.export_number = 0;
	mini->data2.fork_for_hd = 0;
	mini->data2.doubl_left_index = 0;
}

void	t_data_data2_char(t_stract *mini)
{
	free(mini->data2.line);
	mini->data2.line = 0;
	if (mini->data2.heredoc)
	{
		doeble_point_free(mini->data2.heredoc);
		free(mini->data2.heredoc);
		mini->data2.heredoc = 0;
	}
}

void	memory_free_mini(t_stract *mini)
{
	t_data_int_free1(mini);
	t_data_free_char_one_point(mini);
	t_data_free_char_doeble_point(mini);
	t_data_free_char_doeble_point_norm(mini);
	t_data_data2_int(mini);
	t_data_data2_char(mini);
	t_data_data2_built(mini);
}
