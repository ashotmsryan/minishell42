/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:48:03 by amsryan           #+#    #+#             */
/*   Updated: 2022/12/16 22:27:30 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <errno.h>

extern int	g_status;
typedef struct s_val
{
	char		**hd_data;
	char		**ep_data;
	char		**s;
}				t_built;
typedef struct s_data
{
	pid_t	fork_for_hd;
	int		index;
	int		flag_for_paths;
	int		pipe_count;
	int		export_number;
	int		end[2];
	int		doubl_left_index;
	char	*line;
	char	**env;
	char	**heredoc;
	t_built	built;
}				t_data2;
typedef struct sdat {
	int		id;
	int		that_cammand_number;
	int		doubl_right_index;
	int		doubl_left_index;
	int		left_index;
	int		right_index;
	int		fd_input;
	int		fd_input_pipe[2];
	int		fd_output;
	int		flag_for_output;
	int		flag_for_input;
	int		x;
	int		y;
	int		z;
	int		quote_have;
	char	**redirect_input;
	char	**redirect_output;
	char	**heredoc;
	char	**boable_redirect_output;
	char	**pipe_split;
	char	**old_pipe_split;
	char	**redirect_have;
	char	*utils;
	int		left;
	int		right;
	int		double_right;
	int		permission;
}			t_data;
typedef struct sdat1 {
	int	_stdout;
	int	_stdin;
}				t_data1;
typedef struct minir {
	pid_t	fork_main;
	int		syntax_error;
	int		when_pipe_error;
	int		error;
	int		ep_flag;
	int		pipe_number;
	int		flag_write;
	int		*access_if;
	int		*flag;
	pid_t	*forks;
	int		(*end)[2];
	char	*error_char;
	char	*pwd_current;
	char	*pwd_util;
	char	*oldpwd;
	char	*line;
	char	*path;
	char	**line_split_pipe;
	char	**line_split_pipe_mini_shell;
	char	**cmd;
	char	**env;
	char	**path_split;
	t_data1	data;
	t_data2	data2;
}			t_stract;
typedef struct minir_shell {
	int		id;
	int		flag;
	int		i_flag;
	int		m_i;
	int		flag_set_unset;
	int		when_pipe_error;
	int		error;
	int		error_char_id;
	int		index_sintex;
	int		segmenf_error;
	int		pipe_number;
	pid_t	*forks;
	int		*flag_quote;
	int		(*end)[2];
	char	*pwd_util;
	char	*oldpwd;
	char	*pwd_current;
	char	**command;
	char	*path;
	char	*pwd;
	char	*string_return;
	char	*shell_line_split_pipe;
	char	*shell_line_split_pipe_old;
	char	*shell_for_herdoc;
	char	*error_char;
	char	*verified_path;
	char	**env;
	char	**path_split;
	char	*new_len_util;
	t_data	data;
	t_data2	data2;
}			t_mini_shell;

void	for_update_free(t_stract *mini, t_mini_shell **mini_shell);
int		search_error(char *str, t_mini_shell *minir_shell,
			int i_index);
void	signal_call(int i);
void	ft_ctrl_slash(int i);
void	cd_func(t_stract *mini, int i, t_mini_shell *minir_shell);
char	*ft_getenv(char *search_key, int i, t_mini_shell *minir_shell);
char	**env_new(char **env);
void	loop_between_pipe(t_stract *mini, int i);
void	echo_func( int i, t_mini_shell *minir_shell);
void	parsing(t_stract *mini, int i, t_mini_shell *minir_shell);
void	for_that_cammand_number(t_stract *mini, int i,
			t_mini_shell *minir_shell);
char	*spease_set_unset(char *str, t_stract *mini,
			t_mini_shell *minir_shell, int i);
void	func_null(t_stract *mini, char **env);
char	*set_dolar_question_mark(char *str, t_mini_shell *minir_shell,
			int i, int m_i);
void	pipe_and_dup(t_stract *mini, int i, t_mini_shell *minir_shell);
void	error_for(int i, t_mini_shell *minir_shell);
void	parsing_1(t_stract *mini, int i, t_mini_shell *minir_shell);
void	env_change(t_stract *mini, char *search_text, char *change,
			t_mini_shell *minir_shell);
void	pwd_func(t_stract *mini, int i, t_mini_shell *minir_shell);
void	print_env_heve( int j, int i, int i_flag, t_mini_shell *minir_shell);
void	write_null_minishell(t_mini_shell *mini_shell, int number);
void	env_func(int i, t_mini_shell *minir_shell);
int		check_for_command(t_stract *mini, int i, t_mini_shell *minir_shell);
void	mini_shell_null(t_stract *mini, t_mini_shell *mini_shell);
void	heredoc(t_mini_shell *x);
int		ep_strlen(char *s);
void	change_places(t_data2 *data, int i);
int		if_sorted(t_data2 *data);
char	*ep_strdup(char *s1);
void	get_export(t_stract *mini);
void	if_exit(t_mini_shell *minir_shell, int i, t_stract *mini);
char	**quotes(char *s, int i, char flag);
void	ft_unset(int i, t_mini_shell *minir_shell, t_stract *mini);
int		spllen(char **s);
void	free_it(char ***ptr);
void	export_sorting(t_data2 *data);
int		getnmblen(int n);
int		changing_shlvl(int i, t_stract *mini, int lvl);
int		get_shlvl(t_stract *mini, int lvl);
void	kill_all(t_stract *mini, int i, t_mini_shell *minir_shell);
void	when_one_line(t_stract *mini);
int		ft_strncmp1112(const char *s1, const char *s2, size_t n);
int		syntax_error_search(t_stract *mini);
char	*ft_str_n_dup1(char *s, int x);
void	syntax_error(t_stract *mini);
int		search_error2(t_stract *mini);
int		ft_strlen_1(char *str);
int		char_tokin2(char *tokin, int *i);
int		char_tokin1(char *tokin, int *i);
int		char_tokin(char tokin);
void	malloc_start(t_stract *mini);
int		pipe_read_write(t_stract *mini, t_mini_shell *minir_shell);
void	is_len_delet_spaces(t_stract *mini, char *s);
int		func_hirdock(t_stract *mini, t_mini_shell *minir_shell);
void	heredoc_init(t_stract *mini, t_mini_shell *minir_shell_only);
int		access_func(int i, t_mini_shell *minir_shell, int j);
void	start_minishell(t_stract *mini, t_mini_shell *mini_shell);
void	func_call_accsess(int i, t_mini_shell *minir_shell);
int		file_open_for_input(int i, t_mini_shell *minir_shell);
int		file_open_for_output(int i, t_mini_shell *minir_shell);
int		input_file_have_norm(int i, t_mini_shell *minir_shell, int j);
int		input_file_have(int i, t_mini_shell *minir_shell);
int		search_path_input_file(char *path_file, int i, int j,
			t_mini_shell *minir_shell);
int		if_directory(int i, t_mini_shell *minir_shell);
int		diyrectory(int i, t_mini_shell *minir_shell);
void	set_psyntex_error(char *command, t_stract *mini, int i,
			t_mini_shell *minir_shell);
void	flag(int i, t_mini_shell *minir_shell);
int		parsing_norm1(int i, t_mini_shell *minir_shell, char **command, int *j);
int		parsing_for_norm(int i, t_mini_shell *minir_shell,
			int *len, char **command);
void	parsing_norm2(int i, t_mini_shell *minir_shell, int j, char	**command);
void	syntax_error_search1(char *str, t_mini_shell *minir_shell,
			int j, int k);
void	syntax_error_search2(char *str, t_mini_shell *minir_shell,
			int j, int k);
char	*parsing_one_pipe(char *str, int j);
int		if_big_big(char *str, int *k, t_mini_shell *minir_shell, int i);
int		if_39_str(char *str, t_stract *mini, t_mini_shell *minir_shell, int *k);
void	if_34_str(char *str, int *k, int *j);
int		if_smol_smol(char *str, int *k, t_mini_shell *minir_shell, int i);
int		env_one_strline_write(char *str, int *i, char *string_return,
			t_mini_shell *minir_shell);
void	env_one_strline_write_norm(char	*dollar_valu_utils,
			char *string_return, int *k);
int		itoa_namber(int signal);
void	env_one_strline_norm(char *str, int *l);
int		env_one_strline(char *str, int *i,
			t_mini_shell *minir_shell, int i_flag);
char	*write_new_words(char *str, int j, t_mini_shell *minir_shell);
void	itoa_string(char *string_return, int *j, int signal);
size_t	hd_strlen(char *s1, char *s2);
int		env_strlen_ps(char *str);
int		if_export(t_mini_shell *minir_shell, int l, t_stract *mini);
int		norm_find_dbl(char *s1, char *s2, int len, int i);
int		find_dbl(char **tmp, char *s, int flag);
char	*del_plus(char **s, int flag);
void	t_data_free_char_doeble_point(t_stract *mini);
void	t_data_free_char_doeble_point_norm(t_stract *mini);
void	t_data_data2_int(t_stract *mini);
void	t_data_data2_char(t_stract *mini);
void	t_data_data2_built(t_stract *mini);
void	t_data_int_free1(t_stract *mini);
void	t_data_free_char_one_point(t_stract *mini);
void	doeble_point_free(char **str);
void	memory_free_mini(t_stract *mini);
void	memory_free_mini_shell_data_int6(t_mini_shell *mini_shell);
void	memory_free_mini_shell_int1(t_mini_shell *mini_shell);
void	memory_free_mini_shell_doeble_int2(t_mini_shell *mini_shell);
void	memory_free_mini_shell_char3(t_mini_shell *mini_shell);
void	memory_free_mini_shell_char4(t_mini_shell *mini_shell);
void	memory_free_mini_shell_char_doeble5(t_mini_shell *mini_shell);
void	memory_free_mini_shell_data_char_doeble8_1(t_mini_shell *mini_shell);
void	memory_free_mini_shell_data_char_doeble8_2(t_mini_shell *mini_shell);
void	memory_free_mini_shell_data2_int_9(t_mini_shell *mini_shell);
void	memory_free_mini_shell_data2_char_10(t_mini_shell *mini_shell);
void	memory_free_mini_shell_data2_built_11(t_mini_shell *mini_shell);
void	memory_free_t_mini_shell(t_mini_shell *mini_shell);
void	update_for_start_agen(t_stract *mini, t_mini_shell *mini_shell);
void	free_all_78(t_stract **mini, t_mini_shell **mini_shell);
char	**ft_strdupdoub(char **str);
int		ft_strncmp_pars_new(const char *s1, const char *s2, size_t n);
int		ft_len_doeble_pars(char **str);
int		parsing_new(int i, t_mini_shell *minir_shell);
void	pars_redirect1(int i, int j, t_mini_shell *minir_shell,
			char	**command);
void	pars_redirect2(int i, int j, t_mini_shell *minir_shell,
			char	**command);
void	pars_redirect4(int i, int j, t_mini_shell *minir_shell,
			char	**command);
void	pars_redirect3(int i, int j, t_mini_shell *minir_shell,
			char	**command);
void	pars_redirect_not(int i, int j,
			t_mini_shell *minir_shell, char	**command);
void	parsing_new_redirect1(int i, t_mini_shell *minir_shell, int len);
int		parsing_new_r(int i, t_mini_shell *minir_shell);
void	pars_unset_qouts_herdoc(int i, t_mini_shell *minir_shell);
void	pars_have_redirect(int i, int j, t_mini_shell *minir_shell,
			char**command);
void	pars_unset_dolar_data_pipe_split(int i, t_mini_shell *minir_shell);
int		have_env_dolar(char *str, int *i, t_mini_shell *minir_shell);
int		have_env_dolar_set(char *str, int *i, char *string_return,
			t_mini_shell *minir_shell);
char	*pars_ft_getenv_pars(char *search_key, t_mini_shell *minir_shell);
void	set_dolar_new(char *str, t_mini_shell *minir_shell, int len);
int		go_for_double_qout_malloc(char	*str, char search,
			char *new_str, int *l);
int		pars_unset_qouts_norm(char *str, int *quote_have);
int		go_for_double_qout(int *j, char *str, char search);
void	pars_unset_quots_data_pipe_split(int i, t_mini_shell *minir_shell);
void	pars_go_for_double_quote_norm(int *i, int *j, char *str,
			t_mini_shell *minir_shell);
void	go_for_double_quote(int *i, int *j, char *str,
			t_mini_shell *minir_shell);
void	go_for_dolar(int *i, int *j, char *str);
int		set_dolar(char *str, t_mini_shell *minir_shell);
void	pars_unset_dolar_data_redirect_output(int i,
			t_mini_shell *minir_shell);
void	pars_unset_dolar_data_redirect_boable_redirect_output(int i,
			t_mini_shell *minir_shell);
void	pars_unset_dolar_data_redirect_input(int i, t_mini_shell *minir_shell);
void	pars_unset_quots_data_redirect_output(int i, t_mini_shell *minir_shell);
void	pars_unset_quots_data_redirect_input(int i, t_mini_shell *minir_shell);
void	pars_unset_quots_data_redirect_boable_redirect_output(int i,
			t_mini_shell *minir_shell);
int		sumbol_is(char *str);
void	wait_close_dup(t_stract *mini, t_mini_shell *minir_shell);
int		when_have_redirect(t_stract *mini, int i, t_mini_shell *minir_shell);
int		ft_strlen_double(char **str);
int		set_dolar_changed11(char *str, t_mini_shell *minir_shell);
char	*ft_getcwd(int i, t_mini_shell *minir_shell);
int		pars_search_fd_input(t_mini_shell *minir_shell);
int		pars_search_fd_output2(t_mini_shell *minir_shell);
int		pars_diyrectory(char *str);
int		pars_search_fd_output1(t_mini_shell *minir_shell);
int		fork_or_parent_start(t_stract *mini, int i, t_mini_shell *minir_shell);
void	where_output(t_mini_shell *minir_shell, int flag);
int		itoa_string_ads1(char *string_return, int *j, int signal);
void	evry(t_stract *mini, t_mini_shell *minir_shell);
void	cd_func_b(t_stract *mini, int *iflag, int i, t_mini_shell *minir_shell);
void	cd_f_m_no(t_stract *mini, int *iflag, int i, t_mini_shell *minir_shell);
void	cd_fu_b_n(t_stract *mini, int *iflag, int i, t_mini_shell *minir_shell);
void	cd_func_n(t_stract *mini, int i, t_mini_shell *minir_shell);
int		norm_find_and_add(char *tmp, t_data2 *data, char *s, int j);
void	nnnn_adding_export_plus(t_data2 *data, char *s, char **ptr, int k);
void	nn_adding_export_plus(t_data2 *data, char *s, int k, int i);
void	adding_export_plus(t_data2 *data, char *s, int k, int flag);
char	*nnorm_find_and_add(char *s, char *dup);
int		n_find_same(char *s2, char *s);
void	add_in_env(t_data2 *data, char *s, t_stract *mini);
void	add_in_env_plus(t_data2 *data, char *s, t_stract *mini);
void	find_and_add(t_data2 *data, char *s, t_stract *mini);
int		nnn_find_same(char *s, char *s1, char **tmp, int len);
int		nn_find_same(char **tmp, char *s, int len);
int		find_same(char **tmp, char *s, int flag);
char	**norm_find_and_replace(t_data2 *data, char *s1, int len, char *s);
void	find_and_replace(t_data2 *data, char *s, t_stract *mini);
int		re_malloc(t_data2 *data, char *s, t_stract *mini);
void	nnn_add_in_export(t_data2 *data, char *s, int flag, t_stract *mini);
void	export_sorting(t_data2 *data);
void	add_in_export(t_data2 *data, char *s, t_stract *mini);
int		nnn_check_validation(char *splited, int j, char *cmd);
int		check_validation_ep(char *splited, char *cmd);
char	**env_replace(t_data2 *data, char **tmp, char *s);
int		find_same_env(char **tmp, char *s);
void	norm_plus_env(char *s, t_data2 *data, t_stract *mini, int i);
void	add_env(t_data2 *data, char *s, t_stract *mini);
char	*env_repl_norm(char *s);
char	*dupp(char *s, int len);
int		norm_unset_ep(char *key, char *s1, int len);
void	unset_ep(t_data2 *data, int place, t_stract *mini);
int		ft_unset_n(t_data2 *data, int j, t_mini_shell *minir_shell,
			t_stract *mini);
int		env_change_norm(t_mini_shell *minir_shell, char *chg, char *s_t);
void	new_line(t_stract *mini, int j, int k);
void	close_input_output_2(int i, t_mini_shell *minir_shell);
int		p_s_fd_o2_n_n( t_mini_shell *minir_shell);
int		pars_search_fd_output2_norm(char *path_file,
			t_mini_shell *minir_shell);
int		pars_search_fd_output2(t_mini_shell *minir_shell);
void	pars_unset_quots_data_pipe_split(int i, t_mini_shell *minir_shell);
void	pars_set_zro(int i, t_mini_shell *minir_shell, int a);
char	*pars_unset_quots_data_pipe_split_norm(int i, t_mini_shell *minir_shell,
			int a, int l);
void	pars_3(char	*new_str, int a, int i, t_mini_shell *minir_shell);
char	*pars_unset_quots_data_redirect_output_norm(int i,
			t_mini_shell *minir_shell, int a, int l);
void	for_puqdri_1(int a, char *new_str, int i, t_mini_shell *minir_shell);
void	pars_unset_quots_data_redirect_input(int i, t_mini_shell *minir_shell);
void	new_str_puq(char *new_str, int a, int i, t_mini_shell *minir_shell);
int		go_for_double_qout(int *j, char *str, char search);
int		pars_unset_qouts_norm(char *str, int *quote_have);
void	heredoc_when_output(t_mini_shell *minir_shell, int i);
int		func_hirdock_norm1(t_mini_shell *minir_shell, int *i);
int		func_hirdock(t_stract *mini, t_mini_shell *minir_shell);
void	heredoc_when_output_norm(t_mini_shell *minir_shell, int i, int *jx);
void	when_input_not_is_hirdoc(t_mini_shell *minir_shell, int i);
char	*pars_unset_quots_data_redirect_input_norm(int i,
			t_mini_shell *minir_shell, int a, int l);
void	go_for_double_quote1(int *i, int *j, char *str,
			t_mini_shell *minir_shell);
void	pars_go_for_double_quote_norm3(int *i, int *j, char *str,
			t_mini_shell *minir_shell);
void	find_asddbl(char **s1, int flag, int *i);
int		syntacs_error_search_5(char *str, t_stract *mini, int i);
void	cd_func_normin1(t_stract *mini, int *iflag, int i,
			t_mini_shell *minir_shell);
void	nn_find_same_norm1(char	*s2, int *l);
void	print_error_prmishn(char *str, char *err);
void	ft_putstr_2(char *err, char *arg);
void	pars_unset_dolar_data_pipe_split(int i, t_mini_shell *minir_shell);
int		parsing_new_r_for_herdoc(int i, t_mini_shell *minir_shell);
void	new_pars_dolar_s(int i, t_mini_shell *minir_shell);
void	parsing_new_redirect11(int i, t_mini_shell *minir_shell, int len);
int		ft_strncmp2(const char *s1, const char *s2, size_t n);
void	cd_func_tilda_notarg_cd_new_norm(t_stract *mini,
			int i, t_mini_shell *minir_shell);

#endif
