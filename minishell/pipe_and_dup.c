/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_and_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:25:14 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 05:35:38 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	output_dup(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	if (mini->pipe_number > 1 && minir_shell[i].end
		&& i != mini->pipe_number - 1
		&& minir_shell[i].data.flag_for_output == 0)
	{
		if (dup2(minir_shell[i].end[i][1], 1) < 0)
		{
			write (2, "minishell :", 12);
			write (2, "DUP Error\n", 10);
			exit(1);
		}
	}
	else if (minir_shell[i].data.flag_for_output == 1
		|| minir_shell[i].data.flag_for_output == 2)
	{
		if (dup2(minir_shell[i].data.fd_output, 1) < 0)
		{
			write (2, "minishell :", 12);
			write (2, "DUP Error\n", 10);
			exit(1);
		}
		close(minir_shell[i].data.fd_output);
	}
}

void	input_dup(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	if (minir_shell[i].data.flag_for_input == 1
		|| minir_shell[i].data.flag_for_input == 2)
	{
		if (dup2(minir_shell[i].data.fd_input, 0) < 0)
		{
			mini->error = 88;
			minir_shell[i].error = 88;
			write (2, "minishell :", 12);
			write (2, "DUP Error\n", 10);
		}
		close(minir_shell[i].data.fd_input);
	}
	else if (mini->pipe_number > 1 && minir_shell[i].end
		&& i != 0 && minir_shell[i].data.flag_for_input == 0)
	{
		if (dup2(minir_shell[i].end[i - 1][0], 0) < 0)
		{
			mini->error = 88;
			minir_shell[i].error = 88;
			write (2, "minishell :", 12);
			write (2, "DUP Error\n", 10);
		}
	}
}

void	pipe_and_dup(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	int		k;

	input_dup(mini, i, minir_shell);
	output_dup(mini, i, minir_shell);
	k = 0;
	while (k < mini->pipe_number - 1)
	{
		close(minir_shell[i].end[k][1]);
		close(minir_shell[i].end[k][0]);
		k++;
	}
}
