NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f


FUNC =	main.c\
		stack_util.c\
		error.c\
		operation_swap.c\
		operation_push.c\
		operation_rotate.c\
		operation_reverse_rotate.c\
		parse.c\
		parse_util.c\
		ft_split.c\
		pivot.c\
		check.c\
		a_util.c\
		b_util.c\
		a_sort.c\
		b_sort.c\
		a_optimization.c\
		b_optimization.c\
		operation_util.c\



SRCS = $(addprefix mandatory/src/, $(FUNC))
OBJS = $(SRCS:c=o)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : bonus all clean fclean re