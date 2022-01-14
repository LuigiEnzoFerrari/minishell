#ifndef MINISHELL_H
# define MINISHELL_H
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <libft.h>
# include <mini_lists.h>
# include <const.h>
# include <errno.h>

struct s_env_variables
{
    t_environ   *envs_a;
    t_environ   *envs_b;
};

typedef struct s_env_variables  t_vars;

typedef struct sigaction	t_sigaction;

char	    *get_input(t_environ *envs);
void		lexical_analysis_and_parse(char *input, t_vars *vars);
t_tokens	*tokenize(char *input);
void		syntax(t_tokens *tokens);

int			ft_isblank(int c);
int			isseparator(int label);

void		exec(t_tokens *tokens, t_vars *vars);

void		builtin_echo(char **args);
void		builtin_cd(char **args, t_environ *envs);
void		builtin_pwd(char **args, t_environ *envs);
void		builtin_export(char **args, t_environ *envs);
void		builtin_unset(char **args, t_vars *vars);
void		builtin_env(char **args, t_environ *envs);
void		builtin_exit(char **args, t_vars *vars);
void        init_envs_b(t_environ **envs, t_tokens **tokens);
void	    expand_variables(t_tokens *tokens, t_environ *envs);

#endif
