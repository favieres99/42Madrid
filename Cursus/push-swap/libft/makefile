# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 12:36:23 by gfaviere          #+#    #+#              #
#    Updated: 2021/06/09 21:15:58 by gfaviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c ft_strlen.c ft_write.c ft_strcmp.c ft_strdup.c ft_strdel.c ft_strsplit.c ft_strequ.c ft_strjoin.c\
				ft_strlcpy.c get_next_line.c ft_strsub.c ft_strnew.c ft_strchr.c ft_putstr.c ft_putnbr.c ft_abs.c \
				ft_free_array.c ft_itoa.c ft_putchar.c ft_w_count.c

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

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
