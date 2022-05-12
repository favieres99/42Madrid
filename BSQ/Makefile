# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estina <estina@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 13:13:02 by estina            #+#    #+#              #
#    Updated: 2019/09/24 22:54:57 by estina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c read_file.c draw_sqr.c search_solution.c structure_maker.c
SRCS2	=	string_input.c input_transform.c
NAME	=	BSQ
CC		=	cc
RM		=	rm -rf
FLAGS	=	-Wall -Werror -Wextra

${NAME}:
		${CC} ${FLAGS} -o ${NAME} ${SRCS} ${SRCS2}

all:	${NAME}

fclean:
		${RM} ${NAME}

re:		fclean all

.PHONY:	all fclean re