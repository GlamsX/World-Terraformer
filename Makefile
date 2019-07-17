# @Author: la-montagne
# @Date:   2019-07-17T14:24:39+02:00
# @Last modified by:   la-montagne
# @Last modified time: 2019-07-17T14:26:59+02:00

CC	=	gcc -w

GRAPH	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS	=	-W -Werror -Wall -Wextra -g3

NAME	=	my_world

RM	=	rm -rf

SRC	=	main.c	\
		create_0.c	\
		destroy_0.c	\
		draw_0.c	\
		draw_1.c	\
		event_0.c	\
		event_1.c	\
		event_2.c	\
		event_3.c	\
		realloc.c	\
		save_map.c	\
		struct_0.c	\
		usfu_0.c	\
		usfu_1.c	\
		usfu_2.c	\
		world_0.c	\
		world_1.c	\
		world_2.c	\
		world_3.c	\

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GRAPH)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) .vscode

re:		fclean all

bin:	re
	$(RM) $(OBJ)

st:		bin
	./my_world
	$(RM) $(NAME)
