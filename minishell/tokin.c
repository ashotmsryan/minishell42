/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:47:04 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/08 20:47:07 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	char_tokin(char tokin)
{
	if (tokin)
	{
		if (tokin == '|')
			return (1);
		if (tokin == ';')
			return (2);
		if (tokin == ')')
			return (3);
	}
	return (0);
}

int	char_tokin1_norm(char *tokin, int *i)
{
	if (tokin && tokin[*i] && tokin[*i] == '|')
	{
		*i += 1;
		return (1);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>'
		&& tokin[*i + 1] && tokin[*i + 1] == '>')
	{
		*i += 2;
		return (6);
	}
	return (0);
}

int	char_tokin1(char *tokin, int *i)
{
	int	l;

	l = char_tokin1_norm(tokin, i);
	if (l > 0)
		return (l);
	if (tokin && tokin[*i] && tokin[*i] == '<'
		&& tokin[*i + 1] && tokin[*i + 1] == '<')
	{
		*i += 2;
		return (7);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<')
	{
		*i += 1;
		return (8);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>')
	{
		*i += 1;
		return (5);
	}
	return (0);
}

int	char_tokin2(char *tokin, int *i)
{
	if (tokin && tokin[*i] && tokin[*i] == '>'
		&& tokin[*i + 1] && tokin[*i + 1] == '>')
	{
		*i += 2;
		return (6);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<'
		&& tokin[*i + 1] && tokin[*i + 1] == '<')
	{
		*i += 2;
		return (7);
	}
	if (tokin && tokin[*i] && tokin[*i] == '<')
	{
		*i += 1;
		return (8);
	}
	if (tokin && tokin[*i] && tokin[*i] == '>')
	{
		*i += 1;
		return (5);
	}
	return (0);
}
