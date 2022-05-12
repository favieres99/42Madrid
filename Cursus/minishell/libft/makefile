# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 12:36:23 by gfaviere          #+#    #+#              #
#    Updated: 2021/09/17 15:18:25 by gfaviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c			\
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c		\
				ft_strcpy.c	ft_strlcpy.c ft_strlcat.c ft_strchr.c		\
				ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c		\
				ft_isupper.c ft_islower.c ft_isdigit.c ft_isalnum.c		\
				ft_isascii.c ft_isprint.c ft_isspace.c ft_toupper.c		\
				ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c			\
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c		\
				ft_wordcnt.c ft_itoa.c ft_ndigits.c ft_strmapi.c		\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c			\
				ft_putnbr_fd.c ft_isnegative.c ft_strcmp.c

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
