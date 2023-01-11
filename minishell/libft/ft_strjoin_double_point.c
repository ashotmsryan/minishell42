/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_double_point.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:25:18 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/09 17:24:09 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**norm_strjoin_double(char **new_split, char **split, char *str)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		new_split[i] = ft_strdup(split[i]);
		free(split[i]);
		split[i] = 0;
		i++;
	}
	new_split[i++] = ft_strdup(str);
	new_split[i] = NULL;
	return (new_split);
}

char	**ft_strjoin_double_point(char **split, char *str)
{
	char	**new_split;
	int		n;
	char	ss;

	ss = 0;
	n = 0;
	new_split = 0;
	if (str)
	{
		if (split && *split)
		{
			while (split && split[n])
				n++;
		}
		n++;
	}
	else
		return (NULL);
	new_split = (char **)malloc(sizeof(char *) * (n + 1));
	new_split = norm_strjoin_double(new_split, split, str);
	return (new_split);
}
