/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_accsess_file_norm.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:44:00 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/16 01:34:03 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_call_acc_norm(int i, t_mini_shell *minir_shell, int x)
{
	if (x == 4)
	{
		minir_shell[i].data.that_cammand_number = 14;
		minir_shell[i].error_char_id = open
			(minir_shell[i].data.pipe_split[0], O_RDWR);
		minir_shell[i].error = 4;
	}
	else if (x == 5)
		minir_shell[i].data.that_cammand_number = 17;
}

void	func_call_accsess(int i, t_mini_shell *minir_shell)
{
	int	x;

	x = if_directory(i, minir_shell);
	if (x == 1)
	{
		minir_shell[i].data.that_cammand_number = 12;
	}
	else if (x == 2)
	{
		minir_shell[i].data.that_cammand_number = 13;
		minir_shell[i].error_char = minir_shell[i].data.pipe_split[0];
	}
	else if (x == 3)
	{
		minir_shell[i].data.that_cammand_number = 15;
	}
	else if (x == 4 || x == 5)
		func_call_acc_norm(i, minir_shell, x);
	else
	{
		minir_shell[i].data.that_cammand_number = 16;
		minir_shell[i].error = 16;
		minir_shell[i].error_char = minir_shell[i].data.pipe_split[0];
	}
}

int	access_func_norm1(int i, t_mini_shell *minir_shell)
{
	if (access(minir_shell[i].data.pipe_split[0], X_OK & F_OK) != -1)
	{
		minir_shell[i].verified_path = minir_shell[i].data.pipe_split[0];
		if (!ft_getenv("PATH=", i, minir_shell))
		{
			minir_shell[i].error = 17;
			minir_shell[i].error_char = minir_shell[i].data.pipe_split[0];
			return (2);
		}
		if (!ft_strchr(minir_shell[i].data.pipe_split[0], '/'))
			return (0);
		return (1);
	}
	return (0);
}

int	access_func_norm3(int i, t_mini_shell *minir_shell, char **path_bin_all)
{
	if (access(*path_bin_all, X_OK & F_OK) != -1)
	{
		minir_shell[i].verified_path = *path_bin_all;
		if (!ft_getenv("PATH=", i, minir_shell))
		{
			minir_shell[i].error = 16;
			minir_shell[i].error_char = minir_shell[i].data.pipe_split[0];
			return (2);
		}
		return (1);
	}
	return (0);
}

int	access_func(int i, t_mini_shell *minir_shell, int j)
{
	char	*path_bin;
	char	*path_bin_all;
	int		u;

	u = 0;
	while (minir_shell[i].path_split[j])
	{
		path_bin = ft_strjoin(minir_shell[i].path_split[j], "/");
		path_bin_all = ft_strjoin(path_bin, minir_shell[i].data.pipe_split[0]);
		free(path_bin);
		u = access_func_norm3(i, minir_shell, &path_bin_all);
		if (u)
			return (u);
		free(path_bin_all);
		j++;
	}
	u = 0;
	u = access_func_norm1(i, minir_shell);
	if (u)
		return (u);
	return (0);
}
