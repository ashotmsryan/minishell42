/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_t_mini_shell.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:39:57 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 06:18:19 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	memory_free_mini_shell_data_int6(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		mini_shell[i].data.id = 0;
		mini_shell[i].data.that_cammand_number = 0;
		mini_shell[i].data.doubl_right_index = 0;
		mini_shell[i].data.doubl_left_index = 0;
		mini_shell[i].data.left_index = 0;
		mini_shell[i].data.right_index = 0;
		mini_shell[i].data.fd_input = -1;
		mini_shell[i].data.fd_output = -1;
		mini_shell[i].data.flag_for_output = 0;
		mini_shell[i].data.flag_for_input = 0;
		mini_shell[i].data.x = 0;
		mini_shell[i].data.y = 0;
		mini_shell[i].data.z = 0;
		i++;
	}
}

void	memory_free_mini_shell_int1(t_mini_shell *mini_shell)
{
	int	i;

	i = 0;
	while (mini_shell && mini_shell[0].pipe_number > i)
	{
		mini_shell[i].id = 0;
		mini_shell[i].flag = 0;
		mini_shell[i].i_flag = 0;
		mini_shell[i].m_i = 0;
		mini_shell[i].flag_set_unset = 0;
		mini_shell[i].when_pipe_error = 0;
		mini_shell[i].error = 0;
		mini_shell[i].index_sintex = 0;
		mini_shell[i].segmenf_error = 0;
		i++;
	}
}

void	memory_free_t_mini_shell(t_mini_shell *mini_shell)
{
	memory_free_mini_shell_data_int6(mini_shell);
	memory_free_mini_shell_int1(mini_shell);
	memory_free_mini_shell_doeble_int2(mini_shell);
}
