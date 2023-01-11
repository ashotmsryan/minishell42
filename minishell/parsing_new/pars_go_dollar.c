/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_go_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:59:52 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/16 22:57:56 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	sumbol_is(char *str)
{
	if (str[0] == 37 || str[0] == 47 || str[0] == 32 || str[0] == 36)
		return (1);
	return (0);
}

void	pars_go_for_double_quote_norm_1(int *i, int *j,
	char *str, t_mini_shell *minir_shell)
{
	(*i)++;
	if (str[*i] && str[*i] == '?')
	{
		*j += itoa_namber(g_status);
		(*i)++;
	}
	else if (!str[*i] || (str[*i] && sumbol_is(&str[*i])))
	{
		(*j)++;
	}
	else if (str[*i] && str[*i] != 34)
	{
		*j += have_env_dolar
			(&str[*i], i, minir_shell);
	}
}

void	pars_go_for_double_quote_norm(int *i, int *j,
	char *str, t_mini_shell *minir_shell)
{
	if (str[*i] && str[*i] == 36)
	{
		pars_go_for_double_quote_norm_1(i, j, str, minir_shell);
	}
	else if (str[*i] && str[*i] == 92 && str[*i + 1] && str[*i + 1] == 92)
	{
		(*i) += 2;
		(*j)++;
	}
	else if (str[*i] && str[*i] != 34)
	{
		(*i)++;
		(*j)++;
	}
}

void	go_for_double_quote(int *i, int *j,
	char *str, t_mini_shell *minir_shell)
{
	if (str && str[*i] && str[*i] == 34)
	{
		(*i)++;
		(*j)++;
	}
	if (str && str[*i] && str[*i] != 34)
	{
		while (str && str[*i] && str[*i] != 34)
			pars_go_for_double_quote_norm(i, j, str, minir_shell);
		if (str && str[*i] && str[*i] == 34)
		{
			(*i)++;
			(*j)++;
		}
	}
	else if (str && str[*i] && str[*i] == 34)
	{
		(*i)++;
		(*j)++;
	}
}

int	set_dolar(char *str, t_mini_shell *minir_shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] && minir_shell)
	{
		if (str[i] == 34)
			go_for_double_quote(&i, &j, str, minir_shell);
		else if (str[i] == 39)
			go_for_dolar(&i, &j, str);
		else if (str[i] == 36)
			pars_go_for_double_quote_norm(&i, &j, str, minir_shell);
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}
