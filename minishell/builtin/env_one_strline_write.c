/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_one_strline_write.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:37:27 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:37:29 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	itoa_namber(int signal)
{
	int	i;

	i = 0;
	if (!signal)
		return (1);
	while (signal != 0)
	{
		signal = signal / 10;
		i++;
	}
	return (i);
}

void	env_one_strline_norm(char *str, int *l)
{
	while (str[*l] && ((str[*l] >= 48 && str[*l] <= 57)
			|| (str[*l] >= 65 && str[*l] <= 90)
			|| (str[*l] >= 97 && str[*l] <= 122)))
	(*l)++;
}

int	env_one_strline(char *str, int *i,
	t_mini_shell *minir_shell, int i_flag)
{
	int		l;
	char	*dollar_valu;
	char	*dollar_valu_utils;

	l = 0;
	dollar_valu = 0;
	dollar_valu_utils = 0;
	if (str[l] >= 48 && str[l] <= 57)
	l = 1;
	else
		env_one_strline_norm(str, &l);
	*i += l;
	if (l)
	{
		dollar_valu = ft_strndub(str, l);
		if (dollar_valu && *dollar_valu)
			dollar_valu_utils = ft_getenv(dollar_valu, i_flag, minir_shell);
		free(dollar_valu);
		l = 0;
		if (dollar_valu_utils)
			l = ft_strlen0(dollar_valu_utils) - 1;
	}
	return (l);
}

void	env_one_strline_write_norm(char	*dollar_valu_utils,
	char *string_return, int *k)
{
	int		l;

	l = 0;
	if (dollar_valu_utils)
	{
		l = ft_strlen0(dollar_valu_utils);
		while (*k < l - 1)
		{
			string_return[*k] = dollar_valu_utils[*k + 1];
			(*k)++;
		}
	}
}

int	env_one_strline_write(char *str, int *i,
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
		env_one_strline_norm(str, &l);
	*i += l;
	k = 0;
	if (l)
	{
		dollar_valu = ft_strndub(str, l);
		if (dollar_valu && *dollar_valu)
			dollar_valu_utils = ft_getenv(dollar_valu, 0, minir_shell);
		free(dollar_valu);
		env_one_strline_write_norm(dollar_valu_utils, string_return, &k);
	}
	return (k);
}
