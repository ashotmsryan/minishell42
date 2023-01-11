/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_pars_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 05:43:49 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 22:02:53 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_wait(t_mini_shell *minir_shell, int i)
{
	waitpid(minir_shell[i].data2.fork_for_hd, &g_status, 0);
	if (WIFEXITED(g_status))
		g_status = WEXITSTATUS(g_status);
	else if (WIFSIGNALED(g_status))
	{
		write(1, "\n", 1);
		g_status = WTERMSIG(g_status) + 128;
	}
}

void	heredoc_when_output(t_mini_shell *minir_shell, int i)
{
	int	jx;

	jx = -1;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	minir_shell[i].data2.fork_for_hd = fork();
	if (minir_shell[i].data2.fork_for_hd < 0)
	{
		printf("can not open fork\n");
		g_status = 1;
		return ;
	}
	if (minir_shell[i].data2.fork_for_hd == 0)
	{
		heredoc(&minir_shell[i]);
		close (minir_shell[i].data2.end[0]);
		heredoc_when_output_norm(minir_shell, i, &jx);
		close(minir_shell[i].data2.end[1]);
		free_it(&minir_shell[i].data2.built.hd_data);
		exit(0);
	}
	close (minir_shell[i].data2.end[1]);
	heredoc_wait(minir_shell, i);
}

int	func_hirdock_norm1(t_mini_shell *minir_shell, int *i)
{
	if (minir_shell[*i].data.flag_for_input == 2)
	{
		if (pipe(minir_shell[*i].data2.end) != 0)
		{
			printf("can not add pipe\n");
			return (1);
		}
		heredoc_when_output(minir_shell, *i);
	}
	else
		when_input_not_is_hirdoc(minir_shell, *i);
	return (0);
}

int	func_hirdock(t_stract *mini, t_mini_shell *minir_shell)
{
	int	i;

	i = -1;
	if (!minir_shell && (mini->line || mini->line[0]))
		return (1);
	while (++i < mini->pipe_number)
	{
		if (minir_shell[i].data.doubl_left_index > 0)
		{
			heredoc_init(mini, &minir_shell[i]);
			if (func_hirdock_norm1(minir_shell, &i) == 1)
				return (1);
		}
		if (minir_shell[i].segmenf_error == 1)
			return (1);
	}
	return (0);
}
