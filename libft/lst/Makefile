NAME	= lst.a

CC		= clang
CFLAGS	= -Wall -Wextra -Werror

SRC		:= $(wildcard *.c)
OBS		:= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBS)
	$(CC) $(CFLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBS)

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re: fclean

.PHONY: all clean fclean re