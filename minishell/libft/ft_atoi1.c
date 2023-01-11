/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:22:26 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/09 15:11:26 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi0(const char *str)
{
	long long	i;
	long long	j;
	long long	k;

	j = 0;
	k = 1;
	i = 0;
	while (str && str[i] && (str[i] == '\t' || str[i] == ' '
			|| str[i] == '\r' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\v'))
		i++;
	if (str && str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	while (str && str[i] && str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10;
		j = j + (str[i] - '0');
		i++;
	}
	return (j * k);
}
