NAME = minishell

CC := clang
SANIT := -g -fsanitize=address
CFLAGS := -Wall -Wextra -Werror

#readline library flag
RL_FLAGS := -lreadline

LINK_LIB := -L libft -lft

# Core files of minishell
READ_INPUT_FILES = get_input.c get_envs.c
PARSE_INPUT_FILES = tokenize.c lexical_analysis_and_parse.c expand_variables.c
EXECUTE_PARSE_FILES = execute_cmds.c create_cmds.c handle_redirects.c here_document.c check_syntax.c handle_pipes.c \
	execute_builtins.c execute_builtouts.c find_cmd_path.c \

# PATHS to the Core files
READ_INPUT_PATH = $(addprefix steps/read_input/, $(READ_INPUT_FILES))
PARSE_INPUT_PATH = $(addprefix steps/parse_input/, $(PARSE_INPUT_FILES))
EXECUTE_PARSE_PATH = $(addprefix steps/execute_parse/, $(EXECUTE_PARSE_FILES))

# Auxiliar files of minishell
UTILS_FILES = utils.c 
LISTS_TOKEN_FILES = tokens_lst.c
LISTS_CMD_FILES = cmd_lst.c
LISTS_ENV_FILES = env_lst_one.c env_lst_two.c env_lst_utils.c
BUILTIN_FILES = builtin_exit.c builtin_cd.c builtin_env.c \
				builtin_export.c builtin_pwd.c builtin_echo.c builtin_unset.c

# Path to the Auxiliar files
UTILS_PATH = $(addprefix utils/, $(UTILS_FILES))
LISTS_TOKEN_PATH = $(addprefix lists_token/, $(LISTS_TOKEN_FILES))
LISTS_CMD_PATH = $(addprefix lists_cmd/, $(LISTS_CMD_FILES))
LISTS_ENV_PATH = $(addprefix lists_env/, $(LISTS_ENV_FILES))
BUILTIN_PATH = $(addprefix builtin/, $(BUILTIN_FILES))


PATHS = main.c $(BUILTIN_PATH) $(LISTS_CMD_PATH) $(LISTS_ENV_PATH) $(LISTS_TOKEN_PATH)\
		$(UTILS_PATH) $(READ_INPUT_PATH) $(PARSE_INPUT_PATH) $(EXECUTE_PARSE_PATH)

INC = include/ libft/
PATHS_INC = $(addprefix -I, $(INC))

SRCS_LIBS = libft/libft.a 

all: $(NAME)

$(NAME): $(PATHS) $(SRCS_LIBS)
	$(CC) $(PATHS) $(SANIT) $(RL_FLAGS) $(LINK_LIB) $(PATHS_INC) -o $(NAME)

$(SRCS_LIBS):
	make -C libft

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
