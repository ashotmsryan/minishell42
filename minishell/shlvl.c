/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:19:12 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/15 05:49:20 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	changing_shlvl(int i, t_stract *mini, int lvl)
{
	char		*ptr;

	ptr = "SHLVL=";
	free(mini->env[i]);
	mini->env[i] = ft_strdup0(ptr);
	if (lvl != -1)
	{
		ptr = ft_itoa0(lvl + 1);
		mini->env[i] = ft_strjoin0(mini->env[i], ptr);
		free(ptr);
	}
	return (lvl);
}

int	get_shlvl(t_stract *mini, int lvl)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (ft_strncmp0(mini->env[i], "SHLVL", 5) != 0)
		i++;
	if (mini->env[i] != NULL)
	{
		tmp = ft_strdup0(ft_strchr0(mini->env[i], '='));
		lvl = ft_atoi0(&tmp[1]);
		if (lvl >= 1000)
		{
			printf("minishell: warning: shell ");
			printf("level (%d) too high, resetting to 1\n", lvl);
			lvl = 0;
		}
		else if (lvl == 999)
			lvl = -1;
		free (tmp);
		lvl = changing_shlvl(i, mini, lvl);
	}
	return (lvl);
}
