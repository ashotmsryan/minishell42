/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:22:38 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 04:22:41 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	go_for_dolar2(int *i, int *j, char *str)
{
	if (str && str[*i] && str[*i] == 39)
	{
		(*i)++;
		(*j)++;
	}
	if (str && str[*i] && str[*i] != 39)
	{
		while (str && str[*i] && str[*i] != 39)
		{
			(*i)++;
			(*j)++;
		}
	}
	else if (str && str[*i] && str[*i] == 39)
	{
		(*i)++;
		(*j)++;
	}
}

int	set_dolar_changed11(char *str, t_mini_shell *minir_shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] && minir_shell)
	{
		if (str[i] == 34)
			go_for_double_quote1(&i, &j, str, minir_shell);
		else if (str[i] == 39)
			go_for_dolar2(&i, &j, str);
		else if (str[i] == 36)
			pars_go_for_double_quote_norm3(&i, &j, str, minir_shell);
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}
