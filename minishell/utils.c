/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:27:10 by hvardany          #+#    #+#             */
/*   Updated: 2022/12/15 05:51:51 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	spllen(char **s)
{
	int	i;

	i = 0;
	if (s && !s[i])
		return (1);
	while (s && s[i])
		i++;
	return (i);
}

int	getnmblen(int n)
{
	int	count;

	count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	kill_all(t_stract *mini, int i, t_mini_shell *minir_shell)
{
	int	j;

	(void)mini;
	(void)minir_shell;
	j = -1;
	i = 0;
	while (mini->forks[++j] != -1)
		kill(mini->forks[j], SIGKILL);
	printf("minishell: fork: Resource temporarily unavailable\n");
}

int	norm_find_dbl(char *s1, char *s2, int len, int i)
{
	int	j;
	int	place;

	j = -1;
	place = -1;
	while (s2 && s2[++j] && s2[j] != '=')
		s2[j] = '\0';
	if (j > len)
		len = j;
	if (ft_strncmp0(s1, s2, len) == 0)
		place = i;
	free(s2);
	return (place);
}

int	find_dbl(char **tmp, char *s, int flag)
{
	int		i;
	int		len;
	char	*s1;
	char	*s2;

	i = -1;
	s1 = ft_strdup(s);
	find_asddbl(&s1, flag, &i);
	len = i;
	i = -1;
	while (tmp && tmp[++i])
	{
		s2 = ft_strdup(tmp[i]);
		flag = norm_find_dbl(s1, s2, len, i);
	}
	free(s1);
	return (i - 1);
}
