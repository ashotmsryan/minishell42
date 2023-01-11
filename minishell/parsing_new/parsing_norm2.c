/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:52:44 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 03:52:46 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing_norm1(int i,
	t_mini_shell *minir_shell, char **command, int *j)
{
	int	m;
	int	n;

	m = -1;
	n = -1;
	while (command[++m])
		;
	minir_shell[i].flag_quote = malloc(sizeof(int) * m);
	while (++n != m)
			minir_shell[i].flag_quote[n] = 0;
	if (!command || !minir_shell[i].flag_quote)
	{
		printf("malloc for command ERROR\n");
		return (1);
	}
	else
	{
		while (command[*j])
		{
			command[*j] = set_dolar_question_mark
				(command[*j], minir_shell, i, *j);
			(*j)++;
		}
	}
	return (0);
}

int	parsing_for_norm(int i, t_mini_shell *minir_shell, int *len, char **command)
{
	int		j;
	char	*str;

	j = 0;
	str = 0;
	if (parsing_norm1(i, minir_shell, command, &j) == 1)
		return (1);
	*len = j;
	j = -1;
	free(minir_shell[i].shell_line_split_pipe);
	minir_shell[i].shell_line_split_pipe = NULL;
	while (++j < *len)
	{
		str = ft_strjoin2
			(minir_shell[i].shell_line_split_pipe, command[j]);
		if (str)
		{
			free(minir_shell[i].shell_line_split_pipe);
			minir_shell[i].shell_line_split_pipe = str;
			str = 0;
		}
	}
	return (0);
}
