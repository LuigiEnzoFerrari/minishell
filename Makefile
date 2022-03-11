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
READ_INPUT_PATH = $(addprefix srcs/read_input/, $(READ_INPUT_FILES))
PARSE_INPUT_PATH = $(addprefix srcs/parse_input/, $(PARSE_INPUT_FILES))
EXECUTE_PARSE_PATH = $(addprefix srcs/execute_parse/, $(EXECUTE_PARSE_FILES))
BUILTIN_PATH = $(addprefix srcs/execute_parse/builtin/, $(BUILTIN_FILES))

# Auxiliar files of minishell
UTILS_FILES = utils_one.c utils_two.c
LISTS_TOKEN_FILES = tokens_lst_one.c tokens_lst_two.c
LISTS_CMD_FILES = cmd_lst.c
LISTS_ENV_FILES = env_lst_one.c env_lst_two.c  env_lst_three.c env_lst_utils.c
BUILTIN_FILES = builtin_exit.c builtin_cd.c builtin_env.c \
				builtin_export.c builtin_pwd.c builtin_echo.c builtin_unset.c

# Path to the lists files
LISTS_TOKEN_PATH = $(addprefix lists/lists_token/, $(LISTS_TOKEN_FILES))
LISTS_CMD_PATH = $(addprefix lists/lists_cmd/, $(LISTS_CMD_FILES))
LISTS_ENV_PATH = $(addprefix lists/lists_env/, $(LISTS_ENV_FILES))

# Just exists
UTILS_PATH = $(addprefix srcs/utils/, $(UTILS_FILES))

PATHS = main.c $(BUILTIN_PATH) $(LISTS_CMD_PATH) $(LISTS_ENV_PATH) $(LISTS_TOKEN_PATH)\
		$(UTILS_PATH) $(READ_INPUT_PATH) $(PARSE_INPUT_PATH) $(EXECUTE_PARSE_PATH)

FILES= main.c $(READ_INPUT_FILES) $(PARSE_INPUT_FILES) $(EXECUTE_PARSE_FILES) $(UTILS_FILES) $(LISTS_TOKEN_FILES) $(LISTS_CMD_FILES) $(LISTS_ENV_FILES) $(BUILTIN_FILES)

INC = include/ libft/
PATHS_INC = $(addprefix -I, $(INC))

SRCS_LIBS = libft/libft.a 

OBJS_PATH := $(PATHS:.c=.o)

OBJS_DIR=objects/
OBJS=$(addprefix $(OBJS_DIR), $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(SRCS_LIBS) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(SANIT) $(RL_FLAGS) $(LINK_LIB) $(PATHS_INC) -o $@

$(SRCS_LIBS):
	git submodule update --init
	make -C libft

$(OBJS_DIR): $(OBJS_PATH)
	mkdir -p $@
	mv $(OBJS_PATH) $@

%.o: %.c
	clang $(CFLAG) $(SANIT) -c $< $(PATHS_INC) -o $@

clean:
	@make clean -C libft
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
