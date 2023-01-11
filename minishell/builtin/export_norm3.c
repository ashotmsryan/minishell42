/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_norm3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:27:50 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/09 21:30:27 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	re_malloc(t_data2 *data, char *s, t_stract *mini)
{
	int		j;
	int		i;
	char	**tmp;

	j = -1;
	i = spllen(data->built.ep_data);
	tmp = (char **)malloc((i + 2) * sizeof (char *));
	while (data->built.ep_data && data->built.ep_data[++j])
		tmp[j] = ft_strdup0(data->built.ep_data[j]);
	tmp[j] = ep_strdup(s);
	tmp[j + 1] = NULL;
	free_it(&data->built.ep_data);
	data->built.ep_data = tmp;
	mini->data2.built.ep_data = tmp;
	return (0);
}

void	export_sorting(t_data2 *data)
{
	int	i;

	i = 0;
	while (if_sorted(data) == 1)
	{
		if (!data->built.ep_data[i])
			i = 0;
		if (data->built.ep_data[i] && data->built.ep_data[i + 1]
			&& (ft_strncmp0(data->built.ep_data[i],
					data->built.ep_data[i + 1],
					ep_strlen(data->built.ep_data[i])) > 0))
		{
			change_places(data, i);
			i = 0;
		}
		i++;
	}
}

void	nnn_add_in_export(t_data2 *data, char *s, int flag, t_stract *mini)
{
	int		i;
	char	**tmp;

	i = -1;
	while (data->built.ep_data && data->built.ep_data[++i])
		;
	data->export_number = i;
	tmp = data->built.ep_data;
	if (flag == 1 && (find_same(tmp, s, flag) == 1))
		find_and_replace(data, s, mini);
	else if (flag == 0 && (find_same(tmp, s, flag) == 1))
		;
	else if ((find_same(tmp, s, flag) == 0))
		re_malloc(data, s, mini);
	export_sorting(data);
}

void	add_in_export(t_data2 *data, char *s, t_stract *mini)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=')
		flag = 1;
	if (s[i] == '=' && s[i - 1] == '+')
		find_and_add(data, s, mini);
	else
		nnn_add_in_export(data, s, flag, mini);
}

int	nnn_check_validation(char *splited, int j, char *cmd)
{
	if ((splited[0] && ft_isalpha0(splited[0]) == 0
			&& splited[0] != '_'))
	{
		printf("minishell: %s: `%s': not a valid identifier\n", cmd,
			splited);
		return (1);
	}
	if (splited[j] && ((!splited[j + 1] && splited[j] == '+')
			|| (splited[j + 1] && splited[j] == '+' && splited[j + 1] != '=')))
	{
		printf("minishell: %s: `%s': not a valid identifier\n", cmd,
			splited);
		return (1);
	}
	if (splited[0] && ((ft_isalpha0(splited[0]) == 0)
			&& (splited[0] != '_')))
	{
		printf("minishell: %s: `%s': not a valid identifier\n", cmd,
			splited);
		return (1);
	}
	return (0);
}
