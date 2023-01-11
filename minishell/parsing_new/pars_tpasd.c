/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tpasd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:02:33 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 04:46:34 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	go_for_double_qout(int *j, char *str, char search)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	(*j)++;
	while (str[*j] && str[*j] != '\0' && str[*j] != search)
	{
		i++;
		(*j)++;
	}
	if (str[*j] == search)
		(*j)++;
	return (i);
}

int	pars_unset_qouts_norm(char *str, int *quote_have)
{
	int	j;
	int	l;

	j = 0;
	l = 0;
	while (str[j] != '\0')
	{
		if (str[j] == 34)
		{
			*quote_have = 1;
			l += go_for_double_qout(&j, str, 34);
		}
		else if (str[j] == 39)
		{
			*quote_have = 1;
			l += go_for_double_qout(&j, str, 39);
		}
		else
		{
			j++;
			l++;
		}
	}
	return (l);
}
