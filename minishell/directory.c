/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:40:47 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/16 01:27:38 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_minishell(char *s)
{
	if (ft_strncmp0(s, "./minishell", 11) == 0)
		return (0);
	if (ft_strncmp0(s, "minishell", 9) == 0)
		return (0);
	return (1);
}

int	if_directory_norm(int i, t_mini_shell *minir_shell, DIR	*pdir)
{
	int	j;

	j = 0;
	if ((pdir && ft_strchr(minir_shell[i].data.pipe_split[0], '/'))
		|| (pdir && is_minishell(minir_shell[i].data.pipe_split[0])))
	{
		g_status = 126;
		write (2, "minishell :", 12);
		write(2, minir_shell[i].data.pipe_split[0],
			ft_strlen(minir_shell[i].data.pipe_split[0]));
		write (2, ": is a directory\n", 17);
		closedir(pdir);
		return (2);
	}
	return (0);
}

int	if_directory(int i, t_mini_shell *minir_shell)
{
	DIR	*pdir;

	pdir = opendir(minir_shell[i].data.pipe_split[0]);
	if (minir_shell[i].data.pipe_split[0]
		&& if_directory_norm(i, minir_shell, pdir) && pdir)
		return (2);
	else if (!pdir && access_func(i, minir_shell, 0))
	{
		if (minir_shell[i].error == 17)
			return (5);
		if (minir_shell[i].error == 16)
			return (0);
		return (1);
	}
	else if (ft_getenv("PATH=", i, minir_shell)
		&& !ft_strchr(minir_shell[i].data.pipe_split[0], '/') && !pdir)
		return (3);
	else if (ft_strchr(minir_shell[i].data.pipe_split[0], '/') && !pdir)
		return (4);
	return (0);
}
