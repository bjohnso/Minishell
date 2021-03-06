/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:13:20 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/14 16:23:18 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include "libft.h"

/*
**Artifacts
*/

typedef struct		s_shell
{
	char			*alias;
	char			**environ;
	char			**dir;
	bool			exit;
	bool			debug;
}					t_shell;

typedef struct		s_agent
{
	char			*alias;
	char			*target;
	char			*options;
	char			**files;
	char			**exec_args;
	bool			command_status;
	bool			execution_status;
}					t_agent;

typedef struct		s_token
{
	char			*lexeme;
	char			*type;
	int				pos;
}					t_token;

typedef struct		s_token_list
{
	t_token			**tokens;
	size_t			size;
}					t_token_list;

typedef struct		s_buffer
{
	char			*str;
	size_t			size;
}					t_buffer;

/*
**Shell
*/

t_shell				*mini_buff(t_shell *s, t_buffer *b,
						t_token_list *t, t_agent *a);
t_shell				*mini_shell(t_shell *s, t_buffer *b,
						t_token_list *t, t_agent *a);
t_shell				*new_shell(char *alias);
void				shell_destroy(t_shell *shell);

/*
**Directory
*/

char				*file_search(char *dir, char *alias);
char				*build_file_path(char *dir, char *alias);
size_t				build_file_path_init(char *dir, char *alias);

/*
**Environ
*/

char				**environ_init(char **env);
void				environ_push(t_shell *shell, char *pair);
int					environ_search(char **env, char *pair, int split);
char				*environ_get_value(char **env, int pos);
void				environ_replace(t_shell *shell, char *pair, int position);
void				environ_delete(t_shell *shell, int position);
char				*environ_pair_clone(char *original);
void				env_add_or_replace(t_shell *shell, char *file, int split);

/*
**Parser
*/

char				*lexer(char *expansion, int exp_pos);
t_token_list		*parser(t_shell *shell, char *str);
int					quote_lex(void);
int					quote_lex_alt(int len, int quote_count);
char				*space_lex(void);
char				*new_lexeme(char *str, int size);
void				global_init(char *str, int pos);
int					is_delim(char *str);
char				*expand(char *lexeme, char *expansion, int pos);
int					insert_expansion(char *expanded,
						char *expansion, size_t pos);
char				*expand_return(char *lexeme, char *expanded);

/*
**Token
*/

t_token				*generate_token(char *lexeme, int pos);
t_token				*new_token(char *lexeme, int pos, char *type);
t_token_list		*new_token_list();
t_token_list		*token_list_push(t_token_list *token_list, t_token *token);
void				token_list_destroy(t_token_list *token_list);
void				token_destroy(t_token *token);
void				tokens_destroy(t_token **tokens, size_t size);

/*
**Input Reader
*/

t_buffer			*input_reader();

/*
**Util
*/

void				sstr_destroy(char **str, int save);
void				print_array(char **str, char *tag);
void				print_exec_report(t_shell *sh,
						t_token_list *t_list, t_agent *agent);

/*
**Buffer
*/

t_buffer			*new_buffer();
void				buffer_push(t_buffer *buffer, char c);
void				buffer_destroy(t_buffer *buffer);

/*
**Agency
*/

t_agent				*compute_execute(t_shell *shell, t_token_list *token_list);

/*
**Agent
*/

t_agent				*new_agent(t_shell *shell, t_token *token);
char				*agent_map_target(char **env, char *alias);
char				*agent_map_target_alt(char **env, char *alias, int pos);
t_agent				*agent_opt_push(t_agent *agent, char option);
t_agent				*agent_files_push(t_agent *agent, char *file);
t_agent				*agent_generate_exec_args(t_agent *agent);
t_agent				*agent_clone(t_agent *clone, t_agent *agent);
void				agent_destroy(t_agent *agent);

/*
**Executor Manager
*/

int					execute(t_shell *shell, t_agent *agent);
int					execute_builtin(t_shell *shell, t_agent *agent);

/*
**Shell-Builtins
*/

void				mini_echo(t_shell *shell, t_agent *agent);
int					mini_cd(t_shell *shell, t_agent *agent);
void				mini_env(t_shell *shell);
int					mini_setenv(t_shell *shell, t_agent *agent);
int					mini_unsetenv(t_shell *shell, t_agent *agent);

#endif
