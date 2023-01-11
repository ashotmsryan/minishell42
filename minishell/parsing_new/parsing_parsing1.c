/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parsing1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:54:21 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/21 17:26:18 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	flag( int i, t_mini_shell *minir_shell)
{
	if (minir_shell[i].data.pipe_split
		&& minir_shell[i].data.pipe_split[0])
	{
		if (ft_strncmp(minir_shell[i].data.pipe_split[0], "env", 3) == 0)
			minir_shell[i].flag = 1;
		else if (ft_strncmp(minir_shell[i].data.pipe_split[0], "cd", 2) == 0)
			minir_shell[i].flag = 1;
		else if (ft_strncmp(minir_shell[i].data.pipe_split[0], "pwd", 3) == 0)
			minir_shell[i].flag = 1;
		else if (ft_strncmp(minir_shell[i].data.pipe_split[0], "echo", 4) == 0)
			minir_shell[i].flag = 1;
		else if (ft_strncmp(minir_shell[i].data.pipe_split[0], "exit", 4) == 0)
			minir_shell[i].flag = 1;
		else if (ft_strncmp
			(minir_shell[i].data.pipe_split[0], "export", 6) == 0)
			minir_shell[i].flag = 1;
		else if (ft_strncmp(minir_shell[i].data.pipe_split[0], "unset", 5) == 0)
			minir_shell[i].flag = 1;
	}
}

void	parsing(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	int		j;
	char	**command;

	j = *mini->flag;
	command = 0;
	command = ft_split_line1(minir_shell[i].shell_line_split_pipe, ' ');
	minir_shell[i].command = ft_strdupdoub(command);
	parsing_new_r_for_herdoc(i, minir_shell);
	pars_unset_qouts_herdoc(i, minir_shell);
	free_it(&command);
	free_it(&minir_shell[i].command);
	command = 0;
	minir_shell[i].command = 0;
	new_pars_dolar_s(i, minir_shell);
	command = ft_split_line1(minir_shell[i].shell_line_split_pipe, ' ');
	minir_shell[i].command = ft_strdupdoub(command);
	parsing_new_r(i, minir_shell);
	pars_unset_quots_data_pipe_split(i, minir_shell);
	pars_unset_quots_data_redirect_output(i, minir_shell);
	pars_unset_quots_data_redirect_input(i, minir_shell);
	pars_unset_quots_data_redirect_boable_redirect_output(i, minir_shell);
	free_it(&command);
	flag(i, minir_shell);
}

void	parsing_1(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	char	*line_split_pipe;

	line_split_pipe = 0;
	line_split_pipe = spease_set_unset(minir_shell[i].shell_line_split_pipe,
			mini, minir_shell, i);
	if (line_split_pipe)
	{
			minir_shell[i].shell_line_split_pipe_old = mini->line_split_pipe[i];
			minir_shell[i].shell_line_split_pipe = line_split_pipe;
			minir_shell[i].shell_for_herdoc = ft_strdup(line_split_pipe);
			mini->line_split_pipe[i] = line_split_pipe;
	}
}
