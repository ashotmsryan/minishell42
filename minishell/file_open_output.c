/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:42:07 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 04:31:38 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	output_file(int i, t_mini_shell *minir_shell)
{
	int	j;

	j = -1;
	if (minir_shell[i].data.right_index)
	{
		while (++j < minir_shell[i].data.right_index)
		{
			close(minir_shell[i].data.fd_output);
			minir_shell[i].data.fd_output = open(
					minir_shell[i].data.redirect_output[j] + 1,
					O_WRONLY | O_TRUNC | O_CREAT, 0644);
			if (minir_shell[i].data.fd_output == -1)
			{
				minir_shell[i].error_char = minir_shell[i]
					.data.redirect_output[j] + 1;
				g_status = 1;
				return (0);
			}
		}
	}
	return (1);
}

int	output_file_double(int i, t_mini_shell *minir_shell)
{
	int	j;

	j = -1;
	if (minir_shell[i].data.doubl_right_index)
	{
		while (++j < minir_shell[i].data.doubl_right_index)
		{
			close(minir_shell[i].data.fd_output);
			minir_shell[i].data.fd_output = open(minir_shell[i]
					.data.boable_redirect_output[j] + 2,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (minir_shell[i].data.fd_output == -1)
			{
				minir_shell[i].error_char = minir_shell[i]
					.data.boable_redirect_output[j] + 2;
				g_status = 1;
				return (0);
			}
		}
	}
	return (1);
}

int	file_open_for_output1(int i, t_mini_shell *minir_shell)
{
	if (output_file(i, minir_shell) == 0)
	{
		g_status = 1;
		minir_shell[i].error = 7;
		return (0);
	}
	if (output_file_double(i, minir_shell) == 0)
	{
		g_status = 1;
		minir_shell[i].error = 7;
		return (0);
	}
	return (1);
}

int	file_open_for_output(int i, t_mini_shell *minir_shell)
{
	if (minir_shell[i].data.flag_for_output == 1
		|| minir_shell[i].data.flag_for_output == 2)
	{
		if (minir_shell[i].data.flag_for_output == 1)
		{
			if (output_file_double(i, minir_shell) == 0)
			{
				g_status = 1;
				minir_shell[i].error = 7;
				return (0);
			}
			if (output_file(i, minir_shell) == 0)
			{
				g_status = 1;
				minir_shell[i].error = 7;
				return (0);
			}
		}
		else if (minir_shell[i].data.flag_for_output == 2)
			if (file_open_for_output1(i, minir_shell) == 0)
				return (0);
	}
	return (1);
}
