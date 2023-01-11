/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:26 by hvardany          #+#    #+#             */
/*   Updated: 2022/03/29 16:59:27 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sr;
	char	cc;

	cc = (char) c;
	sr = (char *) s;
	while (*sr != '\0')
	{
		if (*sr++ == cc)
		{
			return (--sr);
		}
	}
	if (*sr == cc || cc == 0)
		return (sr);
	return (0);
}
