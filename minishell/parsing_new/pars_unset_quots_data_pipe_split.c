/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_unset_quots_data_pipe_split.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:51:44 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 02:59:24 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	p_u_q_d_p_s_norm(int *l, int *k, char *new_str, char *s)
{
	new_str[*l] = s[*k];
	(*k)++;
	(*l)++;
}

char	*pars_unset_quots_data_pipe_split_norm(int i,
	t_mini_shell *minir_shell, int a, int l)
{
	char	*new_str;
	int		k;

	k = 0;
	new_str = malloc(sizeof(char) * (l + 1));
	if (!new_str)
		exit (1);
	l = 0;
	while (minir_shell && minir_shell[i].data.pipe_split
		&& minir_shell[i].data.pipe_split[a]
		&& minir_shell[i].data.pipe_split[a][k] != '\0')
	{
		if (minir_shell[i].data.pipe_split[a][k] == 34)
			k += go_for_double_qout_malloc(
					&minir_shell[i].data.pipe_split[a][k], 34, new_str, &l);
		else if (minir_shell[i].data.pipe_split[a][k] == 39)
			k += go_for_double_qout_malloc(
					&minir_shell[i].data.pipe_split[a][k], 39, new_str, &l);
		else
			p_u_q_d_p_s_norm(&l, &k, new_str,
				minir_shell[i].data.pipe_split[a]);
	}
	new_str[l] = '\0';
	return (new_str);
}

void	pars_3(char	*new_str, int a, int i,
	t_mini_shell *minir_shell)
{
	free(minir_shell[i].data.pipe_split[a]);
	minir_shell[i].data.pipe_split[a] = new_str;
	new_str = 0;
}

void	pars_4_redirect(char *new_str, int *l, int *k, char *s)
{
	new_str[*l] = s[*k];
	(*k)++;
	(*l)++;
}

char	*pars_unset_quots_data_redirect_output_norm(int i,
	t_mini_shell *minir_shell, int a, int l)
{
	char	*new_str;
	int		k;

	k = 0;
	new_str = malloc(sizeof(char) * (l + 1));
	if (!new_str)
		exit (1);
	l = 0;
	while (minir_shell && minir_shell[i].data.redirect_output
		&& minir_shell[i].data.redirect_output[a]
		&& minir_shell[i].data.redirect_output[a][k] != '\0')
	{
		if (minir_shell[i].data.redirect_output[a][k] == 34)
			k += go_for_double_qout_malloc(&minir_shell
				[i].data.redirect_output[a][k],
					34, new_str, &l);
		else if (minir_shell[i].data.redirect_output[a][k] == 39)
			k += go_for_double_qout_malloc
				(&minir_shell[i].data.redirect_output[a][k], 39, new_str, &l);
		else
			pars_4_redirect(new_str, &l, &k,
				minir_shell[i].data.redirect_output[a]);
	}
	new_str[l] = '\0';
	return (new_str);
}
