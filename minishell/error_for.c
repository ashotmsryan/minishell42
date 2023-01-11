/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:41:00 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/16 00:12:08 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	premis_error(int i, t_mini_shell *minir_shell)
{
	if (minir_shell && minir_shell[i].error == 17)
	{
		g_status = 127;
		write (2, "minishell :", 12);
		write (2, minir_shell[i].error_char,
			ft_strlen(minir_shell[i].error_char));
		write (2, ": Permission denied\n", 20);
	}
}

void	error_for1_2_norm(int i, t_mini_shell *minir_shell)
{
	if (minir_shell && minir_shell[i].error == 15)
	{
		g_status = 127;
		write (2, "minishell :", 12);
		write (2, minir_shell[i].error_char,
			ft_strlen(minir_shell[i].error_char));
		write (2, ": command not found\n", 20);
	}
	if (minir_shell && minir_shell[i].error == 8)
	{
		g_status = 127;
		write (2, "minishell:", 13);
		write (2, minir_shell[i].verified_path,
			ft_strlen(minir_shell[i].verified_path));
		write (2, ": command not found\n", 20);
	}
	if (minir_shell && minir_shell[i].error == 16)
	{
		g_status = 127;
		write (2, "minishell :", 12);
		write (2, minir_shell[i].error_char,
			ft_strlen(minir_shell[i].error_char));
		write (2, ": No such file or directory\n", 28);
	}
	premis_error(i, minir_shell);
}

void	error_for1(int i, t_mini_shell *minir_shell)
{
	if (minir_shell && minir_shell[i].error == 5)
	{
		g_status = 258;
		write (2, "syntax error near unexpected token ` '' \n", 43);
	}
	if (minir_shell && minir_shell[i].error == 6)
	{
		g_status = 258;
		write (2, "syntax error near unexpected token ` ", 40);
		write (2, &minir_shell[i].shell_line_split_pipe_old
		[minir_shell[i].index_sintex], 1);
		write (2, "\n", 1);
	}
	if (minir_shell && minir_shell[i].error == 13)
	{
		g_status = 127;
		write (2, "minishell :", 12);
		write (2, minir_shell[i].error_char,
			ft_strlen(minir_shell[i].error_char));
		write (2, ": No such file or directory\n", 28);
	}
	error_for1_2_norm(i, minir_shell);
}

void	error_norm_asd1(int i, t_mini_shell *minir_shell)
{
	g_status = 126;
	write (2, "minishell :", 13);
	write (2, minir_shell[i].error_char,
		ft_strlen(minir_shell[i].error_char));
	write (2, ": is a directory\n", 17);
}

void	error_for(int i, t_mini_shell *minir_shell)
{
	if (minir_shell && minir_shell[i].error == 1)
	{
		g_status = 258;
		write(2, "syntax error near unexpected token `newline\n", 47);
	}
	if (minir_shell && minir_shell[i].error == 2)
		g_status = 258;
	if (minir_shell && minir_shell[i].error == 3)
		g_status = 258;
	if (minir_shell && minir_shell[i].error == 4)
	{
		g_status = 127;
		write (2, "minishell :", 12);
		perror(minir_shell[i].error_char);
	}
	if (minir_shell[i].error == 126)
		error_norm_asd1(i, minir_shell);
	error_for1(i, minir_shell);
}
