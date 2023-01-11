/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:20:41 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/01 05:29:29 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_heredoc(t_data2 *data, int len)
{
	int	i;
	int	count;

	if (data->line)
		len = ft_strlen0(data->line);
	else
		return (0);
	i = 0;
	count = 0;
	while (data->line && data->line[i] && i < len)
	{
		if (count > 16)
		{
			free_it(&data->built.hd_data);
			printf("Couldn't open that much heredoc!\n");
			exit(0);
		}
		if (data->line[i] && data->line[i + 1] && data->line[i] == '<'
			&& data->line[i + 1] == '<' && data->line[i + 2]
			&& data->line[i + 2] != 32 && (i + 2 < len))
			count++;
		i++;
	}
	return (count);
}

void	add_hd_new(t_data2 *data, char *line)
{
	char	**new_hd;
	int		j;
	int		k;

	k = 0;
	new_hd = 0;
	while (data->built.hd_data && data->built.hd_data[k])
		k++;
	new_hd = (char **)malloc(sizeof(char *) * (k + 2));
	if (!new_hd)
		return ;
	j = 0;
	while (j < k)
	{
		new_hd[j] = data->built.hd_data[j];
		j++;
	}
	new_hd[j++] = ft_strdup0(line);
	new_hd[j] = NULL;
	free(data->built.hd_data);
	data->built.hd_data = new_hd;
}

int	strlen_for_heredoc(t_data2 *data, int i, char *line_hd)
{
	int	len1;
	int	len2;
	int	len;

	len1 = 0;
	len2 = 0;
	len = 0;
	if (data && data->heredoc && data->heredoc[i])
			len1 = ft_strlen_1(data->heredoc[i]) - 2;
	else
		len1 = 0;
	if (line_hd)
		len2 = ft_strlen(line_hd);
	else
		len2 = 0;
	if (len1 >= len2)
		len = len1;
	else
		len = len2;
	return (len);
}

void	norm_hd(t_data2 *data, int i)
{
	char	*line_hd;
	int		len;

	line_hd = 0;
	line_hd = readline("> ");
	if (line_hd == NULL || !data)
		return ;
	len = strlen_for_heredoc(data, i, line_hd);
	while (ft_strncmp0(line_hd, &data->heredoc[i][2], len) != 0)
	{
		add_hd_new(data, line_hd);
		line_hd = readline("> ");
		if (line_hd == NULL)
			return ;
		if (data && line_hd)
			len = strlen_for_heredoc(data, i, line_hd);
		else
			len = 0;
	}
}

void	heredoc(t_mini_shell *x)
{
	int		heredoc_count;
	int		i;
	t_data2	*data;

	data = &x->data2;
	i = 0;
	heredoc_count = x->data.doubl_left_index;
	while (i < heredoc_count)
	{
		signal_call(2);
		if (data->built.hd_data)
			free_it(&data->built.hd_data);
		norm_hd(data, i);
		i++;
	}
}
