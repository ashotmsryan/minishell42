/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:57:36 by hvardany          #+#    #+#             */
/*   Updated: 2022/11/16 16:34:00 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

long long	ft_atoi0(const char *str);
int			ft_isalpha0(int i);
int			ft_isdigit0(int i);
char		*ft_strdup0(const char *s1);
char		*ft_strjoin0(char *s1, char *s2);
int			ft_strlen0(char *str);
int			ft_strncmp0(char *s1, char *s2, size_t n);
char		*ft_itoa0(int n);
char		*ft_strchr0(char *s, int c);
char		*ft_strndub(char *str, int n);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_strjoin_double_point(char **split, char *str);
char		*ft_strjoin1(char *s1, char const *s2);
char		*ft_strjoin2(char *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		**ft_split_line1(char *s, char c);
char		*ft_str_n_dup(const char *s, int x);
char		*ft_strdup(char *s1);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		**ft_split_line(char const	*s, char c);
size_t		l_nlen(char const *s, char c);
int			ft_strindex(char *s, int x, int y);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp1(const char *s1, const char *s2, size_t n);
int			ft_strncmp111(const char *s1, const char *s2, size_t n);
void		clearfree(char **sm, size_t j);
size_t		l_nlen(char const *s, char c);
size_t		len_till(const char *s, char c);
char		*norm_sets(const char *s, char c, char *sm);

#endif
