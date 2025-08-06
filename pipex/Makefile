# EXECUTABLE NAMES
NAME = pipex
NAME_BONUS = pipex

# COMPILER AND FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)
RM = rm -f

# DIRECTORIES
SRC_DIR = project/src
INCLUDE_DIR = project/includes
PIPEX_DIR = $(SRC_DIR)/pipex
PIPEX_BONUS_DIR = $(SRC_DIR)/pipex_bonus
GNL_DIR = $(SRC_DIR)/get_next_line
LIBFT_DIR = $(SRC_DIR)/libft

# VPATH for source files
VPATH = $(PIPEX_DIR):$(PIPEX_BONUS_DIR):$(GNL_DIR)

# SOURCE FILES (just the names)
SRCS_PIPEX = pipex.c utils.c get_next_line.c get_next_line_utils.c
SRCS_BONUS = pipex_bonus.c utils_bonus.c error_bonus.c pipex_path_bonus.c get_next_line.c get_next_line_utils.c

# OBJECT FILES
OBJS = $(SRCS_PIPEX:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# LIBRARIES
LIBFT = $(LIBFT_DIR)/libft.a

# INCLUDES
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

# RULES
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
