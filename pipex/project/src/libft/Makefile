CC = cc -c -Wall -Wextra -Werror
NAME = libft.a

INC = -I ../../includes
LIB = ../../library

SRCS = \
ft_split.c \
ft_strjoin.c \
ft_calloc.c \
ft_strlen.c \
ft_bzero.c \
ft_strchr.c \
ft_strncmp.c \
ft_putstr_fd.c \
ft_strdup.c

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
