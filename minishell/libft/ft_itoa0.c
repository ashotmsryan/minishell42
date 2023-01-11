/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:57:07 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/15 18:14:47 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	count(int k)
{
	int	h;

	if (k < 0)
		h = 1;
	else
		h = 0;
	if (k == 0)
		return (1);
	while (k != 0)
	{
		k = k / 10;
		h++;
	}
	return (h);
}

char	*ft_itoa0(int n)
{
	long			i;
	long			h;
	unsigned int	t;
	char			*s;

	i = 0;
	h = count(n);
	s = (char *)malloc(h + 1);
	t = n;
	if (n < 0)
	{
		s[0] = '-';
		t = -n;
	}
	while ((h > 1 && n < 0) || (h >= 1 && n >= 0))
	{	
		s[h - 1] = t % 10 + '0';
		t = t / 10;
		h--;
	}
	s[count(n)] = '\0';
	return (s);
}
