/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:40:34 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/12 19:36:30 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen0(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		if (!str[i])
			return (0);
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	env_strlen_ps(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		if (!str[i])
			return (0);
	if (!str)
		return (0);
	while (str && str[i] != '\0' && str[i] != '=')
		i++;
	return (i);
}
