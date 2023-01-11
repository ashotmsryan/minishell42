/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_herdoc_norm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:54:39 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/21 18:51:47 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	when_input_not_is_hirdoc(t_mini_shell *minir_shell, int i)
{
	int	status_global;

	minir_shell[i].data2.fork_for_hd = fork();
	if (minir_shell[i].data2.fork_for_hd == -1)
	{
		printf("can not open fork\n");
		g_status = 1;
		return ;
	}
	if (minir_shell[i].data2.fork_for_hd == 0)
	{
		heredoc(&minir_shell[i]);
		free_it(&minir_shell[i].data2.built.hd_data);
		minir_shell[i].data2.built.hd_data = 0;
		exit(0);
	}
	waitpid(minir_shell[i].data2.fork_for_hd, &status_global, 0);
}

int	number_herdoc_dollar(char *str, int *i, t_mini_shell *minir_shell)
{
	int	j;

	j = 0;
	if (str[*i] && str[*i] == 36)
	{
		(*i)++;
		if (str[*i] && str[*i] == '?')
		{
			j += itoa_namber(g_status);
			(*i)++;
		}
		else if (!str[*i] || (str[*i] && !((str[*i] >= 65 && str[*i] <= 90)
					|| (str[*i] >= 97 && str[*i] <= 122)
					|| (str[*i] >= 48 && str[*i] <= 57))))
		{
			j++;
		}
		else if (str[*i] && str[*i] != 34)
		{
			j += have_env_dolar
				(&str[*i], i, minir_shell);
		}
	}
	return (j);
}

void	number_herdoc_dollar_set(char *str, int i,
	t_mini_shell *minir_shell, int strdup_size)
{
	char	*s;
	int		l;

	l = 0;
	s = malloc(sizeof(char) * (strdup_size + 1));
	if (str && str[i] && str[i] == 36)
	{
		i++;
		if (str && str[i] && str[i] == '?')
		{
			l = itoa_string_ads1(s, &i, g_status);
		}
		else if (!str[i] || (str[i] && !((str[i] >= 65 && str[i] <= 90)
					|| (str[i] >= 97 && str[i] <= 122)
					|| (str[i] >= 48 && str[i] <= 57))))
			s[l++] = '$';
		else if (str && str[i] && s)
			l = have_env_dolar_set(&str[i], &i, s, minir_shell);
	}
	s[l] = '\0';
	l = -1;
	while (s && s[++l])
		write(minir_shell->data2.end[1], &s[l], 1);
	free(s);
	s = 0;
}

void	herdoc_dollar(char *str, int *z, t_mini_shell *minir_shell)
{
	int		j;
	int		strdup_size;

	j = *z;
	strdup_size = 0;
		strdup_size = number_herdoc_dollar(str, z, minir_shell);
	if (strdup_size)
		number_herdoc_dollar_set(str, *z - (*z - j), minir_shell, strdup_size);
}

void	heredoc_when_output_norm(t_mini_shell *minir_shell, int i, int *jx)
{
	int	z;
	int	j;

	z = 0;
	j = 0;
	while (minir_shell[i].data2.built.hd_data
		&& minir_shell[i].data2.built.hd_data[++(*jx)])
	{
		z = 0;
		while (minir_shell->data2.built.hd_data[*jx][z])
		{
			if (minir_shell->data2.built.hd_data[*jx][z] == '$'
				&& !minir_shell->data.quote_have)
				herdoc_dollar(minir_shell->data2.built.hd_data[*jx],
					&z, &minir_shell[i]);
			else
			{
				write(minir_shell->data2.end[1],
					&minir_shell->data2.built.hd_data[*jx][z], 1);
				z++;
			}
		}
		write(minir_shell->data2.end[1], "\n", 1);
	}
	write(minir_shell->data2.end[1], "\0", 1);
}
