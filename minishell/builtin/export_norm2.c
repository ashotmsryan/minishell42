/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_norm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:25:32 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 06:36:54 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	nnn_find_same(char *s, char *s1, char **tmp, int len)
{
	int		i;
	char	*s2;

	i = -1;
	s2 = NULL;
	while (s1[++i] != '=')
		;
	s1[i] = '\0';
	i = -1;
	while (tmp && tmp[++i])
	{
		s2 = ft_strdup0(&tmp[i][11]);
		len = n_find_same(s2, s);
		if (tmp[i] && (ft_strncmp0(s2, s1, len) == 0))
		{
			free(s2);
			return (1);
		}
		free (s2);
	}
	return (0);
}

int	nn_find_same(char **tmp, char *s, int len)
{
	int		j;
	int		i;
	int		l;
	char	*s2;

	i = -1;
	while (tmp && tmp[++i])
	{
		l = -1;
		s2 = ft_strdup0(tmp[i]);
		nn_find_same_norm1(s2, &l);
		j = ep_strlen(s2) - 11;
		if (len < j)
			len = j;
		if (s2 && (ft_strncmp0(&s2[11], s, len) == 0))
		{
			free(s2);
			s2 = 0;
			return (1);
		}
		free(s2);
		s2 = 0;
	}
	return (0);
}

int	find_same(char **tmp, char *s, int flag)
{
	int		len;
	char	*s1;

	s1 = ft_strdup0(s);
	len = ep_strlen(s);
	if (flag == 0)
	{
		if (nn_find_same(tmp, s1, len) == 1)
		{
			free (s1);
			return (1);
		}
	}
	else if (flag == 1)
	{
		if (nnn_find_same(s, s1, tmp, len) == 1)
		{
			free (s1);
			return (1);
		}
	}
	free (s1);
	return (0);
}

char	**norm_find_and_replace(t_data2 *data, char *s1, int len, char *s)
{
	char	*s2;
	int		j;
	int		k;
	char	**tmp;

	j = -1;
	tmp = (char **)malloc((spllen(data->built.ep_data) + 1) * sizeof(char *));
	while (data->built.ep_data && data->built.ep_data[++j])
	{
		k = -1;
		s2 = ft_strdup0(&data->built.ep_data[j][11]);
		while (s && s2[++k] && s2[k] != '=')
			;
		s2[k] = '\0';
		if (ft_strlen0(s2) > len)
			len = ft_strlen0(s2);
		if (ft_strncmp0(s2, s1, len) == 0)
			tmp[j] = ep_strdup(s);
		else
			tmp[j] = ft_strdup0(data->built.ep_data[j]);
		free(s2);
		s2 = 0;
	}
	tmp[j] = NULL;
	return (tmp);
}

void	find_and_replace(t_data2 *data, char *s, t_stract *mini)
{
	int		j;
	int		len;
	char	**tmp;
	char	*s1;

	j = -1;
	s1 = ft_strdup0(s);
	while (s1 && s1[++j] && s1[j] != '=')
		;
	s1[j] = '\0';
	len = ft_strlen0(s1);
	tmp = norm_find_and_replace(data, s1, len, s);
	free(s1);
	s1 = 0;
	free_it(&data->built.ep_data);
	data->built.ep_data = tmp;
	mini->data2.built.ep_data = tmp;
}
