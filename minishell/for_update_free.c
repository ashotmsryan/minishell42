/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_update_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:42:25 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/21 17:24:31 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	updata_free_minishell_doubl_a(int j, t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	free_it(&mini_shell[j].command);
	free_it(&mini_shell[j].data.redirect_have);
	free_it(&mini_shell[j].data.heredoc);
	free_it(&mini_shell[j].data.pipe_split);
	free_it(&mini_shell[j].data.old_pipe_split);
	free_it(&mini_shell[j].data.boable_redirect_output);
	free_it(&mini_shell[j].data.redirect_input);
	free_it(&mini_shell[j].data.redirect_output);
	free_it(&mini_shell[j].data2.built.hd_data);
	free_it(&mini_shell[j].data2.built.s);
}

static	void	update_free(t_stract *mini)
{
	int	i;

	if (mini->line_split_pipe)
	{
		free_it(&mini->line_split_pipe);
		mini->line_split_pipe = 0;
	}
	mini->when_pipe_error = 0;
	i = 0;
	mini->syntax_error = 0;
	free(mini->line);
	mini->line = 0;
	free(mini->end);
	mini->end = 0;
	free(mini->cmd);
	mini->cmd = 0;
	free(mini->access_if);
	mini->access_if = 0;
	free(mini->forks);
	mini->forks = 0;
}

void	updata_free_minishell(int j, t_mini_shell *mini_shell)
{
	mini_shell[j].data2.index = 0;
	mini_shell[j].segmenf_error = 0;
	mini_shell[j].index_sintex = 0;
	mini_shell[j].data.x = 0;
	mini_shell[j].data.y = 0;
	mini_shell[j].data.left_index = 0;
	mini_shell[j].data.right_index = 0;
	mini_shell[j].data.doubl_left_index = 0;
	mini_shell[j].data.doubl_right_index = 0;
	mini_shell[j].data.flag_for_input = 0;
	mini_shell[j].data.flag_for_output = 0;
	free(mini_shell[j].shell_for_herdoc);
		mini_shell[j].shell_for_herdoc = 0;
	free(mini_shell[j].shell_line_split_pipe_old);
		mini_shell[j].shell_line_split_pipe_old = 0;
	free(mini_shell[j].data.utils);
		mini_shell[j].data.utils = 0;
	free(mini_shell[j].verified_path);
		mini_shell[j].verified_path = NULL;
	free(mini_shell[j].flag_quote);
		mini_shell[j].flag_quote = 0;
}

void	update_free_new(int j, t_mini_shell *mini_shell)
{
	free(mini_shell[j].string_return);
	mini_shell[j].string_return = 0;
	free(mini_shell[j].shell_line_split_pipe);
	mini_shell[j].shell_line_split_pipe = 0;
}

void	for_update_free(t_stract *mini, t_mini_shell **mini_shell)
{
	int	j;

	j = 0;
	if (mini && mini->pipe_number)
	{
		if (mini->pipe_number)
		{
			j = 0;
			while (*mini_shell && j < mini->pipe_number)
			{
				free(mini->flag);
				mini->flag = 0;
				mini->syntax_error = 0;
				updata_free_minishell(j, *mini_shell);
				updata_free_minishell_doubl_a(j, *mini_shell);
				update_free_new(j, *mini_shell);
				j++;
			}
			free(*mini_shell);
			*mini_shell = 0;
		}
		free(mini->line);
		mini->line = 0;
	}
	update_free(mini);
}
