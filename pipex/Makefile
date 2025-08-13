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

CC = cc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(PIPEX_A) $(LIBFT_A)
	@$(CC) $^ -o $@
	
$(PIPEX_A): $(PIPEX)
	@$(MAKE) -C $(PIPEX) -s

$(LIBFT_A): $(LIBFT)
	@$(MAKE) -C $(LIBFT) -s
	
$(GNL_A): $(GNL)
	@$(MAKE) -C $(GNL) -s

$(PIPEX_BONUS_A): $(PIPEX_BONUS)
	@$(MAKE) -C $(PIPEX_BONUS) -s
	
bonus: .depend

.depend: $(PIPEX_BONUS_A) $(LIBFT_A) $(GNL_A)
	@$(CC) $^ -o $(NAME)
	@touch .depend

clean:
	@$(MAKE) -C $(GNL) fclean -s
	@$(MAKE) -C $(PIPEX_BONUS) fclean -s
	@$(MAKE) -C $(PIPEX) fclean -s
	@$(MAKE) -C $(LIBFT) fclean -s
	@rm -rf .depend
	
fclean: clean
	@rm -rf $(NAME)

	
re: fclean all

.PHONY: all clean fclean re bonus
