/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:41:58 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 04:31:26 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_open_for_input1(int i, t_mini_shell *minir_shell)
{
	if (input_file_have(i, minir_shell) == 0)
	{
		g_status = 1;
		return (0);
	}
	close(minir_shell[i].data.fd_input);
	minir_shell[i].data.fd_input = minir_shell[i].data2.end[0];
	close(minir_shell[i].data2.end[1]);
	return (1);
}

int	file_open_for_input(int i, t_mini_shell *minir_shell)
{
	if ((minir_shell[i].data.flag_for_input == 1
			|| minir_shell[i].data.flag_for_input == 2))
	{
		if (minir_shell[i].data.flag_for_input == 1)
		{
			if (minir_shell[i].data2.end[0])
				close (minir_shell[i].data2.end[0]);
			if (minir_shell[i].data2.end[1])
				close (minir_shell[i].data2.end[1]);
			if (input_file_have(i, minir_shell) == 0)
			{
				g_status = 1;
				return (0);
			}
		}
	}
	if (minir_shell[i].data.flag_for_input == 2)
		if (file_open_for_input1(i, minir_shell) == 0)
			return (0);
	return (1);
}

int	input_file_have_norm(int i, t_mini_shell *minir_shell, int j)
{
	char	*path_file;

	path_file = 0;
	if (minir_shell[i].data.fd_input)
		close(minir_shell[i].data.fd_input);
	minir_shell[i].data.fd_input = open
		(minir_shell[i].data.redirect_input[j] + 1, O_RDONLY);
	if (minir_shell[i].data.fd_input == -1)
	{
		path_file = ft_getcwd(i, minir_shell);
		if (!path_file)
		{
			minir_shell[i].error = 4;
			minir_shell[i].error_char = minir_shell[i].data.redirect_input[j];
			g_status = 1;
			return (0);
		}
		if (path_file && search_path_input_file
			(path_file, i, j, minir_shell) == 0)
			return (0);
	}
	return (1);
}

int	input_file_have(int i, t_mini_shell *minir_shell)
{
	int		j;

	if (minir_shell[i].data.left_index)
	{
		if (minir_shell[i].data.pipe_split && minir_shell[i].data.pipe_split[0])
		{
			if (diyrectory(i, minir_shell) == 0)
			{
				g_status = 1;
				return (0);
			}
		}
		j = 0;
		while (j < minir_shell[i].data.left_index)
		{
			if (input_file_have_norm(i, minir_shell, j) == 0)
				return (0);
			j++;
		}
	}
	return (1);
}

int	search_path_input_file(char *path_file,
	int i, int j, t_mini_shell *minir_shell)
{
	char	*s;
	char	*s1;

	s = 0;
	s = ft_strjoin(path_file, "/");
	s1 = ft_strjoin(s,
			minir_shell[i].data.redirect_input[j] + 1);
	free(s);
	s = 0;
	close(minir_shell[i].data.fd_input);
	minir_shell[i].data.fd_input = open(s1, O_RDONLY);
	free(s1);
	s1 = 0;
	if (minir_shell[i].data.fd_input == -1)
	{
		if (pars_diyrectory(minir_shell[i].data.redirect_input[j] + 1) == 0)
			return (0);
	}
	return (1);
}
