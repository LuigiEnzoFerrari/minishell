NAME = ctype.a

CC = clang
CFLAGS = -Wall -Werror -Wextra

SRC := $(wildcard *.c)
OBS := $(SRC:%.c=%.o)

INC := ../include

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(INC) -c $(SRC)
	ar -rcs $(NAME) $(OBS)

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re