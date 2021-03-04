# Colors

CYAN = \033[38;5;81m
GREEN = \033[38;5;10m
PURPLE = \033[38;5;99m
ORANGE = \033[38;5;172m
WHITE = \033[0m

# Variables 

NAME = push_swap

INCLUDES = push_swap.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

LIBFT_DIR = libft

SRC = Problem_1.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(CYAN)libft library successfully created$(WHITE)\n"

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "$(GREEN)name rule successfully created$(WHITE)\n"

%.o: %.c $(INCLUDES)
	@$(CC) $(FLAGS) -Ilibft -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(LIBFT)
	@make clean -C $(LIBFT_DIR)
	@echo "$(PURPLE)Objects file were removed - clean.$(WHITE)\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(ORANGE)Objects file were removed - fclean.$(WHITE)\n"

sclean:
	@rm -f $(OBJECTS)
	@echo "Objects file were removed - small clean."

push: sclean $(NAME)

re: fclean all

.PHONY: all clean fclean re push