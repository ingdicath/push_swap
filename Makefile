#
# Created by dsalaman on 2021/04/03
#

# ----- Colors -----

CYAN = \033[38;5;81m
GREEN = \033[38;5;10m
PURPLE = \033[38;5;99m
ORANGE = \033[38;5;172m
WHITE = \033[0m

# ----- Variables -----

NAME = 				push_swap checker

INC_PS = 			includes/
INCLUDES = 			-I $(INC_PS) -I $(LIBFT_DIR)

CC = 				gcc
FLAGS = 			-Wall -Werror -Wextra $(INCLUDES)

LIBFT = 			libft.a
LIBFT_DIR = 		libft/

DIR_SRC_PS = 		src/push_swap/
DIR_SRC_CHECK = 	src/checker/
DIR_SRC_COMMON = 	src/common/
DIR_OBJ = 			objs/

SRC_PS = 			push_swap.c checks.c moves.c sort.c reset.c\
					utils_push_swap.c
SRC_CHECK = 		sort_checker.c checker.c
SRC_COMMON = 		input.c instructions.c merge_sort.c node_actions.c\
					queue_actions.c	rotate_reverse_moves.c swap_push_moves.c\
					error.c displays_push_swap.c

PATH_SRC_PS = 		$(addprefix $(DIR_SRC_PS), $(SRC_PS))
PATH_SRC_CHECK = 	$(addprefix $(DIR_SRC_CHECK), $(SRC_CHECK))
PATH_SRC_COMMON = 	$(addprefix $(DIR_SRC_COMMON), $(SRC_COMMON))

OBJ_PS = 			$(PATH_SRC_PS:$(DIR_SRC_PS)%.c=$(DIR_OBJ)%.o)
OBJ_CHECK = 		$(PATH_SRC_CHECK:$(DIR_SRC_CHECK)%.c=$(DIR_OBJ)%.o)
OBJ_COMMON = 		$(PATH_SRC_COMMON:$(DIR_SRC_COMMON)%.c=$(DIR_OBJ)%.o)
OBJ = 				$(OBJ_PS) $(OBJ_CHECK) $(OBJ_COMMON)

# ----- Rules -----

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT) .
	@echo "$(CYAN)libft library successfully created$(WHITE)\n"

$(word 1, $(NAME)): $(OBJ_PS) $(OBJ_COMMON) $(LIBFT)
	@$(CC) $(FLAGS) -o $(word 1, $(NAME)) $(OBJ_PS) $(OBJ_COMMON) $(LIBFT)
	@echo "$(GREEN)push_swap successfully created$(WHITE)\n"

$(word 2, $(NAME)): $(OBJ_CHECK) $(OBJ_COMMON) $(LIBFT)
	@$(CC) $(FLAGS) -o $(word 2, $(NAME)) $(OBJ_CHECK) $(OBJ_COMMON) $(LIBFT)
	@echo "$(GREEN)checker successfully created$(WHITE)\n"

$(DIR_OBJ)%.o: $(DIR_SRC_PS)%.c
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJ)%.o: $(DIR_SRC_CHECK)%.c
	@cd $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJ)%.o: $(DIR_SRC_COMMON)%.c
	@cd $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJ)
	@echo "$(PURPLE)Objects were removed - clean.$(WHITE)\n"

fclean: clean
	@rm -f $(NAME) $(LIBFT)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(ORANGE)Names were removed - fclean.$(WHITE)\n"

sclean:
	@rm -rf $(DIR_OBJ)
	@echo "Objects file were removed - small clean."

push: sclean $(NAME)

re: fclean all

.PHONY: all clean fclean re push