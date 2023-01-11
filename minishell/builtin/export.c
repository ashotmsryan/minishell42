/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:50:55 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/27 16:19:42 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*env_repl_norm(char *s)
{
	char	*ss;
	int		l;

	ss = ft_strdup0(s);
	l = env_strlen_ps(ss);
	ss[l] = '\0';
	return (ss);
}

int	nnn_if_export(char **splited, t_data2 *data, t_stract *mini)
{
	int	i;
	int	j;	

	i = 0;
	while (splited && splited[++i])
	{
		j = -1;
		while (splited[i][++j])
		{
			if (check_validation_ep(splited[i], "export") == 1)
			{
				return (1);
			}
			if (splited[i][j] == '=')
			{
				add_env(data, splited[i], mini);
				break ;
			}
		}
		add_in_export(data, splited[i], mini);
	}
	return (0);
}

int	if_export(t_mini_shell *minir_shell, int l, t_stract *mini)
{
	int		i;
	t_data2	*data;

	i = -1;
	data = &minir_shell[l].data2;
	i = spllen(minir_shell[l].data.pipe_split);
	if (i >= 2)
	{
		if (nnn_if_export(minir_shell[l].data.pipe_split, data, mini) == 1)
		{
			g_status = 1;
			return (1);
		}
	}
	else
	{
		i = -1;
		while (data->built.ep_data && data->built.ep_data[++i])
			printf("%s\n", data->built.ep_data[i]);
	}
	g_status = 0;
	return (0);
}
