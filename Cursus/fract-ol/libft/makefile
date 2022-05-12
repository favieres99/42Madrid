# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 12:36:23 by gfaviere          #+#    #+#              #
#    Updated: 2021/06/15 13:53:13 by gfaviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strcmp.c ft_putstr.c ft_error.c ft_putstr_fd.c ft_strlen.c ft_strnew.c

HEADS		=	libft.h

OBJS		=	$(SRCS:.c=.o)

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

.c.o:			$(HEADS)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

all:			$(NAME)

clean:
				rm -f $(OBJS)
				rm -f $(BNOBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
