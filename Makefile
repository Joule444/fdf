# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 12:36:07 by jthuysba          #+#    #+#              #
#    Updated: 2022/10/14 14:46:20 by jthuysba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = FdF

LIB_DIR        = ./libft

LIBFT        = ./libft/libft.a

GNL_DIR        = ./get_next_line

GNL        = ./get_next_line/get_next_line.h

SRCS        = main.c

OBJS        = ${SRCS:.c=.o}

RM        = rm -f

CC        = gcc

FLAGS        = -Wall -Wextra -Werror -g -I includes/

all        : ${NAME}

%.o: %.c
		  @${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${LIBFT}    :
		  @echo "\033[1;36m~Building libft~"
		  @make -sC ${LIB_DIR}
		  @echo ">>OK"

${GNL}    :
		  @echo "\033[1;36m~Building gnl~"
		  @make -sC ${GNL_DIR}
		  @echo ">>OK"

${NAME}        : ${OBJS} ${LIBFT}
		  @echo "\033[1;35m~Compiling~"
		  @${CC} ${FLAGS} ${OBJS} -L/usr/include  -lpthread -L -lm -o ${NAME} ${LIBFT} ${GNL}
		  @echo ">>OK"

clean        :
		  @echo "\033[1;31m~Cleaning libft~"
		  @make clean -sC ${LIB_DIR} ${GNL_DIR} 
		  @echo ">>OK"
		  @echo "\033[1;33m~Cleaning objects~"
		  @${RM} ${OBJS}
		  @echo ">>OK"

fclean        : clean
		  @echo "\033[1;32m~Cleaning all~"
		  @${RM} ${NAME}
		  @${RM} ${LIBFT} ${GNL}
		  @echo ">>OK"

re        : fclean all

.PHONY        : all clean fclean re