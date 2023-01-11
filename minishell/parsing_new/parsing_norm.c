/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 03:51:38 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 03:52:18 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parsing_norm2_norm2(int i,
	t_mini_shell *minir_shell, int j, char	**command)
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

void	parsing_norm2_norm1(int i,
	t_mini_shell *minir_shell, int j, char	**command)
{
	char	**str;

	str = 0;
	if (!minir_shell[i].flag_quote[j]
		&& ft_strncmp111(command[j], ">", 1) == 0)
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
	}
	else
		parsing_norm2_norm2(i, minir_shell, j, command);
}

void	parsing_norm2_norm(int i,
	t_mini_shell *minir_shell, int j, char	**command)
{
	char	**str;

	str = 0;
	if (!minir_shell[i].flag_quote[j]
		&& ft_strncmp111(command[j], "<", 1) == 0)
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
	}
	else
		parsing_norm2_norm1(i, minir_shell, j, command);
}

void	parsing_norm2_ps_a1(int i,
	t_mini_shell *minir_shell, int j, char	**command)
{
	char	**str;

	str = 0;
	if (!minir_shell[i].flag_quote[j]
		&& ft_strncmp111(command[j], ">>", 2) == 0)
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
	}
	else
		parsing_norm2_norm(i, minir_shell, j, command);
}

void	parsing_norm2(int i, t_mini_shell *minir_shell, int j, char	**command)
{
	char	**str;

	str = 0;
	if (command && command[j])
	{
		if (!minir_shell[i].flag_quote[j]
			&& ft_strncmp1112(command[j], "<<", 2) == 0)
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
		else
			parsing_norm2_ps_a1(i, minir_shell, j, command);
	}
}
