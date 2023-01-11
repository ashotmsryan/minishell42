/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:46:43 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:18:32 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error_norm11(t_stract *mini)
{
	if (mini->syntax_error == 8)
		write(2, "syntax error near unexpected token `<'\n", 39);
	if (mini->syntax_error == 9)
		write(2, "syntax error near unexpected token `''\n", 39);
	if (mini->syntax_error == 10)
		write(2, "syntax error near unexpected token `'''\n", 40);
	if (mini->syntax_error == 11)
		write(2, "syntax error near unexpected token `newline'\n", 45);
	if (mini->syntax_error > 0)
		g_status = 258;
}

void	syntax_error(t_stract *mini)
{
	if (mini->syntax_error == 1)
		write (2, "syntax error near unexpected token `|'\n", 39);
	if (mini->syntax_error == 2)
		write (2, "yntax error near unexpected token `;'\n", 38);
	if (mini->syntax_error == 3)
		write (2, "syntax error near unexpected token `)'\n", 39);
	if (mini->syntax_error == 4)
		write (2, "1syntax error near unexpected token `newline'\n", 46);
	if (mini->syntax_error == 5)
		write (2, "syntax error near unexpected token `>'\n", 39);
	if (mini->syntax_error == 6)
		write(2, "syntax error near unexpected token `>>'\n", 40);
	if (mini->syntax_error == 7)
		write (2, "syntax error near unexpected token `<<'\n", 40);
	syntax_error_norm11(mini);
}

void	set_psyntex_error(char *command,
	t_stract *mini, int i, t_mini_shell *minir_shell)
{
	if (command && (command[ft_strlen(command) - 1] == '>'
			|| command[ft_strlen(command) - 1] == '<'))
	{
		minir_shell[i].error = 3;
		minir_shell[i].segmenf_error = 1;
		minir_shell[i].index_sintex = ft_strlen
			(minir_shell[i].shell_line_split_pipe) - 1;
	}
	if (mini)
	{
		if (mini && (mini->line[ft_strlen(mini->line) - 1] == '>'
				|| mini->line[ft_strlen(mini->line) - 1] == '<'))
		{
			minir_shell[i].error = 3;
			minir_shell[i].segmenf_error = 1;
			minir_shell[i].index_sintex = ft_strlen
				(minir_shell[i].shell_line_split_pipe) - 1;
		}
	}
}

void	syntax_error_search2(char *str,
	t_mini_shell *minir_shell, int j, int k)
{
	if (str[k] && (str[k] == '>' || str[k] == '<'))
	{
		minir_shell->segmenf_error = 1;
		minir_shell->error = 3;
		minir_shell->index_sintex = j - 1;
	}
}

void	syntax_error_search1(char *str,
	t_mini_shell *minir_shell, int j, int k)
{
	if (str[k] && str[k] == '<' && str[k + 1] && str[k + 1] == '>')
	{
		minir_shell->segmenf_error = 1;
		minir_shell->error = 3;
		minir_shell->index_sintex = j - 1;
	}
	if (str[k] && str[k] == '>' && str[k + 1] && str[k + 1] == '<')
	{
		minir_shell->error = 1;
		minir_shell->segmenf_error = 1;
		minir_shell->error = 3;
		minir_shell->index_sintex = j - 1;
	}
}
