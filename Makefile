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
MLXLIB = libmlx.a

all:${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -framework OpenGL -framework AppKit ${OBJ} libmlx.a -o ${NAME}

%.o:%.c Makefile
	${CC} ${CFLAGS} -MMD -Imlx -c $<

clean:
	rm -rf ${OBJ} *.d

fclean: clean
	rm -rf ${NAME}

re: fclean all

-include *.d

.PHONY: all clean fclean re
