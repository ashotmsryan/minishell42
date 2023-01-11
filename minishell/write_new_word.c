/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_new_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:47:36 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:47:37 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_new_words_norm(char *str, int *j, t_mini_shell *minir_shell, int *i)
{
	int	flag_set_unset;

	flag_set_unset = 0;
	if (str[*i] && str[*i + 1] && str[*i + 1] == '?')
	{
		flag_set_unset = 1;
		itoa_string(minir_shell->string_return, j, g_status);
		*i += 2;
	}
	else if (!str[*i + 1] || (str[*i + 1] && str[*i + 1] == 32))
	{
		minir_shell->string_return[(*j)++] = '$';
		if (str[*i])
			(*i)++;
	}
	else if (str[(*i) + 1])
	{
		flag_set_unset = 1;
		(*i)++;
		(*j) += env_one_strline_write
			(&str[*i], i, &minir_shell->string_return[*j], minir_shell);
	}
	return (flag_set_unset);
}

int	write_new_words_norm1(char *str, int *j, t_mini_shell *minir_shell, int *i)
{
	if (str[*i] && str[*i] == 34)
	{
		(*i)++;
		while (str[*i] && str[*i] != 34)
		{
			minir_shell->flag_set_unset = 0;
			if (str[*i] && str[*i] == 36)
				minir_shell->flag_set_unset = write_new_words_norm
					(str, j, minir_shell, i);
			else if (str[*i] && minir_shell->flag_set_unset == 0)
			{
				if (str[*i] != 34)
					minir_shell->string_return[(*j)++] = str[*i];
				(*i)++;
			}
		}
		if (str[*i])
			(*i)++;
	}
	return (minir_shell->flag_set_unset);
}

void	write_new_word_norm2(char *str, int *j,
	t_mini_shell *minir_shell, int *i)
{
	if (str[*i] && str[*i] == 36)
	{
		if (str[*i] && str[*i + 1] && str[*i + 1] == '?')
		{
			itoa_string(minir_shell->string_return,
				j, g_status);
			*i += 2;
		}
		else if (!str[*i + 1] || (str[*i + 1] && str[*i + 1] == 32))
		{
			minir_shell->string_return[(*j)++] = '$';
			if (str)
				(*i)++;
		}
		else if (str[*i + 1])
		{
			(*i)++;
			(*j) += env_one_strline_write(&str[*i], i,
					&minir_shell->string_return[*j], minir_shell);
		}
		else
			minir_shell->string_return[(*j)++] = str[(*i)++];
	}
	if (str[*i] && str[*i] != 36 && str[*i] != 39 && str[*i] != 34)
		minir_shell->string_return[(*j)++] = str[(*i)++];
}

void	write_new_word_norm3(char *str, int *j,
	t_mini_shell *minir_shell, int *i)
{
	(*i)++;
	while (str[*i] && str[*i] != 39)
	{
		if (str[*i] && str[*i] != 39)
			minir_shell->string_return[(*j)++] = str[*i];
		(*i)++;
	}
	if (str[*i])
		(*i)++;
}

char	*write_new_words(char *str, int j, t_mini_shell *minir_shell)
{
	int	i;

	minir_shell->flag_set_unset = 0;
	i = 0;
	minir_shell->string_return = 0;
	if (!str || !*str || !j)
		return (NULL);
	minir_shell->string_return = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (i < ft_strlen0(str))
	{
		minir_shell->flag_set_unset = write_new_words_norm1
			(str, &j, minir_shell, &i);
		if (str[i] && str[i] == 39)
		{
			write_new_word_norm3(str, &j, minir_shell, &i);
		}
		write_new_word_norm2(str, &j, minir_shell, &i);
	}
	minir_shell->string_return[j] = '\0';
	return (minir_shell->string_return);
}
