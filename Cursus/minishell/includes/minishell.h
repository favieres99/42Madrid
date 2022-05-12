/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:05:27 by jballest          #+#    #+#             */
/*   Updated: 2021/11/05 12:38:19 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# define D_QUOTE '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"
# define CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define ERROR_PIPE "minishell: syntax error near unexpected token `|'\n"
# define ERROR_DIR "No such file or directory\n"
# define ERROR_HOME "minishell: cd: HOME not set\n"
# define ERROR_CMD "command not found\n"

extern char	**environ;
typedef struct s_env
{
	char	**env;
	int		len;
	char	**key;
	char	**content;
	int		index;
}			t_env;

typedef struct s_split
{
	int		n_comand;
	int		ini;
	int		len;
	int		q;
	int		qtt_pipe;
}			t_split;

typedef struct s_token
{
	char	*to_print;
	char	*to_exec;
	char	quote;
	char	*end;
	char	*new;
	int		i;
	int		init;
	int		len;
	int		posic;
}			t_token;

/*
** Struct heart of minishell
** line_read -> initial line
** commands[50] -> initial line splitted in (| > <)
** tokens -> commands splitted in (' ')
** path -> PATH splitted in (:)
*/
typedef struct s_struct
{
	int		ret_number;
	bool	is_builtin;
	bool	has_flag;
	int		is_append;
	int		last_redir;
	int		out_fd;
	int		in_fd;
	int		num_tokens;
	int		c;
	char	quote;
	char	*line;
	char	*line_read;
	char	*name_file;
	char	*error_name_file;
	char	*home;
	char	*commands[50];
	char	*token_aux;
	char	**tokens;
	char	**path;
	t_env	env_aux;
	t_env	env;
	t_split	split;
	t_token	token;
}			t_struct;

void	split_cmd(t_struct *mini, char *in, int i);
void	is_builtin(char *cmd, t_struct *mini);
void	run_builtin(t_struct *mini);
char	*find_env(t_struct *mini, char *needle);
int		ft_cd(t_struct *mini);
void	ft_echo(t_struct *mini);
void	ft_env(t_struct *mini);
void	create_env(t_struct *mini, char **my_env);
void	ft_exit(t_struct *mini);
void	free_char_array(char **array);
void	free_char_array2(char **array);
void	ft_export(t_struct *mini);
void	ft_pwd(t_struct *mini);
char	*get_cwd_buf(void);
void	ft_unset(t_struct *mini);
void	alloc_env_aux(t_struct *mini);
int		init_path(t_struct *mini);
void	redirect_in(t_struct *mini, int j, char *aux);
void	redirect_out(t_struct *mini, int j);
void	run_commands(t_struct *mini);
int		file_descriptor_handler(int in, int out);
void	spaces_in_pipe(t_struct *mini, int i, char *command);
void	execve_error(t_struct *mini);
void	run_signals(int sig);
void	tokenizer(t_struct *mini);
int		tokenizer_find_char(char *string, char needle);
void	tokenizer_clean_quotes(t_struct *mini, char *in, int i, int c);
void	get_home_sign(t_struct *mini, t_token *tk);
void	get_dollar_sign(t_struct *mini, t_token *tk);
t_token	*init_tk(void);
void	free_tk(t_token *tk);
void	finish_tokenizer(t_struct *mini, t_token *tk);

#endif
