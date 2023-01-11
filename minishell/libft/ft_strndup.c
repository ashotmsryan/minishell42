/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:05:53 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/22 14:05:57 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndub(char *str, int n)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str || !*str)
		return (0);
	while (i < n && str[i++])
		;
	if (i == n)
	{
		ret = malloc(sizeof(char) * (i + 1));
		i = -1;
		while (++i < n)
			ret[i] = str[i];
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
