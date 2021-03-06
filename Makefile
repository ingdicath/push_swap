# Colors

# CYAN = \033[38;5;81m
# GREEN = \033[38;5;10m
# PURPLE = \033[38;5;99m
# ORANGE = \033[38;5;172m
# WHITE = \033[0m


# ----- Colors -----




# ----- Variables -----

NAME_PS = push_swap

NAME_CHECK = checker

INCLUDES = push_swap.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

LIBFT_DIR = libft

SRC_PS = Problem_1.c

SRC_CHECK = Problem_2.c

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CHECK = $(SRC_CHECK:.c=.o)

# RESET			= 	\033[0m
# GREEN 			= 	\033[38;5;46m
# WHITE 			= 	\033[38;5;15m
# GREY 			= 	\033[38;5;8m
# ORANGE 			= 	\033[38;5;202m
# RED 			= 	\033[38;5;160m

CYAN = \033[38;5;81m
GREEN = \033[38;5;10m
PURPLE = \033[38;5;99m
ORANGE = \033[38;5;172m
WHITE = \033[0m


all: $(NAME_PS) $(NAME_CHECK)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(CYAN)libft library successfully created$(WHITE)\n"

$(NAME_PS): $(OBJ_PS) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_PS) $(OBJ_PS) $(LIBFT)
	@echo "$(GREEN)name push_swap rule successfully created$(WHITE)\n"

$(NAME_CHECK): $(OBJ_CHECK) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_CHECK) $(OBJ_CHECK) $(LIBFT)
	@echo "$(GREEN)name checker rule successfully created$(WHITE)\n"

%.o: %.c $(INCLUDES)
	@$(CC) $(FLAGS) -Ilibft -c $< -o $@

clean:
	@rm -f $(OBJ_PS) $(OBJ_CHECK) $(LIBFT)
	@make clean -C $(LIBFT_DIR)
	@echo "$(PURPLE)Objects were removed - clean.$(WHITE)\n"

fclean: clean
	@rm -f $(NAME_PS) $(NAME_CHECK)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(ORANGE)Names were removed - fclean.$(WHITE)\n"

sclean:
	@rm -f $(OBJ_PS) $(OBJ_CHECK)
	@echo "Objects file were removed - small clean."

push: sclean $(NAME_PS) $(NAME_CHECK)

re: fclean all

.PHONY: all clean fclean re push