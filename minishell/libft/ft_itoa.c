/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:48:11 by hvardany          #+#    #+#             */
/*   Updated: 2022/10/30 20:31:26 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*setmalloc(char *s, int t, int z)
{
	int				j;
	unsigned int	n;

	j = 0;
	if (z < 0)
	{
		n = z * -1;
		s[j] = '-';
	}
	else
		n = z;
	s[t] = '\0';
	if (n == 0)
		s[j] = '0';
	while (n > 0)
	{
		s[t - j - 1] = n % 10 + '0';
		n /= 10;
		j++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	k;
	int				t;

	t = 0;
	if (n < 0)
	{
		t++;
		k = n * -1;
	}
	else
		k = n;
	while (k > 0)
	{
		k = k / 10;
		t++;
	}
	if (n == 0)
		t++;
	s = (char *)malloc((t + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s = setmalloc(s, t, n);
	return (s);
}
