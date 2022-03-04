NAME := printf.a

CC := clang
CFLAGS := -Wall -Werror -Wextra

SRC := $(wildcard *.c)
OBS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBS)
	ar -rcs $(NAME) $(OBS)

$(OBS):
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBS) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re