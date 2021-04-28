cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)
include_directories(libft)

add_executable(push_swap
        includes/push_swap.h
        libft/ft_array_size.c
        libft/ft_atoi.c
        libft/ft_atol.c
        libft/ft_bzero.c
        libft/ft_free_array.c
        libft/ft_isdigit.c
        libft/ft_isemptyline.c
        libft/ft_isnumber.c
        libft/ft_ispositive_number.c
        libft/ft_iswhitespace.c
        libft/ft_max.c
        libft/ft_min.c
        libft/ft_put_error.c
        libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_strcmp.c
        libft/ft_strcmp_trim.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strtrim.c
        libft/ft_substr.c
        libft/get_next_line.c
        libft/ft_print_array.c
        libft/libft.h
        src/checker/sort_checker.c
        src/checker/checker.c
        src/common/displays_push_swap.c
        src/common/input.c
        src/common/error.c
        src/common/instructions.c
        src/common/merge_sort.c
        src/common/node_actions.c
        src/common/queue_actions.c
        src/common/rotate_reverse_moves.c
        src/common/swap_push_moves.c
        src/push_swap/utils_push_swap.c
        src/push_swap/push_swap.c
        src/push_swap/sort.c
        src/push_swap/checks.c
        src/push_swap/moves.c src/push_swap/reset.c)
