/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dolar_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:07:03 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/17 00:05:37 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pars_go_for_double_quote_norm_set(int *i,
	int *j, char *str, t_mini_shell *minir_shell)
{
	if (str && str[*i] && str[*i] == 36)
	{
		(*i)++;
		if (str && str[*i] && str[*i] == '?')
		{
			itoa_string(minir_shell->data.utils, j, g_status);
			(*i)++;
		}
		else if (!str[*i] || (str[*i] && sumbol_is(&str[*i])))
			minir_shell->data.utils[(*j)++] = '$';
		else if (str && str[*i] && str[*i] != 34)
			*j += have_env_dolar_set
				(&str[*i], i, &minir_shell->data.utils[*j], minir_shell);
	}
	else if (str[*i] && str[*i] == 92 && str[*i + 1] && str[*i + 1] == 92)
	{
		minir_shell->data.utils[(*j)++] = str[(*i)++];
		(*i)++;
	}
	else if (str && str[*i] && str[*i] != 34)
		minir_shell->data.utils[(*j)++] = str[(*i)++];
}

void	pars_go_for_dolar_set(int *i, int *j,
	char *str, t_mini_shell *minir_shell)
{
	if (str && str[*i] && str[*i] == 39)
		minir_shell->data.utils[(*j)++] = str[(*i)++];
	if (str && str[*i] && str[*i] != 39)
	{
		while (str && str[*i] && str[*i] != 39)
		{
			minir_shell->data.utils[(*j)++] = str[(*i)++];
		}
	}
	if (str && str[*i] && str[*i] == 39)
	{
		minir_shell->data.utils[(*j)++] = str[(*i)++];
	}
}

void	go_for_double_quote_set(int *i, int *j,
	char *str, t_mini_shell *minir_shell)
{
	if (str && str[*i] && str[*i] == 34)
		minir_shell->data.utils[(*j)++] = str[(*i)++];
	if (str && str[*i] && str[*i] != 34)
	{
		while (str && str[*i] && str[*i] != 34)
			pars_go_for_double_quote_norm_set(i, j, str, minir_shell);
		if (str && str[*i] && str[*i] == 34)
		{
			minir_shell->data.utils[(*j)++] = str[(*i)++];
		}
	}
	else if (str && str[*i] && str[*i] == 34)
		minir_shell->data.utils[(*j)++] = str[(*i)++];
}

void	set_dolar_new(char *str, t_mini_shell *minir_shell, int len)
{
	int		i;
	int		j;

	free(minir_shell->data.utils);
	minir_shell->data.utils = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (minir_shell && str && str[i])
	{
		if (str[i] == 34)
			go_for_double_quote_set(&i, &j, str, minir_shell);
		else if (str[i] == 39)
			pars_go_for_dolar_set(&i, &j, str, minir_shell);
		else if (str[i] == 36)
			pars_go_for_double_quote_norm_set(&i, &j, str, minir_shell);
		else
			minir_shell->data.utils[j++] = str[i++];
	}
	minir_shell->data.utils[j] = '\0';
}
