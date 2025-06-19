NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = pipex.c pipex_utill.c libft/libft.a

#BONUS_SRC =
OBJ = $(SRC:.c=.o)
#BONUS_OBJ = $(BONUS_SRC:.c=.o)

#BONUS_DONE = bonus_done_marker

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	
#bonus: $(BONUS_DONE)

#$(BONUS_DONE): $(OBJ) $(BONUS_OBJ)
#	$(AR) $(NAME) $(BONUS_OBJ)
#	touch $(BONUS_DONE)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(BONUS_DONE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
