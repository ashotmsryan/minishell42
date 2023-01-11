/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_one_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:53:05 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 04:03:39 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pars_if_39_34_32(char *s, char *str, int *j, int *i)
{
	if (str[*i] && str[*i] == 39)
	{
		s[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] != 39)
		{
			s[(*j)++] = str[(*i)++];
		}
		if (str[*i])
		s[(*j)++] = str[(*i)++];
	}
	if (str[*i] && str[*i] == 34)
	{
		s[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] != 34)
			s[(*j)++] = str[(*i)++];
		if (str[*i])
		s[(*j)++] = str[(*i)++];
	}
	if (str[*i] && str[*i] == 32)
	{
		s[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] == 32)
			(*i)++;
	}
}

void	pars_if_smol_smol_34(char *s, char *str, int *j, int *i)
{
	if (str[*i] && str[*i] == '<' && str[*i + 1] && str[*i + 1] == '<')
	{
		if (*i - 1 > 0 && str[*i - 1] != 32)
		s[(*j)++] = ' ';
		s[(*j)++] = str[(*i)++];
		s[(*j)++] = str[(*i)++];
		while (str[(*i)] && str[(*i)] == ' ')
			(*i)++;
		while (str[*i] && str[*i] != '<' && str[*i] != '>'
			&& str[*i] != ' ' && str[*i] != 39
			&& str[*i] != 34 && str[*i] != '$')
			s[(*j)++] = str[(*i)++];
	}
	if (str[(*i)] && str[(*i)] == '>' && str[*i + 1] && str[*i + 1] == '>')
	{
		if (*i - 1 > 0 && str[*i - 1] != 32)
		s[(*j)++] = ' ';
		s[(*j)++] = str[(*i)++];
		s[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] == ' ')
			(*i)++;
		while (str[*i] && str[*i] != '<' && str[*i] != '>' && str[*i] != ' '
			&& str[*i] != 39 && str[*i] != 34 && str[*i] != '$')
			s[(*j)++] = str[(*i)++];
	}
}

void	pars_if_big_smol_34(char *s, char *str, int *j, int *i)
{
	if (str[*i] && str[*i] == '>' && str[*i + 1] && str[*i + 1] != '>')
	{
		if (*i - 1 > 0 && str[*i - 1] != 32)
		s[(*j)++] = ' ';
		s[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] == ' ')
			(*i)++;
		while (str[*i] && str[*i] != '<' && str[*i] != '>'
			&& str[*i] != ' ' && str[*i] != 39
			&& str[*i] != 34 && str[*i] != '$')
			s[(*j)++] = str[(*i)++];
	}
	if (str[*i] && str[*i] == '<' && str[*i + 1] && str[*i + 1] != '<')
	{
		if (*i - 1 > 0 && str[*i - 1] != 32)
		s[(*j)++] = ' ';
		s[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] == ' ')
			(*i)++;
		while (str[*i] && str[*i] != '<' && str[*i] != '>' && str[*i] != ' '
			&& str[*i] != 39 && str[*i] != 34 && str[*i] != '$')
		{
			s[(*j)++] = str[(*i)++];
		}
	}
}

void	pars_if_dollar(char *s, char *str, int *j, int *i)
{
	if (str[*i] && str[*i] == '$')
	{
		s[(*j)++] = str[(*i)++];
		if (str[*i] && str[*i] == 32)
		{
			s[(*j)++] = str[(*i)++];
			while (str[*i] && str[*i] == ' ')
			(*i)++;
		}
	}
	if (str[*i] && str[*i] != '<' && str[*i] != '>'
		&& str[*i] != 32 && str[*i] != '$' && str[*i] != 34 && str[*i] != 39)
	{
		s[(*j)++] = str[(*i)++];
	}
	if (str[*i] && (str[*i] == '<' || str[*i] == '>' || str[*i] == 32
			|| str[*i] == '$' || str[*i] == 34
			|| str[*i] == 39) && !str[*i + 1])
	{
		s[(*j)++] = str[(*i)++];
	}
}

char	*parsing_one_pipe(char *str, int j)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	j = 0;
	while (str[i])
	{
		pars_if_39_34_32(s, str, &j, &i);
		pars_if_smol_smol_34(s, str, &j, &i);
		pars_if_big_smol_34(s, str, &j, &i);
		pars_if_dollar(s, str, &j, &i);
	}
	s[j] = '\0';
	return (s);
}
