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
CC = 				gcc
FLAGS = 			-Wall -Werror -Wextra

LIBFT = 			libft.a
LIBFT_DIR = 		libft/

INC_PS = 			includes/
INCLUDES = 			-I $(INC_PS) -I $(LIBFT_DIR)

DIR_SRC_PS = 		src/push_swap/
DIR_SRC_CHECK = 	src/checker/
DIR_SRC_COMMON = 	src/common/
#DIR_OBJ = 			objs/

SRC_PS = 			push_swap.c choose_moves.c
SRC_CHECK = 		check_sort.c checker.c
SRC_COMMON = 		input.c instructions.c merge_sort.c node_actions.c\
					queue_actions.c	rotate_reverse_moves.c swap_push_moves.c\
					utils.c utils_push_swap.c displays_push_swap.c

PATH_SRC_PS = 		$(addprefix $(DIR_SRC_PS), $(SRC_PS))
PATH_SRC_CHECK = 	$(addprefix $(DIR_SRC_CHECK), $(SRC_CHECK))
PATH_SRC_COMMON = 	$(addprefix $(DIR_SRC_COMMON), $(SRC_COMMON))

OBJ_PS = 			$(PATH_SRC_PS:%.c=%.o)
OBJ_CHECK = 		$(PATH_SRC_CHECK:%.c=%.o)
OBJ_COMMON = 		$(PATH_SRC_COMMON:%.c=%.o)
OBJ = 				$(OBJ_PS) $(OBJ_CHECK) $(OBJ_COMMON)

#OBJ_PS = 			$(PATH_SRC_PS:%.c=%.o))
#OBJ_CHECK = 		$(addprefix $(DIR_OBJ), $(PATH_SRC_CHECK:%.c=%.o))
#OBJ_COMMON = 		$(addprefix $(DIR_OBJ), $(PATH_SRC_COMMON:%.c=%.o))
#OBJ = 				$(OBJ_PS) $(OBJ_CHECK) $(OBJ_COMMON)

# ----- Rules -----

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT) .
	@echo "$(CYAN)libft library successfully created$(WHITE)\n"

$(word 1, $(NAME)): $(OBJ_PS) $(OBJ_COMMON) $(LIBFT)
	@$(CC) $(FLAGS) -o $(word 1, $(NAME)) $(OBJ_PS) $(OBJ_COMMON) $(LIBFT) $(INCLUDES)
	@echo "$(GREEN)push_swap successfully created$(WHITE)\n"

$(word 2, $(NAME)): $(OBJ_CHECK) $(OBJ_COMMON) $(LIBFT)
	@$(CC) $(FLAGS) -o $(word 2, $(NAME)) $(OBJ_CHECK) $(OBJ_COMMON) $(LIBFT) $(INCLUDES)
	@echo "$(GREEN)checker successfully created$(WHITE)\n"

#$(DIR_OBJ):
#	@mkdir -p $@
#
#$(OBJ): $(DIR_OBJ)%.o:%.c
#	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LIBFT)
	@make clean -C $(LIBFT_DIR)
	@echo "$(PURPLE)Objects were removed - clean.$(WHITE)\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(ORANGE)Names were removed - fclean.$(WHITE)\n"

sclean:
	@rm -f $(OBJ)
	@echo "Objects file were removed - small clean."

push: sclean $(NAME)

re: fclean all

.PHONY: all clean fclean re push