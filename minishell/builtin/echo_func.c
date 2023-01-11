/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:37:04 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:37:07 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo_all_n(char	*str)
{
	int	i;

	i = 0;
	if (ft_strncmp1(str, "-n", 3) == 0)
		return (1);
	else
	{
		if (str[i] == '-' && str[i + 1] && str[i + 1] == 'n')
			i++;
		else
			return (0);
		while (str && str[i] && str[i] == 'n')
			i++;
		if (!str[i])
			return (1);
	}
	return (0);
}

void	echo_func_norm(int i, t_mini_shell *minir_shell, int j)
{
	int	k;

	while (minir_shell[i].data.pipe_split && minir_shell[i].data.pipe_split[j])
	{
		k = 0;
		while (minir_shell[i].data.pipe_split
			&& minir_shell[i].data.pipe_split[j]
			&& minir_shell[i].data.pipe_split[j][k] != '\0')
		{
			write(1, &minir_shell[i].data.pipe_split[j][k], 1);
			if (minir_shell[i].data.pipe_split[j][k])
				k++;
		}
		j++;
		if (minir_shell[i].data.pipe_split[j])
			write(1, " ", 1);
	}
}

void	echo_func(int i, t_mini_shell *minir_shell)
{
	char	new_line;
	int		j;

	j = 1;
	new_line = 0;
	if (minir_shell[i].data.pipe_split && minir_shell[i].data.pipe_split[1]
		&& echo_all_n(minir_shell[i].data.pipe_split[1]))
	{
		new_line = 1;
		j++;
	}
	echo_func_norm(i, minir_shell, j);
	if (new_line == 0)
		printf("\n");
	g_status = 0;
}
