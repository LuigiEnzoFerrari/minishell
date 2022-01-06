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


typedef struct sigaction	t_sigaction;

void		lexical_analysis_and_parse(char *input, t_environ *envs);
t_tokens	*tokenize(char *input);
void		syntax(t_tokens *tokens);

int			ft_isblank(int c);
int			isseparator(int label);

void		exec(t_tokens *tokens, t_environ *envs);

void		echo(char **args);
void		cd(char **args, t_environ *envs);
void		pwd(char **args, t_environ *envs);
void		export(char **args);
void		unset(char **args);
void		env(char **args, t_environ *envs);
void		exits(char **args);


#endif
