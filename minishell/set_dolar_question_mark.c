/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dolar_question_mark.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:25:48 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 05:28:27 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	for_norm(char *str, int *i, int *j)
{
	if (str[*i] != 34)
		(*j)++;
	(*i)++;
}

void	set_dolar_question_mark_norm1(char *str,
	t_mini_shell *minir_shell, int *i, int *j)
{
	int	flag;

	while (str[*i] && str[*i] != 34)
	{
		flag = 0;
		if (str[*i] && str[*i] == 36)
		{
			(*i)++;
			flag = 1;
			if (str[*i] && str[*i] == '?')
			{
				*j += itoa_namber(g_status);
				(*i)++;
			}
			else if (!str[*i] || (str[*i] && str[*i] == 32))
				(*j)++;
			else if (str[*i] && str[*i] != 34)
				*j += env_one_strline
					(&str[*i], i, minir_shell, minir_shell->i_flag);
		}
		else if (str[*i] && flag == 0)
			for_norm(str, i, j);
	}
}

void	set_dolar_question_mark_norm2(char *str,
	t_mini_shell *minir_shell, int *i, int *j)
{
	if (str[0] == 34 || str[0] == 39)
	minir_shell[minir_shell->i_flag].flag_quote[minir_shell->m_i] = 1;
	if (str[*i] && str[*i] == 34)
	{
		(*i)++;
		set_dolar_question_mark_norm1(str, minir_shell, i, j);
		if (str[*i])
		(*i)++;
	}
	if (str[*i] && str[*i] == 39)
	{
		(*i)++;
		while (str[*i] && str[*i] != 39)
		{
			(*j)++;
			(*i)++;
		}
		if (str[*i])
		(*i)++;
	}
}

void	set_dolar_question_mark_norm3(char *str,
	t_mini_shell *minir_shell, int *i, int *j)
{
	set_dolar_question_mark_norm2(str, minir_shell, i, j);
	if (str[*i] && str[*i] == 36)
	{
		(*i)++;
		if (str[*i] && str[*i] == '?')
		{
			(*j) += itoa_namber(g_status);
			(*i)++;
		}
		else if (!str[*i] || (str[*i] && str[*i] == 32))
			(*j)++;
		else if (str[*i])
			(*j) += env_one_strline
				(&str[*i], i, minir_shell, minir_shell->i_flag);
	}
	if (str[*i] && str[*i] != 36 && str[*i] != 39 && str[*i] != 34)
	{
		(*j)++;
		(*i)++;
	}
}

char	*set_dolar_question_mark(char *str,
	t_mini_shell *minir_shell, int i_flag, int m_i)
{
	int		i;
	int		j;
	char	*string_return;

	i = 0;
	j = 0;
	string_return = 0;
	if (!str || !*str)
		return (NULL);
	while (str && i < ft_strlen0(str))
	{
		minir_shell->m_i = m_i;
		minir_shell->i_flag = i_flag;
		set_dolar_question_mark_norm3(str, minir_shell, &i, &j);
	}
	if (!j)
		return (NULL);
	string_return = write_new_words(str, j, minir_shell);
	if (string_return)
	{
		free(str);
		return (string_return);
	}
	return (str);
}
