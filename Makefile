NAME        = fdf

LIB_DIR        = ./libft

MLX_DIR     = ./mlx

LIBFT        = ./libft/libft.a

MLX        = ./mlx/libmlx.a

SRCS        = main.c mlx.c bresenham.c bresenham_octants.c utils.c check_file.c lst_fonct.c lst_init.c iso.c draw_figure.c z_fonct.c move_keys.c

OBJS        = ${SRCS:.c=.o}

RM        = rm -f

CC        = gcc

FLAGS        = -g3

FLAGS_LIB    = -lXext -lX11

all        : ${NAME}

.c.o        :
		  @${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${LIBFT}    :
		  @echo "\033[35m----Building libft----"
		  @make -sC ${LIB_DIR}
		  @echo "OK"

${MLX}        :
		  @echo "\033[35m----Building MLX----"
		  @make -sC ${MLX_DIR}
		  @echo "OK"

${NAME}        : ${OBJS} ${LIBFT} ${MLX}
		  @echo "\033[34m----Compiling----"
		  @${CC} ${FLAGS} ${OBJS} -L ${MLX_DIR} -lmlx -lm ${FLAGS_LIB} -o ${NAME} ${LIBFT}
		  @echo "OK"

clean        :
		  @echo "\033[31m----Cleaning libft----"
		  @make clean -sC ${LIB_DIR}
		  @echo "OK"
		  @echo "\033[31m----Cleaning MLX----"
		  @make clean -sC ${MLX_DIR}
		  @echo "OK"
		  @echo "\033[31m----Cleaning objects----"
		  @${RM} ${OBJS}
		  @echo "OK"

fclean        : clean
		  @echo "\033[33m----Cleaning all----"
		  @${RM} ${NAME}
		  @${RM} ${LIBFT}
		  @${RM} ${MLX}
		  @echo "OK"

re        : fclean all

.PHONY        : all clean fclean re
