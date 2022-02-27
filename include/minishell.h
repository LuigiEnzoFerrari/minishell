/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:41:36 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:41:37 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <readline/readline.h>
# include <readline/history.h>
# include <mini_lists.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <libft.h>
# include <stdio.h>
# include <const.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>

# define HERE_D "bash: warning: here-document at line1 delimited by end-of-file"

# define STD 0
# define LAST 1
# define PIP 2
# define IN 0
# define OUT 1

int			*last_status_number(void);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Envs Database			 						*/

struct	s_env_variables
{
	t_environ	*global_vars;
	t_environ	*local_vars;
};
typedef struct s_env_variables	t_env_vars;

typedef struct sigaction		t_sigaction;

/*──────────────────────────────────────────────────────────────────────*/
/*					 	    Handle Signals		 						*/

int			mysignal(int sig, void (*handler)(int));
void		handle_signals(int sig);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Read and Store Envs		 						*/

t_environ	*get_global_vars(void);
t_env_vars	*get_environment_variables(void);
void		init_local_vars(t_env_vars *vars, t_tokens **tokens);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Read and Store Input	 						*/

char		*get_input(t_environ *envs, t_env_vars *vars);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Parse and Store it in Tokens 					*/

t_tokens	*lexical_analysis_and_parse(char *input, t_env_vars *vars);
t_tokens	*tokenize(char *input);
void		expand_variables(t_tokens *tokens, t_env_vars *vars);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Execute Commands 								*/

void		execute_cmds(t_tokens *tokens, t_env_vars *vars);
t_cmds		*create_cmds(t_tokens *tokens);
char		*get_bin_path(char *args, t_environ *envs);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	    Pipes  				 						*/

void		case_pipe(int fds[3][2], t_cmds *cmds);
void		save_pipes(int *fds_std);
void		ajust_pipes(t_cmds *cmds, int fds[3][2]);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	    Redirects			 						*/

int			redirects(char *args, int flag, int std_fd);
char		**remove_redirects(char **args, int *labels);
int			check_syntax(t_tokens *tokens);
void		here_document(char *args, int flag, int std_fd);
void		case_redirect(t_cmds *cmds);
void		here_document(char *args, int flag, int std_fd);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Minishell Builtin	 							*/

int			isbuiltin(char *cmd);
void		execute_builtin(char **args, int fds[3][2], t_env_vars *vars);
void		builtin_echo(char **args);
void		builtin_cd(char **args, t_environ *envs);
void		builtin_pwd(char **args, t_environ *envs);
void		builtin_export(char **args, t_env_vars *vars);
void		builtin_unset(char **args, t_env_vars *vars);
void		builtin_env(char **args, t_environ *envs);
void		builtin_exit(char **args, int fds[3][2], t_env_vars *vars);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Minishell Builtin	 							*/

void		execute_builtout(char **args, t_env_vars *vars);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Utils				 							*/

int			ft_isblank(int c);
int			is_token(int c);
int			token_ends(int c);
size_t		number_of_labels(t_tokens *tokens, int label);

#endif
