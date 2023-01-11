/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:47:22 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 21:08:57 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	when_one_line(t_stract *mini)
{
	if (mini->line && mini->line[0])
		printf("minishell: %s : command not found\n", mini->line);
}

void	itoa_string(char *string_return, int *j, int signal)
{
	char	*s;
	int		i;

	i = 0;
	s = 0;
	if (!j || !string_return)
		return ;
	s = ft_itoa(signal);
	while (s[i])
	{
		string_return[(*j)++] = s[i];
		i++;
	}
	free(s);
}

int	itoa_string_ads1(char *string_return, int *j, int signal)
{
	char	*s;
	int		i;

	i = 0;
	s = 0;
	if (!j || !string_return)
		return (0);
	s = ft_itoa(signal);
	while (s[i])
	{
		string_return[(*j)++] = s[i];
		i++;
	}
	free(s);
	return (i);
}
