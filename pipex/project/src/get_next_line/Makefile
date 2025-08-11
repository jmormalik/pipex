CC = cc -c -Wall -Wextra -Werror
NAME = gnl.a

INC = -I ../../includes
LIB = ../../library

SRCS = \
get_next_line.c \
get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $^ -o $@ $(INC)

.depend: $(OBJS)
	@mkdir -p ../../library
	ar -rcs $(LIB)/$(NAME) $^
	@touch .depend
	
$(NAME): .depend

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)/$(NAME)
	@rm -f .depend

re: fclean all

.PHONY: all clean fclean re
