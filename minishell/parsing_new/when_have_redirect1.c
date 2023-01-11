/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_have_redirect1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:23:37 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 06:32:23 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	sumbol_is88(char *str)
{
	if ((str[0] >= 33 && str[0] <= 47) || str[0] == 36
		|| str[0] == 32 || (str[0] >= 91 && str[0] <= 96))
		return (1);
	return (0);
}

void	pars_if_permission(int i, char *s, t_mini_shell *minir_shell)
{
	int	l;

	l = 0;
	if (s[l] == '>')
	l++;
	l++;
	if (s[l] == 34 && s[i] == 34 && s[i + 1])
	{
		minir_shell->data.permission = 1;
	}
	else if (s[l] == '$' && s[i])
	{
		minir_shell->data.permission = 1;
	}
}

void	pg_norm_fdqn3(int *i, int *j,
			char *str)
{
	if (str[*i] && str[*i] == 92 && str[*i + 1] && str[*i + 1] == 92)
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

void	pars_go_for_double_quote_norm3(int *i, int *j,
			char *str, t_mini_shell *minir_shell)
{
	int	per;

	per = 0;
	if (str[*i] && str[*i] == 36)
	{
		(*i)++;
		if (str[*i] && str[*i] == '?')
		{
			*j += itoa_namber(g_status);
			(*i)++;
		}
		else if (!str[*i]
			|| (str[*i] && ((str[*i] == 34 && *i - 2 > 0 && str[*i - 2] == 34)
					|| sumbol_is88(&str[*i]))))
			(*j)++;
		else if (str[*i] && str[*i] != 34)
		{
			per = *j;
			*j += have_env_dolar(&str[*i], i, minir_shell);
			if (per > 0 && per < 3 && *j)
				pars_if_permission(*i, str, minir_shell);
		}
	}
	else
		pg_norm_fdqn3(i, j, str);
}

void	go_for_double_quote1(int *i, int *j,
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
			pars_go_for_double_quote_norm3(i, j, str, minir_shell);
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
