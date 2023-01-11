/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_norm4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:30:32 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/16 23:12:20 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_validation_ep(char *splited, char *cmd)
{
	int	j;

	j = -1;
	if (splited && splited[0] && (splited[0] == '=' || splited[0] == ' '))
	{
		printf("minishell: %s: `%s': not a valid identifier\n", cmd,
			splited);
		g_status = 1;
		return (1);
	}
	while (splited && splited[++j] && splited[j] != '=')
	{
		if (nnn_check_validation(splited, j, cmd) == 1)
		{
			g_status = 1;
			return (1);
		}
	}
	return (0);
}

char	**env_replace(t_data2 *data, char **tmp, char *s)
{
	int		j;
	int		len;
	char	*s1;
	int		l;
	char	*s2;

	j = -1;
	s2 = env_repl_norm(s);
	len = env_strlen_ps(s2);
	while (data->env && data->env[++j])
	{
		s1 = env_repl_norm(data->env[j]);
		l = env_strlen_ps(s1);
		if (len < l)
			len = l;
		if (data->env[j]
			&& (ft_strncmp0(s1, s2, len)) == 0)
			tmp[j] = ft_strdup(s);
		else
			tmp[j] = ft_strdup0(data->env[j]);
		free(s1);
	}
	free(s2);
	tmp[j] = NULL;
	return (tmp);
}

int	find_same_env(char **tmp, char *s)
{
	int		len;
	int		i;
	char	*s1;
	char	*s2;

	s1 = del_plus(&s, 0);
	i = -1;
	while (s1[++i] != '=')
		;
	s1[i] = '\0';
	i = -1;
	while (tmp && tmp[++i])
	{
		s2 = ft_strdup0(tmp[i]);
		len = n_find_same(s2, s1);
		if (tmp[i] && (ft_strncmp0(s2, s1, len) == 0))
		{
			free(s2);
			free(s1);
			return (1);
		}
		free (s2);
	}
	free (s1);
	return (0);
}

void	norm_plus_env(char *s, t_data2 *data, t_stract *mini, int i)
{
	char	**tmp;
	int		j;
	char	*a;

	j = -1;
	a = ft_strdup0(ft_strchr0(s, '='));
	tmp = (char **)malloc((spllen(data->env) + 1) * sizeof(char *));
	while (data->env && data->env[++j])
	{
		if (j != i)
			tmp[j] = ft_strdup0(data->env[j]);
		else
		{
			tmp[j] = ft_strdup0(data->env[j]);
			tmp[j] = ft_strjoin0(tmp[j], &a[1]);
		}
	}
	tmp[j] = NULL;
	free_it(&data->env);
	free(a);
	data->env = tmp;
	mini->env = tmp;
}

void	add_env(t_data2 *data, char *s, t_stract *mini)
{
	int		flag;
	char	**tmp;

	flag = 0;
	while (s && s[flag] && s[flag] != '+')
		flag++;
	if (s[flag] == '+')
		flag = -1;
	if (find_same_env(data->env, s) == 1 && flag != -1)
	{
		tmp = (char **)malloc((spllen(data->env) + 1) * sizeof(char *));
		tmp = env_replace(data, tmp, s);
		free_it(&data->env);
		data->env = tmp;
		mini->env = tmp;
	}
	else if (find_same_env(data->env, s) == 1 && flag == -1)
		norm_plus_env(s, data, mini, find_dbl(data->env, s, 1));
	else if (find_same_env(data->env, s) == 0)
		add_in_env(data, s, mini);
}
