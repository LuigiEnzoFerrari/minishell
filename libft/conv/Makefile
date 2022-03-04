NAME := conv.a

CC := clang
CFLAGS := -Wall -Werror -Wextra

AUX_PATH := ../math
AUX :=	$(wildcard $(AUX_PATH)/*.c)

SRC := $(wildcard *.c) $(AUX)
OBS := *.o

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
