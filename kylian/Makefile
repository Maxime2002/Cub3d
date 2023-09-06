NAME	=	cub3d

LIBDIR = ../minilibx-linux

SRCS	=	main.c	\
			ft_error.c \
			utils/ft_strlen.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			utils/ft_strjoin_free.c \
			utils/ft_atoi.c \
			utils/ft_count_number.c \
			utils/ft_count_nb_char.c \
			parsing/ft_parsing.c \
			parsing/ft_init_map_and_arg.c \
			parsing/ft_fill_arg.c \
			parsing/ft_charg_color_img.c \
			parsing/ft_charg_map.c \
			ft_free.c \

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