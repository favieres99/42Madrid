# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 12:36:23 by gfaviere          #+#    #+#              #
#    Updated: 2019/11/21 15:19:30 by gfaviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
				ft_memset.c  ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
				ft_atoi.c ft_bzero.c ft_calloc.c ft_strdup.c \
				ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_split.c

BSRCS		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonu.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c

HEADS		=	libft.h

OBJS		=	$(SRCS:.c=.o)

BNOBJS		=	$(BSRCS:.c=.o)

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

.c.o:			$(HEADS)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

bonus:			$(BNOBJS) $(OBJS)
				ar rc $(NAME) $(BNOBJS)
				ranlib $(NAME)

all:			$(NAME)

clean:
				rm -f $(OBJS)
				rm -f $(BNOBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
