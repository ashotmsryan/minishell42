/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_search_fd_output1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:07:15 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 02:07:18 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pars_search_fd_output1_norm(char *path_file, t_mini_shell *minir_shell)
{
	char	*s;
	char	*s1;
	int		fd;

	s = 0;
	s = ft_strjoin(path_file, "/");
	s1 = ft_strjoin(s,
			minir_shell->data.redirect_output[minir_shell->data.right] + 1);
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
			->data.redirect_output[minir_shell->data.right] + 1;
		return (1);
	}
	close(fd);
	return (0);
}

int	p_s_fd_output1(t_mini_shell *minir_shell, int *fd)
{
	char	*path_file;
	char	buf[256];

	if (*fd == -1)
	{
		path_file = getcwd(buf, sizeof(buf));
		if (path_file != NULL)
		{
			if (path_file && pars_search_fd_output1_norm
				(path_file, minir_shell) == 0)
				return (1);
		}
		else if (ft_strchr(minir_shell->data.redirect_output
				[minir_shell->data.right] + 1, '/'))
		{
			minir_shell->error = 4;
			minir_shell->error_char = minir_shell->data.redirect_output
			[minir_shell->data.right] + 1;
			return (1);
		}
	}
	close(*fd);
	return (0);
}

void	print_error_prmishn(char *str, char *err)
{
	write(2, "minishell: ", 11);
	write(2, err, ft_strlen(err));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	pars_sr_fd_output(t_mini_shell *minir_shell)
{
	int	fd;

	fd = open
		(minir_shell->data.redirect_output[minir_shell->data.right] + 1,
			O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		print_error_prmishn(strerror(errno),
			(minir_shell->data.redirect_output[minir_shell->data.right] + 1));
		g_status = 1;
		return (1);
	}
	close(fd);
	where_output(minir_shell, 1);
	return (0);
}

int	pars_search_fd_output1(t_mini_shell *minir_shell)
{
	char	*path_file;

	path_file = 0;
	if (ft_strchr(minir_shell->data.redirect_output[minir_shell
				->data.right] + 1, '/') != 0)
	{
		if (pars_diyrectory(minir_shell->data.redirect_output
				[minir_shell->data.right] + 1) == 0)
		{	
			minir_shell->error = 126;
			minir_shell->error_char = minir_shell->data.redirect_output
			[minir_shell->data.right] + 1;
			g_status = 1;
			return (1);
		}
	}
	if (pars_sr_fd_output(minir_shell))
		return (1);
	return (0);
}
