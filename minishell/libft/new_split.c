/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:17:04 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 22:29:25 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp1112(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	if (s1[j] && s1[j] == s1[j - 1])
		return (1);
	return (0);
}
