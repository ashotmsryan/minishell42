/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:17:23 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/09 21:20:34 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	nnnn_adding_export_plus(t_data2 *data, char *s, char **ptr, int k)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (s && s[++j] && s[j] != '=')
		;
	while (*ptr && (*ptr)[++i])
		data->built.ep_data[k][i] = (*ptr)[i];
	while (s && s[++j])
	{
		data->built.ep_data[k][i] = s[j];
		i++;
	}
	data->built.ep_data[k][i] = '\"';
	data->built.ep_data[k][i + 1] = '\0';
	free (*ptr);
	*ptr = 0;
}

void	nn_adding_export_plus(t_data2 *data, char *s, int k, int i)
{
	int		l;
	char	*ptr;
	int		j;

	l = 0;
	j = -1;
	ptr = data->built.ep_data[k];
	while (data->built.ep_data[k][++i])
		;
	data->built.ep_data[k][i - 1] = '\0';
	while (s[++j] != '=')
		;
	while (s[++j] != '\0')
		l++;
	data->built.ep_data[k] = malloc((i - 1) + l + 3);
	nnnn_adding_export_plus(data, s, &ptr, k);
}

void	adding_export_plus(t_data2 *data, char *s, int k, int flag)
{
	char	**tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (flag == 0)
	{
		tmp = data->built.ep_data;
		data->built.ep_data = (char **)malloc((spllen(data->built.ep_data)
					+ 2) * sizeof(char *));
		while (tmp[++j])
			data->built.ep_data[j] = ft_strdup0(tmp[j]);
		data->built.ep_data[j] = ep_strdup(s);
		data->built.ep_data[j + 1] = (char *)malloc(sizeof(char));
		data->built.ep_data[j + 1] = NULL;
		free_it(&tmp);
		tmp = 0;
	}
	else if (flag == 1)
		nn_adding_export_plus(data, s, k, i);
}

char	*nnorm_find_and_add(char *s, char *dup)
{
	int	i;

	i = -1;
	dup = ft_strdup0(s);
	while (dup && dup[++i] && dup[i] != '=')
		;
	dup[i] = '\0';
	return (dup);
}

int	norm_find_and_add(char *tmp, t_data2 *data, char *s, int j)
{
	char	*dup;
	int		len;
	int		i;

	i = -1;
	while (data->built.ep_data && data->built.ep_data[++i])
	{
		dup = nnorm_find_and_add(&data->built.ep_data[i][11], dup);
		len = ft_strlen0(dup);
		if (len > j)
			j = len;
		if (data->built.ep_data[i] && (ft_strncmp0(tmp, dup, j) == 0))
		{
			adding_export_plus(data, s, i, 1);
			free (tmp);
			tmp = 0;
			free(dup);
			dup = 0;
			return (-1);
		}
		free (dup);
	}
	return (i);
}
