/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:24:38 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/09 19:28:19 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_change_norm(t_mini_shell *minir_shell, char *chg, char *s_t)
{
	int		k;

	k = -1;
	while (minir_shell->env[++k])
	{
		if (ft_strncmp0(s_t, minir_shell->env[k], ft_strlen(s_t)) == 0)
		{
			free(minir_shell->env[k]);
			minir_shell->env[k] = 0;
			minir_shell->env[k] = ft_strjoin(s_t, chg);
			return (-1);
		}
	}
	return (k);
}

char	*ft_getenv(char *search_key, int i, t_mini_shell *minir_shell)
{
	int	k;

	k = 0;
	while (minir_shell[i].env[k])
	{
		if (ft_strncmp(minir_shell[i].env[k],
				search_key, ft_strlen(search_key)) == 0)
			return (&(minir_shell[i].env[k][ft_strlen(search_key)]));
		k++;
	}
	return (NULL);
}

void	evry(t_stract *mini, t_mini_shell *minir_shell)
{
	int	i;

	i = 0;
	while (i < minir_shell[0].pipe_number)
	{
		minir_shell[i].env = mini->env;
		minir_shell[i].data2.env = mini->env;
		i++;
	}
}
