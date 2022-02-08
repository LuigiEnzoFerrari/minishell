#ifndef MINI_LISTS_H
# define MINI_LISTS_H

/*──────────────────────────────────────────────────────────────────────*/
/*					 		Label related		 						*/

# define FILENAME 1
# define SINGLE_QUOTE 2
# define DOUBLE_QUOTE 3
# define PIPE 4
# define SINGLE_REDIRECT 5
# define DOUBLE_REDIRECT 6
# define STRING 7
# define HEARDOC 8

/*──────────────────────────────────────────────────────────────────────*/
/*					 Declared Structs related	 						*/

/*  Store Environments per node Struct	*/
struct s_environ
{
	char				*key;
	char				*value;
	struct s_environ	*next;
};

typedef struct s_environ t_environ;

/*  Keywords separated per node Struct	*/
struct s_tokens
{
	int				label;
	char			*token;
	struct s_tokens	*next;
};

typedef struct s_tokens t_tokens;

/*  Commands to execute Struct	*/
struct s_commands
{
	char				**args;
	int					*labels;
	struct s_commands	*next;
};

typedef		struct	s_commands t_cmds;

/*──────────────────────────────────────────────────────────────────────*/
/*					 Environment variables related 						*/

t_environ	*init_env(char *key, char *value);
void		delete_env(t_environ **envs);
t_environ	*last_env(t_environ *envs);
void		push_env(t_environ **envs, char *key, char *value);
void		delete_envs(t_environ **tokens);
void		update_env(t_environ *envs, char *key, char *value);
void		to_env_list(t_environ **envs, char *environ);
void		delete_env_by_key(t_environ **envs, char *key);
char		*get_env_value(t_environ *envs, char *key);
size_t		size_envs(t_environ *envs);
t_environ	*get_env(t_environ *envs, char *key);
t_environ	*env_list_duplicate(t_environ *envs);
int			has_key(t_environ *envs, char *key);
void		to_env_list(t_environ **envs, char *environ);
/*──────────────────────────────────────────────────────────────────────*/
/*					 		Tokens related 								*/

t_tokens	*add_new(char *token, int label);
t_tokens	*last_token(t_tokens *tokens);
void		push_token(t_tokens **tokens, char *token, int label);
void		delete_token(t_tokens **token);
void		delete_tokens(t_tokens **tokens);
size_t		number_of_labels(t_tokens *tokens, int label);
void		delete_top_token(t_tokens **tokens);
/*──────────────────────────────────────────────────────────────────────*/
/*					 Execute commands related 							*/

t_cmds		*init_cmd(char **args, int *labels);
void		delete_cmd(t_cmds **cmd);
t_cmds		*last_cmd(t_cmds *cmds);
void		push_cmd(t_cmds **cmds, char **args, int *labels);
void		delete_cmds(t_cmds **tokens);
t_cmds		*pipe_commands(t_tokens *tokens);
/*──────────────────────────────────────────────────────────────────────*/

#endif
