/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_unset_quots_data_redirect_input.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:44:12 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 04:47:03 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_input_norm_6(char *new_str, int *l, int *k, char *s)
{
	new_str[*l] = s[*k];
	(*k)++;
	(*l)++;
}

char	*pars_unset_quots_data_redirect_input_norm(int i,
	t_mini_shell *minir_shell, int a, int l)
{
	char	*new_str;
	int		k;

	k = 0;
	new_str = malloc(sizeof(char) * (l + 1));
	if (!new_str)
		exit (1);
	l = 0;
	while (minir_shell && minir_shell[i].data.redirect_input
		&& minir_shell[i].data.redirect_input[a]
		&& minir_shell[i].data.redirect_input[a][k] != '\0')
	{
		if (minir_shell[i].data.redirect_input[a][k] == 34)
			k += go_for_double_qout_malloc(&minir_shell
				[i].data.redirect_input[a][k], 34, new_str, &l);
		else if (minir_shell[i].data.redirect_input[a][k] == 39)
			k += go_for_double_qout_malloc(&minir_shell
				[i].data.redirect_input[a][k], 39, new_str, &l);
		else
			redirect_input_norm_6(new_str, &l, &k,
				minir_shell[i].data.redirect_input[a]);
	}
	new_str[l] = '\0';
	return (new_str);
}

void	p_u_q_d_r_b_r_o_n1(int *k, int *l, char *new_str, char *s)
{
	new_str[*l] = s[*k];
	(*k)++;
	(*l)++;
}

static char	*pars_unset_quots_data_redirect_boable_redirect_output_norm(int i,
		t_mini_shell *minir_shell, int a, int l)
{
	char	*new_str;
	int		k;

	k = 0;
	new_str = malloc(sizeof(char) * (l + 1));
	if (!new_str)
		exit (1);
	l = 0;
	while (minir_shell && minir_shell[i].data.boable_redirect_output
		&& minir_shell[i].data.boable_redirect_output[a]
		&& minir_shell[i].data.boable_redirect_output[a][k] != '\0')
	{
		if (minir_shell[i].data.boable_redirect_output[a][k] == 34)
			k += go_for_double_qout_malloc(&minir_shell
				[i].data.boable_redirect_output[a][k], 34, new_str, &l);
		else if (minir_shell[i].data.boable_redirect_output[a][k] == 39)
			k += go_for_double_qout_malloc(&minir_shell
				[i].data.boable_redirect_output[a][k], 39, new_str, &l);
		else
			p_u_q_d_r_b_r_o_n1(&k, &l, new_str,
				minir_shell[i].data.boable_redirect_output[a]);
	}
	new_str[l] = '\0';
	return (new_str);
}

void	pars_unset_quots_data_redirect_boable_redirect_output(int i,
		t_mini_shell *minir_shell)
{
	int		l;
	int		a;
	int		quote_have;
	char	*new_str;

	a = 0;
	while (minir_shell[i].data.boable_redirect_output
		&& minir_shell[i].data.boable_redirect_output[a])
	{
		quote_have = 0;
		l = 0;
		l = pars_unset_qouts_norm(minir_shell
			[i].data.boable_redirect_output[a], &quote_have);
		if (l && quote_have == 1)
		{
			new_str
				= pars_unset_quots_data_redirect_boable_redirect_output_norm(i,
					minir_shell, a, l);
			new_str_puq(new_str, a, i, minir_shell);
		}
		a++;
	}
}
