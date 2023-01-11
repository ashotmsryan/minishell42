/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_herdoc_norm1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:44:38 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:44:40 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_init(t_stract *mini, t_mini_shell *minir_shell_only)
{
	minir_shell_only->data2.built.hd_data = 0;
	minir_shell_only->data2.env = mini->env;
	minir_shell_only->data2.line = minir_shell_only->shell_for_herdoc;
	minir_shell_only->data2.doubl_left_index = minir_shell_only->data
		.doubl_left_index;
	minir_shell_only->data2.heredoc = minir_shell_only->data.heredoc;
}
