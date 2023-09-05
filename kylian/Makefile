NAME	=	cub3d

LIBDIR = ../minilibx-linux

SRCS	=	main.c	\
			ft_error.c \
			utils/ft_strlen.c \

OBJ =	${SRCS:.c=.o}

CC =	gcc

CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address

.c.o:
		$(CC) $(CFLAGS) -Iminilibx-linux  -Imlx_linux -c $< -o $(<:.c=.o)

$(NAME): ${OBJ}
		cd ../minilibx-linux && ./configure && $(MAKE)
		$(CC) ${OBJ} -Iminilibx-linux ../minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

all:	${NAME}

clean:
		rm -f ${OBJ}
		cd ${LIBDIR} && ${MAKE} clean

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re