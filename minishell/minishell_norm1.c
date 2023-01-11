/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_norm1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:22:33 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/21 17:25:07 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_len_delet_spaces(t_stract	*mini, char *s)
{
	int		i;

	i = 0;
	if (mini && s && s[i] == ' ')
	{
		while (mini && s && s[i] == ' ')
			i++;
	}
	free(mini->line);
	mini->line = 0;
	mini->line = ft_strjoin(&s[i], "");
}

void	fork_or_parent_start_1(t_stract *mini,
	t_mini_shell *minir_shell, int *_stdin, int *_stdout)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < mini->pipe_number)
	{
		if (dup2(1, *_stdout) < 0)
			printf("minishell : : command not found\n");
		if (dup2(0, *_stdin) < 0)
			printf("minishell : : command not found\n");
		k = fork_or_parent_start(mini, i, minir_shell);
		if (k == 1)
		{
			error_for(i, minir_shell);
			return ;
		}
		else if (k == 2)
			error_for(i, minir_shell);
		if (dup2(*_stdout, 1) < 0)
			printf("minishell : : command not found\n");
		if (dup2(*_stdin, 0) < 0)
			printf("minishell : : command not found\n");
		i++;
	}
}

int	pipe_read_write(t_stract *mini, t_mini_shell *minir_shell)
{
	int	i;
	int	_stdout;
	int	_stdin;

	i = -1;
	_stdout = dup(1);
	_stdin = dup(0);
	while (++i < mini->pipe_number)
	{
		parsing_1(mini, i, minir_shell);
		parsing(mini, i, minir_shell);
	}
	minir_shell[mini->pipe_number - 1].segmenf_error = mini->syntax_error;
	if (func_hirdock(mini, minir_shell) == 1)
	{
		error_for(0, minir_shell);
		return (0);
	}
	if (mini->syntax_error != 0)
		return (0);
	fork_or_parent_start_1(mini, minir_shell, &_stdin, &_stdout);
	wait_close_dup(mini, minir_shell);
	close(_stdout);
	close(_stdin);
	return (1);
}

void	malloc_start(t_stract *mini)
{
	int	i;

	i = 0;
	mini->line_split_pipe = ft_split_line(mini->line, '|');
	mini->forks = malloc(sizeof(pid_t) * mini->pipe_number);
	mini->flag = malloc(sizeof(int) * mini->pipe_number);
	if (mini->pipe_number - 1 > 0)
	{
		mini->end = malloc(sizeof(int *) * (mini->pipe_number - 1));
		if (!mini->end)
		{
			g_status = 1;
			write(2, "Malloc error in mini->end\n", 26);
			exit(1);
		}
	}
	if (!mini->forks)
	{
		g_status = 1;
		write(2, "Malloc error in main\n", 21);
		exit(1);
	}
}
