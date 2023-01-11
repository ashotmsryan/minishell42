/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:22:56 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 23:39:04 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_or_parent_start_norm(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	mini->forks[i] = fork();
	if (mini->forks[i] == -1)
	{
		kill_all(mini, i, minir_shell);
		return (1);
	}
	if (mini->forks[i] == 0)
	{
		if (mini->pipe_number > 1 || minir_shell[i].flag == 0)
		{
			signal_call(0);
			check_for_command(mini, i, minir_shell);
		}
		exit(g_status);
	}
	return (0);
}

int	fork_or_parent_start(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	minir_shell[i].data.id = minir_shell[i].id;
	if (when_have_redirect(mini, i, minir_shell) == 1)
		return (2);
	if (mini->pipe_number > 1 || minir_shell[i].flag == 0)
		if (fork_or_parent_start_norm(mini, i, minir_shell) == 1)
			return (1);
	if (mini->pipe_number == 1 && minir_shell[i].flag == 1)
	{
		check_for_command(mini, i, minir_shell);
	}
	close(minir_shell[i].data.fd_input);
	close(minir_shell[i].data.fd_output);
	return (0);
}

void	wait_close_dup(t_stract *mini, t_mini_shell *minir_shell)
{
	int	i;

	i = 0;
	while (i < mini->pipe_number - 1)
	{
		close(mini->end[i][1]);
		close(mini->end[i][0]);
		i++;
	}
	i = -1;
	while (++i < mini->pipe_number
		&& (mini->pipe_number > 1 || minir_shell[i].flag == 0))
	{
		waitpid(mini->forks[i], &g_status, 0);
		if (WIFEXITED(g_status))
			g_status = WEXITSTATUS(g_status);
		else if (WIFSIGNALED(g_status))
		{
			if (g_status == SIGQUIT && i == mini->pipe_number - 1)
				write(1, "Quit: 3\n", 9);
			else if (g_status != SIGQUIT && i == mini->pipe_number - 1)
				write(1, "\n", 1);
			g_status = WTERMSIG(g_status) + 128;
		}
	}
}

void	start_minishell(t_stract *mini, t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	if (mini && mini->line && l_nlen(mini->line, ' ') != 0)
	{
		malloc_start(mini);
		while (i < mini->pipe_number - 1)
		{
			if (pipe(mini->end[i]) == -1)
			{
				printf("pipe ERROR\n");
				mini->when_pipe_error = 1;
				free_all_78(&mini, &mini_shell);
				return ;
			}
			i++;
		}
		mini_shell_null(mini, mini_shell);
		if (mini->when_pipe_error == 0)
			pipe_read_write(mini, mini_shell);
	}
	else
		when_one_line(mini);
}
