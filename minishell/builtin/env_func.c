/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:37:17 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 06:50:30 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_ep_env(t_mini_shell *minir_shell,
		char *change, char *search_text)
{
	int		j;
	char	*ch;
	char	*se;

	j = -1;
	ch = ft_strdup(change);
	se = ft_strdup(search_text);
	while (minir_shell->data2.built.ep_data[++j])
	{
		if (ft_strncmp0(se, &minir_shell->data2.built.ep_data[j][11],
			ft_strlen0(se) - 1) == 0)
		{
			free(minir_shell->data2.built.ep_data[j]);
			minir_shell->data2.built.ep_data[j] = 0;
			se = ft_strjoin0(se, ch);
			minir_shell->data2.built.ep_data[j] = ep_strdup(se);
		}
	}
	free(ch);
	free(se);
}

void	env_change(t_stract *mini, char *search_text,
	char *change, t_mini_shell *minir_shell)
{
	int		k;
	int		j;
	char	**new_env;

	change_ep_env(minir_shell, change, search_text);
	k = env_change_norm(minir_shell, change, search_text);
	if (k == -1)
		return ;
	free(minir_shell->env[k]);
	new_env = (char **)malloc(sizeof(char *) * (k + 2));
	j = 0;
	while (j < k)
	{
		new_env[j] = minir_shell->env[j];
		j++;
	}
	new_env[j++] = ft_strjoin(search_text, change);
	new_env[j] = NULL;
	free(minir_shell->env);
	minir_shell->env = new_env;
	mini->env = new_env;
	evry(mini, minir_shell);
}

void	env_func(int i, t_mini_shell *minir_shell)
{
	int	j;

	j = 0;
	if (minir_shell[i].env)
	{
		while (minir_shell[i].env[j])
			printf("%s\n", minir_shell[i].env[j++]);
		g_status = 0;
	}
	else
	{
		write(2, "minishell: env: No such file or directory\n", 42);
		g_status = 1;
	}
}

char	**env_new(char **env)
{
	int		i;
	int		flag;
	char	**env_new;

	flag = 0;
	i = 0;
	while (env && env[i])
		i++;
	env_new = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env && env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7))
		{
			env_new[i - flag] = ft_strjoin(env[i], "");
		}
		else
			flag++;
	}
	env_new[i - flag] = NULL;
	return (env_new);
}

void	print_env_heve(int j, int i, int i_flag, t_mini_shell *minir_shell)
{
	char	*s;
	char	*str;
	int		k;

	k = 0;
	s = ft_str_n_dup(&(minir_shell[i_flag].data.pipe_split[j][i]),
			minir_shell[i_flag].data.x);
	str = getenv(s);
	if (str && *str)
	{
		while (str[k] != '\0')
			write(1, &str[k++], 1);
	}
	free(s);
}
