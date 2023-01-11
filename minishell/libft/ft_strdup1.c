/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:56:46 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/12 19:18:33 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup0(const char *s1)
{
	int		i;
	char	*s;
	char	*a;

	if (!s1)
		return (NULL);
	s = (char *)s1;
	i = ft_strlen0(s);
	a = malloc((i + 1) * sizeof(char));
	i = 0;
	if (!a)
		return (NULL);
	while (s && s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
