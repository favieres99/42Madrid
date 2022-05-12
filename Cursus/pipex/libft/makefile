# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 12:36:23 by gfaviere          #+#    #+#              #
#    Updated: 2021/09/10 16:52:01 by gfaviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				ft_strncmp.c ft_strnstr.c

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
