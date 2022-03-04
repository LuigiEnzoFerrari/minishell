NAME := put.a

CC := clang
CFLAGS := -Wall -Werror -Wextra

SRC := $(wildcard *.c)
OBS := $(patsubst %.c, %.o, $(SRC))

INC := ../include

all: $(NAME)

$(NAME): $(OBS)
	@ar -rcs $(NAME) $(OBS)

$(OBS):
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all