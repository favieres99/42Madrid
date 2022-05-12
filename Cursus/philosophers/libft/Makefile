SRCS		=	ft_atoi.c ft_strlen.c

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