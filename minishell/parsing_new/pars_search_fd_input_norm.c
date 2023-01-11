/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_search_fd_input_norm.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:56:11 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 01:56:13 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	p_s_fd_o2_2_norm(t_mini_shell *minir_shell)
{
	minir_shell->error = 4;
	minir_shell->error_char = minir_shell->data.boable_redirect_output
	[minir_shell
		->data.double_right] + 2;
}

int	p_s_fd_o2_2(t_mini_shell *minir_shell, char *path_file)
{
	int		fd;

	path_file = 0;
	fd = open
		(minir_shell->data.boable_redirect_output[minir_shell
			->data.double_right] + 2, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		print_error_prmishn(strerror(errno),
			minir_shell->data.boable_redirect_output[minir_shell
			->data.double_right] + 2);
		g_status = 1;
		return (1);
	}
	close(fd);
	return (0);
}

int	pars_search_fd_output2(t_mini_shell *minir_shell)
{
	char	*path_file;

	path_file = 0;
	if (ft_strchr(minir_shell->data.boable_redirect_output
			[minir_shell->data.double_right] + 2, '/') != 0)
	{
		if (pars_diyrectory(minir_shell->data.boable_redirect_output
				[minir_shell->data.double_right] + 2) == 0)
		{
			minir_shell->error = 126;
			minir_shell->error_char = minir_shell->data.boable_redirect_output
			[minir_shell->data.double_right] + 2;
			return (1);
		}
	}
	if (p_s_fd_o2_2(minir_shell, path_file) == 1)
		return (1);
	where_output(minir_shell, 2);
	return (0);
}
