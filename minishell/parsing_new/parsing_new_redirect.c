/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_new_redirect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:45:34 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 03:45:36 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pars_redirect1(int i, int j,
	t_mini_shell *minir_shell, char	**command)
{
	char	**str;

	str = 0;
	if (command && command[j])
	{
		minir_shell[i].data.that_cammand_number = 2;
		minir_shell[i].data.flag_for_input = 2;
		minir_shell[i].data.doubl_left_index++;
		str = ft_strjoin_double_point
			(minir_shell[i].data.heredoc, command[j]);
		if (str)
		{
			free(minir_shell[i].data.heredoc);
			minir_shell[i].data.heredoc = str;
			str = 0;
		}
	}
}

void	pars_redirect2(int i, int j,
	t_mini_shell *minir_shell, char	**command)
{
	char	**str;

	str = 0;
	if (command && command[j])
	{
		minir_shell[i].data.that_cammand_number = 4;
		minir_shell[i].data.flag_for_output = 2;
		minir_shell[i].data.doubl_right_index++;
		str = ft_strjoin_double_point
			(minir_shell[i].data.boable_redirect_output, command[j]);
		if (str)
		{
			free(minir_shell[i].data.boable_redirect_output);
			minir_shell[i].data.boable_redirect_output = 0;
			minir_shell[i].data.boable_redirect_output = str;
			str = 0;
		}
		pars_have_redirect(i, j, minir_shell, command);
	}
}

void	pars_redirect3(int i, int j,
	t_mini_shell *minir_shell, char	**command)
{
	char	**str;

	str = 0;
	if (command && command[j])
	{
		minir_shell[i].data.that_cammand_number = 1;
		minir_shell[i].data.flag_for_input = 1;
		minir_shell[i].data.left_index++;
		str = ft_strjoin_double_point
			(minir_shell[i].data.redirect_input, command[j]);
		if (str)
		{
			free(minir_shell[i].data.redirect_input);
			minir_shell[i].data.redirect_input = str;
			str = 0;
		}
		pars_have_redirect(i, j, minir_shell, command);
	}
}

void	pars_redirect4(int i, int j,
	t_mini_shell *minir_shell, char	**command)
{
	char	**str;

	str = 0;
	if (command && command[j])
	{
		minir_shell[i].data.that_cammand_number = 3;
		minir_shell[i].data.flag_for_output = 1;
		minir_shell[i].data.right_index++;
		str = ft_strjoin_double_point
			(minir_shell[i].data.redirect_output, command[j]);
		if (str)
		{
			free(minir_shell[i].data.redirect_output);
			minir_shell[i].data.redirect_output = str;
			str = 0;
		}
		pars_have_redirect(i, j, minir_shell, command);
	}
}

void	pars_redirect_not(int i, int j,
	t_mini_shell *minir_shell, char	**command)
{
	char	**str;

	str = 0;
	str = ft_strjoin_double_point
		(minir_shell[i].data.pipe_split, command[j]);
	if (str)
	{
		free(minir_shell[i].data.pipe_split);
		minir_shell[i].data.pipe_split = 0;
		minir_shell[i].data.pipe_split = str;
		str = 0;
	}
}
