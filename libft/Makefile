# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsalaman <dsalaman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/20 13:49:31 by dsalaman      #+#    #+#                  #
#    Updated: 2021/03/13 17:42:13 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isemptyline.c ft_isnumber.c ft_iswhitespace.c ft_put_error.c\
	ft_putstr_fd.c ft_putstr.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c\
	ft_strjoin.c ft_strlen.c ft_substr.c ft_strtrim.c get_next_line.c\
	ft_strcmp_trim.c ft_free_array.c ft_array_size.c ft_min.c ft_max.c\
	ft_ispositive_number.c ft_isdigit.c ft_putendl_fd.c ft_putchar_fd.c\
	ft_atol.c ft_bzero.c ft_print_array.c ft_numlen.c ft_putnbr_fd.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "libft library creation successful"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all