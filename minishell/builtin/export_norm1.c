/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_norm1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:20:48 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/09 21:25:25 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_and_add(t_data2 *data, char *s, t_stract *mini)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strdup0(s);
	while (tmp && tmp[++i] && tmp[i] != '+')
		;
	tmp[i] = '\0';
	if (norm_find_and_add(tmp, data, s, i) == -1)
		return ;
	adding_export_plus(data, s, i, 0);
	mini->data2.built.ep_data = data->built.ep_data;
	free (tmp);
	tmp = 0;
}

char	*del_plus(char **s, int flag)
{
	char	*plus;
	int		j;
	int		i;

	j = ft_strlen0(*s);
	plus = malloc(j + 1);
	j = -1;
	i = -1;
	while (*s && (*s)[++j])
	{
		if ((*s)[j] == '+' && (*s)[j + 1] && (*s)[j + 1] == '=')
			;
		else
			plus[++i] = (*s)[j];
	}
	plus[i + 1] = '\0';
	if (flag == 1)
		free(*s);
	return (plus);
}

void	add_in_env_plus(t_data2 *data, char *s, t_stract *mini)
{
	int		i;
	char	**tmp;
	char	*plus;

	i = 0;
	tmp = (char **)malloc ((spllen(data->env) + 2) * sizeof(char *));
	while (s && s[i] && s[i] != '=')
		i++;
	i = -1;
	while (data->env && data->env[++i])
		tmp[i] = ft_strdup0(data->env[i]);
	plus = del_plus(&s, 0);
	tmp[i] = ft_strdup0(plus);
	tmp[i + 1] = NULL;
	free(plus);
	free_it(&data->env);
	data->env = tmp;
	mini->env = tmp;
}

void	add_in_env(t_data2 *data, char *s, t_stract *mini)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = ft_strlen0(s);
	tmp = (char **)malloc ((spllen(data->env) + 2) * sizeof(char *));
	while (s && s[i] && s[i] != '=')
		i++;
	if (s && s[i] && i != 0 && s[i] == '=' && s[i - 1] != '+')
	{
		i = -1;
		while (data->env && data->env[++i])
			tmp[i] = ft_strdup0(data->env[i]);
		tmp[i] = ft_strdup0(s);
		tmp[i + 1] = NULL;
		free_it(&data->env);
		data->env = tmp;
		mini->env = tmp;
	}
	else if (s && s[i] && i != 0 && s[i] == '=' && s[i - 1] == '+')
		add_in_env_plus(data, s, mini);
}

int	n_find_same(char *s2, char *s)
{
	int	len;
	int	k;
	int	j;

	len = ep_strlen(s);
	k = 0;
	j = -1;
	while (s2 && s2[++j] && s2[j] != '=')
		k++;
	s2[j] = '\0';
	if (len < k)
		len = k;
	return (len);
}
