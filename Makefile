NAME = minishell

CC := clang
SANIT := -g -fsanitize=address
CFLAGS := -Wall -Wextra -Werror

#readline library flag
RL_FLAGS := -lreadline

LINK_LIB := -L libft -lft
SRCS = main.c \
	get_input.c init_envs_b.c expand_variables.c \
	lexical_analysis_and_parse.c linked_list_infos.c \
	tokenize.c execute_commands.c \
	utils.c \

LISTS_CMD_FILES = cmd_lst_one.c cmd_lst_utils.c

LISTS_ENV_FILES = env_lst_one.c env_lst_two.c env_lst_utils.c

BUILTIN_FILES = builtin_exit.c builtin_cd.c builtin_env.c \
				builtin_export.c builtin_pwd.c builtin_echo.c builtin_unset.c

BUILTIN_PATH = $(addprefix builtin/, $(BUILTIN_FILES))
LISTS_ENV_PATH = $(addprefix lists_env/, $(LISTS_ENV_FILES))
LISTS_CMD_PATH = $(addprefix lists_cmd/, $(LISTS_CMD_FILES))

PATHS = $(BUILTIN_PATH) $(LISTS_CMD_PATH) $(LISTS_ENV_PATH)

INC = include

SRCS_LIBS = libft/libft.a 

all: $(NAME)

$(NAME): $(SRCS) $(SRCS_LIBS)
	$(CC) $(SRCS) $(PATHS) $(SANIT) $(RL_FLAGS) $(LINK_LIB) -I $(INC)

$(SRCS_LIBS):
	make -C libft


clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re