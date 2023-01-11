/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_read_new_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:02:48 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 01:02:51 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	symbols(char *str, int *l)
{
	while (str[*l] && ((str[*l] >= 48 && str[*l] <= 57)
			|| (str[*l] >= 65 && str[*l] <= 90)
			|| (str[*l] >= 97 && str[*l] <= 122)))
	(*l)++;
}

void	have_env_dolar_set1(char	*dollar_valu_utils,
	char *string_return, int *k)
{
	int		l;

	l = 0;
	if (dollar_valu_utils)
	{
		l = ft_strlen0(dollar_valu_utils);
		while (*k < l)
		{
			string_return[*k] = dollar_valu_utils[*k];
			(*k)++;
		}
	}
}

int	have_env_dolar_set(char *str, int *i,
	char *string_return, t_mini_shell *minir_shell)
{
	int		l;
	int		k;
	char	*dollar_valu;
	char	*dollar_valu_utils;

	l = 0;
	dollar_valu = 0;
	dollar_valu_utils = 0;
	if (str[l] >= 48 && str[l] <= 57)
		l = 1;
	else
		symbols(str, &l);
	*i += l;
	k = 0;
	if (l)
	{
		dollar_valu = ft_strndub(str, l);
		if (dollar_valu && *dollar_valu)
			dollar_valu_utils = pars_ft_getenv_pars(dollar_valu, minir_shell);
		free(dollar_valu);
		have_env_dolar_set1(dollar_valu_utils, string_return, &k);
	}
	return (k);
}
