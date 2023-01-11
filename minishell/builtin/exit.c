/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:28:49 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/12 14:27:08 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>

char	**check_quotes(t_data2 *data)
{
	char	**ptr;
	int		j;
	int		i;
	int		l;

	l = -1;
	ptr = (char **) malloc (sizeof (char *) * 3);
	while (data->built.s && data->built.s[++l])
	{
		ptr[l] = malloc(sizeof(char) * (ft_strlen0(data->built.s[l]) + 1));
		j = 0;
		i = -1;
		while (data->built.s && data->built.s[l] && data->built.s[l][j])
		{
			if (data->built.s[l][j] == '\"' || data->built.s[l][j] == '\'')
				j++;
			ptr[l][++i] = data->built.s[l][j];
			if (data->built.s[l][j])
				j++;
		}
		ptr[l][++i] = '\0';
	}
	ptr[l] = NULL;
	free_it(&data->built.s);
	return (ptr);
}

void	numeric_error(t_data2 *data, t_mini_shell *minir_shell, t_stract *mini)
{
	int	i;

	i = -1;
	while (data->built.s && data->built.s[1] && data->built.s[1][++i])
	{
		if ((data->built.s && data->built.s[1] && (data->built.s[1][i] == '+'
				|| data->built.s[1][i] == '-')
				&& (data->built.s[1][i + 1] == '+'
			|| data->built.s[1][i + 1] == '-'))
			|| (data->built.s && data->built.s[1] && (data->built.s[1][i] < 48
			|| data->built.s[1][i] > 57) && data->built.s[1][i] != '-'
			&& data->built.s[1][i] != '+'))
		{
			printf("exit\n");
			ft_putstr_2("minishell: exit: ", data->built.s[1]);
			ft_putstr_2(": numeric argument required\n", NULL);
			free_all_78(&mini, &minir_shell);
			exit(255);
		}
	}
}

void	l_range_error(long long status, t_data2 *data,
	t_mini_shell *minir_shell, t_stract *mini)
{
	unsigned int	ustatus;
	int				plus;

	ustatus = 0;
	plus = 0;
	if (data->built.s && data->built.s[1] && data->built.s[1][0]
		&& data->built.s[1][0] == '-')
		plus = 1;
	if ((ft_strncmp0("9223372036854775808", &data->built.s[1][1], 19) < 0
		&& plus == 1) || ft_strlen0(data->built.s[1]) > 19
		|| ft_strncmp0("9223372036854775807", data->built.s[1], 19) < 0)
	{
		printf("exit\n");
		ft_putstr_2("minishell: exit: ", data->built.s[1]);
		ft_putstr_2(": numeric argument required\n", NULL);
		free_all_78(&mini, &minir_shell);
		exit(255);
	}
	if (status >= LONG_MIN && status <= 9223372036854775807)
	{
		printf("exit\n");
		ustatus = (unsigned int)status;
		free_all_78(&mini, &minir_shell);
		exit(ustatus);
	}
}

int	if_exitnorm(t_data2 *data, t_stract *mini, t_mini_shell *minir_shell, int f)
{
	if (f == 1)
	{
		if (data->built.s && data->built.s[1][0]
			&& ft_isalpha0(data->built.s[1][0]) == 1)
		{
			printf("exit\n");
			ft_putstr_2("minishell: exit: ", data->built.s[1]);
			ft_putstr_2(": numeric argument required\n", NULL);
			free_all_78(&mini, &minir_shell);
			exit (255);
		}
		if (mini->pipe_number == 1 && minir_shell->flag == 1)
			printf("exit\n");
		ft_putstr_2("minishell: exit: too many arguments\n", NULL);
		g_status = 1;
		return (1);
	}
	else if (f == 0)
	{
		data->built.s = check_quotes(data);
		numeric_error(data, minir_shell, mini);
		g_status = ft_atoi0(data->built.s[1]);
		l_range_error(g_status, data, minir_shell, mini);
	}
	return (0);
}

void	if_exit(t_mini_shell *minir_shell, int f, t_stract *mini)
{
	int				i;
	t_data2			*data;

	i = 0;
	data = &minir_shell[f].data2;
	data->built.s = ft_split(minir_shell[f].shell_line_split_pipe, ' ');
	while (data->built.s && data->built.s[i])
		i++;
	if (i > 2)
	{
		if (if_exitnorm(data, mini, minir_shell, 1) == 1)
			return ;
	}
	else if (i == 1)
	{
		free_all_78(&mini, &minir_shell);
		printf("exit\n");
		exit(g_status);
	}
	else
		if_exitnorm(data, mini, minir_shell, 0);
}
