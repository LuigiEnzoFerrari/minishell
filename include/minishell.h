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


#define IN 0
#define OUT 1
#define HEREDOC_SIGINT -4


int *last_status_number();

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Envs Database			 						*/

struct s_env_variables
{
	t_environ   *global_vars;
	t_environ   *local_vars;
};

typedef struct s_env_variables  t_env_vars;


typedef struct sigaction	t_sigaction;

/*──────────────────────────────────────────────────────────────────────*/
/*					 	    Handle Signals		 						*/

int     mysignal(int sig, void (*handler)(int));
void	handle_signals(int sig);

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

/*──────────────────────────────────────────────────────────────────────*/
/*					 	    Pipes  				 						*/

void	case_pipe(int *save, t_cmds  *cmds, int *stdpipe);
void    save_pipes(int *stdpipe);
void    ajust_pipes(t_cmds *cmds, int *stdpipe, int *save);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	    Redirects			 						*/

int    redirects(char *args, int flag, int std_fd);
char    **remove_redirects(char **args, int *labels);
int     check_syntax(t_tokens *tokens);
void    here_document(char *args, int flag, int std_fd);
void	case_redirect(int saveIN, t_cmds  *cmds);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Minishell Builtin	 							*/

int         isbuiltin(char *cmd);
void        execute_builtin(char **args, t_env_vars *vars);
void		builtin_echo(char **args);
void		builtin_cd(char **args, t_environ *envs);
void		builtin_pwd(char **args, t_environ *envs);
void		builtin_export(char **args, t_env_vars *vars);
void		builtin_unset(char **args, t_env_vars *vars);
void		builtin_env(char **args, t_environ *envs);
void		builtin_exit(char **args, t_env_vars *vars);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Minishell Builtin	 							*/

void        execute_builtout(char **args, t_env_vars *vars);

/*──────────────────────────────────────────────────────────────────────*/
/*					 	Utils				 							*/

int			ft_isblank(int c);
void		print_tokens(t_tokens *temp);
void		print_cmds(t_cmds *temp);
void		print_array(char **paths);

#endif
