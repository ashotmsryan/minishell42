/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:01:13 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/09 22:02:44 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	norm_unset_ep(char *key, char *s1, int len)
{
	int		key_len;
	char	*s2;
	int		i;

	i = -1;
	s2 = ft_strdup0(key);
	while (s2 && s2[++i] && s2[i] != '=')
		;
	s2[i] = '\0';
	key_len = ft_strlen0(s2);
	if (len < key_len)
		len = key_len;
	if (ft_strncmp0(s2, s1, len) == 0)
	{
		free (s1);
		free (s2);
		return (1);
	}
	free(s2);
	free(s1);
	return (0);
}

int	ft_unset_n(t_data2 *data, int j, t_mini_shell *minir_shell, t_stract *mini)
{
	int		len;
	char	*s;

	len = ep_strlen(&data->built.ep_data[j][11]);
	s = dupp(&data->built.ep_data[j][11], len);
	if (norm_unset_ep
		(minir_shell->data.pipe_split[data->index], s, len) == 1)
	{
		unset_ep(data, j, mini);
		return (1);
	}
	return (0);
}
