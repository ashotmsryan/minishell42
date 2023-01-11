/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntacs_error_ad1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 05:34:16 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 05:34:19 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntacs_error_search_5(char *str, t_stract *mini, int i)
{
	if (char_tokin2(str, &i) != 0)
	{
		while (str && str[i] && str[i] == 32)
		i++;
		if (!str[i])
		{
			mini->syntax_error = 11;
			return (1);
		}
	}
	return (0);
}
