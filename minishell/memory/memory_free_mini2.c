/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_mini2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:39:45 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:05:10 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	doeble_point_free(char **str)
{
	int	i;

	i = -1;
	if (!str && !str[0])
		return ;
	while (str[++i])
	{
		free(str[i]);
		str[i] = 0;
	}
}

void	t_data_int_free1(t_stract *mini)
{
	int	i;

	i = 0;
	mini->fork_main = 0;
	mini->syntax_error = 0;
	mini->when_pipe_error = 0;
	mini->error = 0;
	mini->ep_flag = 0;
	mini->flag_write = 0;
	free(mini->access_if);
	mini->access_if = 0;
	free(mini->flag);
	mini->flag = 0;
	free(mini->forks);
	mini->forks = 0;
	free(mini->end);
	mini->end = 0;
}

void	t_data_free_char_one_point(t_stract *mini)
{
	free(mini->error_char);
	mini->error_char = 0;
	free(mini->pwd_current);
	mini->pwd_current = 0;
	free(mini->pwd_util);
	mini->pwd_util = 0;
	free(mini->oldpwd);
	mini->oldpwd = 0;
	free(mini->line);
	mini->line = 0;
}

void	t_data_data2_built(t_stract *mini)
{
	if (mini->data2.built.hd_data)
	{
		doeble_point_free(mini->data2.built.hd_data);
		free(mini->data2.built.hd_data);
		mini->data2.built.hd_data = 0;
	}
	if (mini->data2.built.s)
	{
		doeble_point_free(mini->data2.built.s);
		free(mini->data2.built.s);
		mini->data2.built.s = 0;
	}
}
