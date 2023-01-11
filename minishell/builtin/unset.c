/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:22:08 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/01 02:59:46 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*dupp(char *s, int len)
{
	int		i;
	char	*ret;

	i = -1;
	ret = malloc (len + 1);
	while (s && s[++i] && i < len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

void	unset_ep(t_data2 *data, int place, t_stract *mini)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = -1;
	tmp = (char **)malloc(sizeof(char *) * spllen(data->built.ep_data) + 1);
	while (data->built.ep_data && data->built.ep_data[++i])
	{
		if (i == place)
			i++;
		tmp[++j] = ft_strdup0(data->built.ep_data[i]);
		if (!tmp[j])
			break ;
	}
	if (tmp[j])
		tmp[++j] = NULL;
	free_it(&data->built.ep_data);
	data->built.ep_data = tmp;
	mini->data2.built.ep_data = tmp;
}

static void	unsetting_env(t_data2 *data, int place, t_stract *mini)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = -1;
	tmp = (char **)malloc(sizeof(char *) * spllen(data->env));
	while (data->env && data->env[++i])
	{
		if (i == place)
			i++;
		tmp[++j] = ft_strdup0(data->env[i]);
		if (!tmp[j])
			break ;
	}
	if (tmp[j])
		tmp[++j] = NULL;
	free_it(&data->env);
	mini->env = tmp;
	data->env = tmp;
}

static void	unset_env(t_data2 *data, char *key, int key_len, t_stract *mini)
{
	int		i;
	char	*s;
	int		len;

	i = -1;
	while (data->env && data->env[++i])
	{
		len = ep_strlen(data->env[i]);
		s = dupp(data->env[i], len);
		if (len < key_len)
			len = key_len;
		if (ft_strncmp0(key, s, len) == 0)
		{
			unsetting_env(data, i, mini);
			free (s);
			break ;
		}
		free (s);
	}
}

void	ft_unset(int i, t_mini_shell *minir_shell, t_stract *mini)
{
	int		j;
	int		key_len;
	t_data2	*data;

	data = &minir_shell[i].data2;
	j = -1;
	data->index = 0;
	while (minir_shell[i].data.pipe_split[++data->index] && check_validation_ep
		(minir_shell[i].data.pipe_split[data->index], "unset") == 0)
	{
		j = -1;
		key_len = ft_strlen0(minir_shell[i].data.pipe_split[data->index]);
		while (data->built.ep_data[++j])
			if (ft_unset_n(data, j, &minir_shell[i], mini))
				break ;
		unset_env(data, minir_shell[i].data.pipe_split[data->index],
			key_len, mini);
		g_status = 0;
	}
}
