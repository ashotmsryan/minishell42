/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:24:12 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 05:47:29 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status;

void	main1(t_stract	*mini, t_mini_shell	**mini_shell)
{
	if (mini->line && mini->line[0])
	{
		mini->pipe_number = l_nlen(mini->line, '|');
		if (mini->pipe_number)
		*mini_shell = malloc(sizeof(t_mini_shell) * mini->pipe_number);
		write_null_minishell(*mini_shell, mini->pipe_number);
		start_minishell(mini, *mini_shell);
	}
}

void	main_norm(t_stract *mini,
	t_mini_shell **mini_shell, struct termios *def)
{
	char	*s;

	for_update_free(mini, mini_shell);
	if (tcsetattr(0, TCSANOW, def) < 0)
		printf("minishell: signal_error2\n");
	s = 0;
	s = readline("minishell $ ");
	if (s == NULL)
	{
		printf("exit\n");
		exit (0);
	}
	is_len_delet_spaces(mini, s);
	free(s);
	s = 0;
	if (mini->line[0])
		add_history(mini->line);
	if (syntax_error_search(mini) == 0)
		main1(mini, mini_shell);
}

void	free_all_78(t_stract **mini, t_mini_shell **mini_shell)
{
	int	i;

	i = -1;
	if (mini && *mini && (*mini)->pipe_number > 1)
	{
		while (++i < (*mini)->pipe_number)
		{
			close((*mini_shell)[i].data.fd_input);
			close((*mini_shell)[i].data.fd_output);
			close((*mini)->end[i][0]);
			close((*mini)->end[i][1]);
		}
	}
	memory_free_mini(*mini);
	if (*mini_shell)
	{
		memory_free_t_mini_shell(*mini_shell);
		free(*mini_shell);
	}
	free(*mini);
}

int	main(int argc, char *argv[], char **env)
{
	struct termios	def;
	t_stract		*mini;
	t_mini_shell	*mini_shell;
	int				lvl;

	if (tcgetattr(0, &def) < 0)
		perror("minishell: signal_error1");
	(void)argc;
	(void)argv;
	lvl = 0;
	rl_catch_signals = 0;
	mini = (t_stract *)malloc(sizeof(t_stract));
	func_null(mini, env);
	mini_shell = 0;
	g_status = 0;
	get_shlvl(mini, lvl);
	get_export(mini);
	while (1)
	{
		signal_call(1);
		main_norm(mini, &mini_shell, &def);
		syntax_error(mini);
	}
	free_all_78(&mini, &mini_shell);
	return (0);
}
