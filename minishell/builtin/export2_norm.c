/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:44 by amsryan           #+#    #+#             */
/*   Updated: 2022/11/30 23:28:01 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ep_strlen(char *s)
{
	int		flag;
	int		size;

	flag = 0;
	size = -1;
	while (s && s[++size])
	{
		if (s[size] == '=')
		{
			flag++;
			break ;
		}
	}
	size = 0;
	if (flag == 1)
		while (s && s[size] && !((s[size] == '=') || (s[size] == '+'
					&& s[size + 1] && s[size + 1] == '=')))
			size++;
	else
		while (s && s[size] != '\0')
			size++;
	return (size);
}

int	if_sorted(t_data2 *data)
{
	int	i;

	i = -1;
	while (data->built.ep_data[++i])
	{
		if (data->built.ep_data[i + 1]
			&& (ft_strncmp0(data->built.ep_data[i],
					data->built.ep_data[i + 1],
					ep_strlen(data->built.ep_data[i])) > 0))
			return (1);
	}
	return (0);
}

void	change_places(t_data2 *data, int i)
{
	char	*s;

	s = data->built.ep_data[i];
	data->built.ep_data[i] = data->built.ep_data[i + 1];
	data->built.ep_data[i + 1] = s;
}

void	old_pwd_get(t_data2 *data, char *oldpwd)
{
	char	**new;
	int		i;
	char	*s;

	i = -1;
	s = "declare -x ";
	new = (char **)malloc((spllen(data->built.ep_data) + 2) * sizeof(char *));
	while (data->built.ep_data[++i])
		new[i] = ft_strdup0(data->built.ep_data[i]);
	new[i] = ft_strdup(s);
	new[i] = ft_strjoin0(new[i], oldpwd);
	new[++i] = NULL;
	free_it(&data->built.ep_data);
	data->built.ep_data = new;
}

void	get_export(t_stract *mini)
{
	int		l;
	t_data2	*data;

	l = -1;
	data = &mini->data2;
	data->built.ep_data = malloc(sizeof(char *) * (spllen(mini->env) + 1));
	if (!data->built.ep_data)
	{
		printf("ERROR\n");
		exit(1);
	}
	while (mini->env[++l])
		data->built.ep_data[l] = ep_strdup(mini->env[l]);
	data->built.ep_data[l] = NULL;
	old_pwd_get(data, "OLDPWD");
	export_sorting(data);
	mini->data2.built.ep_data = data->built.ep_data;
}
