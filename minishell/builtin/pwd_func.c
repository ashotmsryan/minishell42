/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:37:49 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:37:52 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getcwd(int i, t_mini_shell *minir_shell)
{
	char	*pwd;

	pwd = ft_getenv("PWD=", i, minir_shell);
	return (pwd);
}

void	pwd_func(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	if (minir_shell[i].data.pipe_split[1]
		&& minir_shell[i].data.pipe_split[1][0] == '-'
		&& minir_shell[i].data.pipe_split[1][1])
	{
		write(2, "minishell: pwd: -", 17);
		write(2, &minir_shell[i].data.pipe_split[1][1], 1);
		write(2, ": invalid option\n", 17);
		write(2, "pwd: usage: pwd [-LP]\n", 22);
		g_status = 1;
	}
	else
	{
		minir_shell[i].pwd_current = ft_getcwd(i, minir_shell);
		minir_shell[i].pwd_util = minir_shell[i].pwd_current;
		if (mini->flag_write == 0)
		{
			printf("%s\n", minir_shell[i].pwd_current);
		}
		minir_shell[i].pwd_current = 0;
		g_status = 0;
	}
}
