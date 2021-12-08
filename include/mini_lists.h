#ifndef MINI_LISTS_H
# define MINI_LISTS_H

struct s_tokens
{
	int				label;
	char			*token;
	struct s_tokens	*next;
};

struct s_environ
{
	char				*key;
	char				*value;
	struct s_environ	*next;
};

typedef struct s_tokens t_tokens;

typedef struct s_environ t_environ;

t_tokens	*add_new(char *token, int label);
t_tokens	*last_token(t_tokens *tokens);
void		push_token(t_tokens **tokens, char *token, int label);
void		delete_token(t_tokens **token);
void		delete_tokens(t_tokens **tokens);
size_t		number_of_labels(t_tokens *tokens, int label);

#define FILENAME 1
#define SINGLE_QUOTE 2
#define DOUBLE_QUOTE 3
#define PIPE 4
#define SINGLE_REDIRECT 5
#define DOUBLE_REDIRECT 6
#define STRING 7

#endif
