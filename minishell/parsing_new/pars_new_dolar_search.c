/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_new_dolar_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:02:21 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 01:02:24 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pars_strncmp(char *s1, char *s2, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (!s1[j] || !s2[j] || s1[j] > s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		else if (s1[j] < s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		j++;
	}
	if (s1[j] != '=')
		return (1);
	return (0);
}

char	*pars_ft_getenv_pars(char *search_key, t_mini_shell *minir_shell)
{
	int	k;

	k = 0;
	while (minir_shell->env[k])
	{
		if (pars_strncmp(minir_shell->env[k], search_key, ft_strlen(search_key))
			== 0)
		{
			return (&(minir_shell->env[k][ft_strlen(search_key) + 1]));
		}
		k++;
	}
	return (NULL);
}

void	have_env_dolar1(char *str, int *l)
{
	while (str[*l] && ((str[*l] >= 48 && str[*l] <= 57)
			|| (str[*l] >= 65 && str[*l] <= 90)
			|| (str[*l] >= 97 && str[*l] <= 122)))
	(*l)++;
}

int	have_env_dolar(char *str, int *i,
	t_mini_shell *minir_shell)
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
		have_env_dolar1(str, &l);
	*i += l;
	if (l)
	{
		dollar_valu = ft_strndub(str, l);
		if (dollar_valu && *dollar_valu)
			dollar_valu_utils = pars_ft_getenv_pars(dollar_valu, minir_shell);
		free(dollar_valu);
		l = 0;
		if (dollar_valu_utils)
			l = ft_strlen0(dollar_valu_utils);
	}
	return (l);
}
