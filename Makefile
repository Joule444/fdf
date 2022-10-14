# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 12:36:07 by jthuysba          #+#    #+#              #
#    Updated: 2022/10/14 15:35:25 by jthuysba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = FdF

LIB_DIR        = ./libft

LIBFT        = ./libft/libft.a

SRCS        = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS        = ${SRCS:.c=.o}

RM        = rm -f

CC        = gcc

FLAGS        = -Wall -Wextra -Werror -g -I includes/

all        : ${NAME}

%.o: %.c
		  @${CC} ${FLAGS} -Imlx -c $< -o ${<:.c=.o}

${LIBFT}    :
		  @echo "\033[1;36m>>BUILDING LIBFT"
		  @make -sC ${LIB_DIR}
		  @echo ">>OK!\n~ ~ ~ ~ ~"

${NAME}        : ${OBJS} ${LIBFT}
		  @echo "\033[1;35m>>COMPILING"
		  @${CC} ${FLAGS} ${OBJS} -L/usr/include  -lpthread -L -lm -o ${NAME} ${LIBFT}
		  @echo ">>OK!"

clean        :
		  @echo "\033[1;31m>>CLEANING LIBFT"
		  @make clean -sC ${LIB_DIR}
		  @echo ">>OK!\n~ ~ ~ ~ ~"
		  @echo "\033[1;33m>>CLEANING OBJECTS"
		  @${RM} ${OBJS}
		  @echo ">>OK!\n~ ~ ~ ~ ~"

fclean        : clean
		  @echo "\033[1;32m>>CLEANING ALL"
		  @${RM} ${NAME}
		  @${RM} ${LIBFT}
		  @echo ">>OK!\n~ ~ ~ ~ ~"

re        : fclean all

.PHONY        : all clean fclean re