/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_t_mini_shell2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:40:28 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:06:09 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	memory_free_mini_shell_data_char_doeble8_1(t_mini_shell *mini_shell)
{
	int	i;

	i = -1;
	while (mini_shell && mini_shell[0].pipe_number > ++i)
	{
		if (mini_shell[i].data.redirect_input)
		{
			doeble_point_free(mini_shell[i].data.redirect_input);
			free(mini_shell[i].data.redirect_input);
			mini_shell[i].data.redirect_input = 0;
		}
		if (mini_shell[i].data.redirect_output)
		{
			doeble_point_free(mini_shell[i].data.redirect_output);
			free(mini_shell[i].data.redirect_output);
			mini_shell[i].data.redirect_output = 0;
		}
		if (mini_shell[i].data.heredoc)
		{
			doeble_point_free(mini_shell[i].data.heredoc);
			free(mini_shell[i].data.heredoc);
			mini_shell[i].data.heredoc = 0;
		}
	}
}

void	memory_free_mini_shell_data_char_doeble8_2(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		if (mini_shell[i].data.boable_redirect_output)
		{
			doeble_point_free(mini_shell[i].data.boable_redirect_output);
			free(mini_shell[i].data.boable_redirect_output);
			mini_shell[i].data.boable_redirect_output = 0;
		}
		if (mini_shell[i].data.pipe_split)
		{
			doeble_point_free(mini_shell[i].data.pipe_split);
			free(mini_shell[i].data.pipe_split);
			mini_shell[i].data.pipe_split = 0;
		}
		i++;
	}
}

void	memory_free_mini_shell_data2_int_9(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		mini_shell[i].data2.fork_for_hd = 0;
		mini_shell[i].data2.index = 0;
		mini_shell[i].data2.flag_for_paths = 0;
		mini_shell[i].data2.pipe_count = 0;
		mini_shell[i].data2.export_number = 0;
		mini_shell[i].data2.doubl_left_index = 0;
		i++;
	}
}

void	memory_free_mini_shell_data2_char_10(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		free(mini_shell[i].data2.line);
		mini_shell[i].data2.line = 0;
		if (mini_shell[i].data2.env)
		{
			doeble_point_free(mini_shell[i].data2.env);
			free(mini_shell[i].data2.env);
			mini_shell[i].data2.env = 0;
		}
		if (mini_shell[i].data2.heredoc)
		{
			doeble_point_free(mini_shell[i].data2.heredoc);
			free(mini_shell[i].data2.heredoc);
			mini_shell[i].data2.heredoc = 0;
		}
	}
}

void	memory_free_mini_shell_data2_built_11(t_mini_shell *mini_shell)
{
	int	i;

	i = -1;
	while (mini_shell && mini_shell[0].pipe_number > ++i)
	{
		if (mini_shell[i].data2.built.hd_data)
		{
			doeble_point_free(mini_shell[i].data2.built.hd_data);
			free(mini_shell[i].data2.built.hd_data);
			mini_shell[i].data2.built.hd_data = 0;
		}
		if (mini_shell[i].data2.built.ep_data)
		{
			doeble_point_free(mini_shell[i].data2.built.ep_data);
			free(mini_shell[i].data2.built.ep_data);
			mini_shell[i].data2.built.ep_data = 0;
		}
		if (mini_shell[i].data2.built.s)
		{
			doeble_point_free(mini_shell[i].data2.built.s);
			free(mini_shell[i].data2.built.s);
			mini_shell[i].data2.built.s = 0;
		}
	}
}
