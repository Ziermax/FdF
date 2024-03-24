CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
SRC = fdf.c \
	  get_next_line.c get_next_line_utils.c read_file.c \
	  ascii_to.c object.c set_object.c make_object.c \
	  matrix.c matrix_transformation.c object_movement.c \
	  color.c draw_line.c draw_straight_line.c draw_corner.c draw_object.c \
	  display_image.c mlx_image.c
OBJ = ${SRC:.c=.o}
INC = ${SRC:.c=.d}
MLXLIB = libmlx.a

all:${NAME}

${NAME}: ${OBJ} ${MLXLIB}
	${CC} ${CFLAGS} -framework OpenGL -framework AppKit ${OBJ} ${MLXLIB} -o ${NAME}

%.o:%.c Makefile
	${CC} ${CFLAGS} -MMD -Imlx -c $<

${MLXLIB}:
	@make -C minilibx_macos
	mv minilibx_macos/${MLXLIB} ./

clean:
	rm -rf ${OBJ}
	rm -rf ${INC}
	rm -rf ${MLXLIB}
	make clean -C minilibx_macos

fclean: clean
	rm -rf ${NAME}

re: fclean all

-include ${INC}

.PHONY: all clean fclean re
