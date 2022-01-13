NAME = minishell

CC := clang
SANIT := -g -fsanitize=address
CFLAGS := -Wall -Wextra -Werror

#readline library flag
RL_FLAGS := -lreadline

LINK_LIB := -L libft -lft
SRCS = main.c get_input.c lexical_analysis_and_parse.c linked_list_infos.c \
	tokenize.c env_list.c syntax.c exec.c \
	utils.c \
	\
	echo.c\
	cd.c \
	builtin_temp.c \
	export.c \
	\
	\

INC = include

SRCS_LIBS = libft/libft.a 

all: $(NAME)

$(NAME): $(SRCS) $(SRCS_LIBS)
	$(CC) $(SRCS) $(SANIT) $(RL_FLAGS) $(LINK_LIB) -I $(INC)

$(SRCS_LIBS):
	make -C libft


clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re