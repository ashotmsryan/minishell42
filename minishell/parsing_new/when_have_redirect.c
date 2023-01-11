/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_have_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:14:29 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 04:50:14 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	outpu_1(char *str, t_mini_shell *minir_shell)
{
	int	i;
	int	l;

	i = 1;
	minir_shell->data.permission = 0;
	l = set_dolar_changed11(&str[1], minir_shell);
	if (str[1] == '$' && l == 0)
	{
		g_status = 1;
		write (2, "minishell:", 11);
		write (2, &str[1], ft_strlen(&str[1]));
		write (2, ": ambiguous redirect\n", 21);
		return (1);
	}
	else if (pars_search_fd_output1(minir_shell) == 1)
		return (1);
	return (0);
}

int	outpu_2(char *str, t_mini_shell *minir_shell)
{
	int	i;
	int	l;

	i = 2;
	minir_shell->data.permission = 0;
	l = set_dolar_changed11(&str[2], minir_shell);
	if (str[2] == '$' && l == 0)
	{
		g_status = 1;
		write (2, "minishell:", 11);
		write (2, &str[2],
			ft_strlen(&str[2]));
		write (2, ": ambiguous redirect\n", 21);
		return (1);
	}
	else if (pars_search_fd_output2(minir_shell) == 1)
		return (1);
	return (0);
}

int	input_1(char *str, t_mini_shell *minir_shell)
{
	int	i;
	int	l;

	i = 1;
	minir_shell->data.permission = 0;
	l = set_dolar_changed11(&str[1], minir_shell);
	if (str[1] == '$' && l == 0)
	{
		g_status = 1;
		write (2, "minishell:", 11);
		write (2, &str[1], ft_strlen(&str[1]));
		write (2, ": ambiguous redirect\n", 21);
		g_status = 1;
		return (1);
	}
	else if (pars_search_fd_input(minir_shell) == 1)
		return (1);
	return (0);
}

int	when_have_redirect_norm(int i, int j, t_mini_shell *minir_shell)
{
	if (ft_strncmp_pars_new(minir_shell[i].data.redirect_have[j], ">>", 2) == 0)
	{
		if (outpu_2(minir_shell[i].data.redirect_have[j], &minir_shell[i]) == 1)
			return (1);
		minir_shell[i].data.double_right++;
	}
	else if (ft_strncmp_pars_new(minir_shell[i].data.redirect_have[j],
			"<", 1) == 0)
	{
		if (input_1(minir_shell[i].data.redirect_have[j], &minir_shell[i]) == 1)
			return (1);
		minir_shell[i].data.left++;
	}
	else if (ft_strncmp_pars_new(minir_shell[i].data.redirect_have[j],
			">", 1) == 0)
	{
		if (outpu_1(minir_shell[i].data.redirect_have[j], &minir_shell[i]) == 1)
			return (1);
		minir_shell[i].data.right++;
	}
	return (0);
}

int	when_have_redirect(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	int	j;
	int	len;

	j = 0;
	if (mini && minir_shell && minir_shell[i].data.redirect_have
		&& *minir_shell[i].data.redirect_have[j])
	{
		len = ft_strlen_double(minir_shell[i].data.redirect_have);
		while (j < len)
		{
			if (when_have_redirect_norm(i, j, minir_shell))
				return (1);
			j++;
		}
	}
	if (minir_shell->data.flag_for_input == 2)
		minir_shell->data.fd_input = minir_shell->data2.end[0];
	else if (minir_shell->data2.end[0])
		close(minir_shell->data2.end[0]);
	return (0);
}
