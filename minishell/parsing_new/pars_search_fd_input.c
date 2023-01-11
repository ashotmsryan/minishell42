/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_search_fd_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:55:38 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 01:55:40 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <dirent.h>

int	pars_diyrectory(char *str)
{
	DIR	*pdir;

	pdir = opendir(str);
	if (pdir)
	{
		closedir(pdir);
		return (0);
	}
	return (1);
}

int	pars_search_fd_input_norm(t_mini_shell *minir_shell)
{
	char	**str;

	if (pars_diyrectory
		(minir_shell->data.redirect_input[minir_shell->data.left] + 1)
		== 0)
	{
		g_status = 126;
		str = ft_strjoin_double_point
			(minir_shell->data.pipe_split,
				minir_shell->data.redirect_input[minir_shell->data.left] + 1);
		if (str)
		{
			free(minir_shell->data.pipe_split);
			minir_shell->data.pipe_split = 0;
			minir_shell->data.pipe_split = str;
			str = 0;
		}
		return (0);
	}
	minir_shell->error = 4;
	g_status = 127;
	minir_shell->error_char
		= minir_shell->data.redirect_input[minir_shell->data.left] + 1;
	return (1);
}

int	pars_search_fd_input(t_mini_shell *minir_shell)
{
	minir_shell->data.fd_input = open
		(minir_shell->data.redirect_input[minir_shell->data.left] + 1,
			O_RDONLY);
	if (minir_shell->data.fd_input == -1)
	{
		if (pars_search_fd_input_norm(minir_shell) == 1)
			return (1);
	}
	if (minir_shell->data.flag_for_input == 2
		|| (minir_shell->data.flag_for_input == 1
			&& minir_shell->data.left != minir_shell->data.left_index - 1))
	{
		close(minir_shell->data.fd_input);
	}
	return (0);
}

int	pars_search_fd_output2_norm(char *path_file, t_mini_shell *minir_shell)
{
	char	*s;
	char	*s1;
	int		fd;

	s = 0;
	s = ft_strjoin(path_file, "/");
	s1 = ft_strjoin(s,
			minir_shell->data.boable_redirect_output[minir_shell
			->data.double_right] + 2);
	free(s);
	s = 0;
	fd = open(s1, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(s1);
	s1 = 0;
	if (fd == -1)
	{
		minir_shell->error = 4;
		g_status = 127;
		minir_shell->error_char = minir_shell
			->data.boable_redirect_output[minir_shell->data.double_right] + 2;
		return (1);
	}
	close (fd);
	return (0);
}

void	where_output(t_mini_shell *minir_shell, int flag)
{
	if (flag == 1)
	{
		if (minir_shell->data.flag_for_output == 1
			&& minir_shell->data.right_index - 1 == minir_shell->data.right)
		{
			minir_shell->data.fd_output = open
				(minir_shell->data.redirect_output[minir_shell->data.right] + 1,
					O_WRONLY | O_TRUNC | O_CREAT, 0644);
		}
	}
	if (flag == 2)
	{
		if (minir_shell->data.flag_for_output == 2
			&& minir_shell->data.doubl_right_index - 1
			== minir_shell->data.double_right)
		{
			minir_shell->data.fd_output = open
				(minir_shell->data.boable_redirect_output
				[minir_shell->data.double_right] + 2,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
	}
}
