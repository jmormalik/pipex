NAME = pipex

DIRECTORY = ./project

SOURCE = $(DIRECTORY)/src
PIPEX = $(SOURCE)/pipex
PIPEX_BONUS = $(SOURCE)/pipex_bonus
LIBFT = $(SOURCE)/libft
GNL = $(SOURCE)/get_next_line

LIBRARY = $(DIRECTORY)/library
PIPEX_A = $(LIBRARY)/pipex.a
PIPEX_BONUS_A = $(LIBRARY)/pipex_bonus.a
LIBFT_A = $(LIBRARY)/libft.a
GNL_A = $(LIBRARY)/gnl.a

PIPEX_SRCS = $(addprefix $(PIPEX)/, \
pipex.c \
utils.c \
)
PIPEX_BONUS_SRCS = $(addprefix $(PIPEX_BONUS)/, \
pipex_bonus.c \
error_bonus.c \
utils_bonus.c \
pipex_path_bonus.c \
)
GNL_SRCS = $(addprefix $(GNL)/, \
get_next_line.c \
get_next_line_utils.c \
)
LIBFT_SRCS = $(addprefix $(LIBFT)/, \
ft_split.c \
ft_strjoin.c \
ft_calloc.c \
ft_strlen.c \
ft_bzero.c \
ft_strncmp.c \
ft_strchr.c \
ft_strdup.c \
ft_putstr_fd.c \
)
CC = cc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(PIPEX_A) $(LIBFT_A)
	$(CC) $^ -o $@
	
$(PIPEX_A): $(PIPEX_SRCS)
	$(MAKE) -C $(PIPEX)

$(LIBFT_A): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT)
	
$(GNL_A): $(GNL_SRCS)
	$(MAKE) -C $(GNL)

$(PIPEX_BONUS_A): $(PIPEX_BONUS_SRCS)
	$(MAKE) -C $(PIPEX_BONUS)
	
bonus: .depend

.depend: $(PIPEX_BONUS_A) $(LIBFT_A) $(GNL_A)
	$(CC) $^ -o $(NAME)
	@touch .depend

clean:
	$(MAKE) -C $(GNL) fclean
	$(MAKE) -C $(PIPEX_BONUS) fclean
	$(MAKE) -C $(PIPEX) fclean
	$(MAKE) -C $(LIBFT) fclean
	@rm -rf .depend
	
fclean: clean
	rm -rf $(NAME)

	
re: fclean all

.PHONY: all clean fclean re bonus
