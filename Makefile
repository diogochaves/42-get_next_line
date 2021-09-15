CC		=	clang
FLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

NAME	=	getnextline
HEADER	=	get_next_line.h
SRCS	=	get_next_line.c \
			get_next_line_utils.c \
			main.c
OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):$(OBJS) $(HEADER)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o:	%.c
		$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
