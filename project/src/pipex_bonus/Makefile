CC = cc -c -Wall -Wextra -Werror
NAME = pipex_bonus.a

INC = -I ../../includes
LIB = ../../library

SRCS = \
pipex_bonus.c \
pipex_path_bonus.c \
error_bonus.c \
utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $^ -o $@ $(INC)

$(NAME): $(OBJS)
	@mkdir -p ../../library
	@ar -rcs $(LIB)/$(NAME) $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(LIB)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
