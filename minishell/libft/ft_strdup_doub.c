/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_doub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:38:31 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:38:34 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_strdupdoub(char **str)
{
	int		i;
	char	**s;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str && str[i])
		i++;
	s = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (str && str[i])
	{
		s[i] = ft_strdup(str[i]);
		i++;
	}
	s[i] = 0;
	return (s);
}
