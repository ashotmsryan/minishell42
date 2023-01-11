/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:46:15 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/16 15:10:16 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin0(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(ft_strlen0(s1) + ft_strlen0(s2) + 1);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{	
		s[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	s[i] = '\0';
	return (s);
}
