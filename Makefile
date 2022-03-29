NAME = a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIB_DIR = ./lib/

FUNC =	main.c\
		child.c\
		error.c\
		parser.c\
		pipe.c\
		read_file.c\

BONUS_FUNC =

SRCS = $(addprefix src/, $(FUNC))
OBJS = $(SRCS:c=o)

BONUS_SRCS = $(addprefix bonus/, $(BONUS_FUNC))
BONUS_OBJS = $(BONUS_SRCS:c=o)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) -L $(LIB_DIR) -lft -o $(NAME) $^

all : $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : bonus all clean fclean re