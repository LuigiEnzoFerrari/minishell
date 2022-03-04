NAME	= libft.a
CC		= clang
CFLAGS	= -Wall -Wextra -Werror

INC		:= include/

DIRS	:= ctype math conv lst put string gnl string_array put_array

SRC		:= $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBS		:= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBS)
	ar -rcs $(NAME) $(OBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
