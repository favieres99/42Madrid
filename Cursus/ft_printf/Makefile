# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 14:01:45 by gfaviere          #+#    #+#              #
#    Updated: 2019/12/21 23:07:12 by gfaviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

FT_PRINTF_SRC = ft_calchex.c ft_printf.c ft_printf_utils.c ft_imprimirtodo.c \
				ft_flag.c ft_char.c ft_str.c ft_int.c ft_pointer.c ft_porcentaje.c \
				ft_printf_pututils.c ft_printf_pututils2.c ft_hex.c ft_int0.c \
				ft_intneg.c ft_hex0.c ft_prechex.c

LIBFT_PATH = libft/
LIBFT_SRC = ft_isdigit.c ft_strlen.c ft_atoi.c ft_itoa.c ft_putchar.c

OBJ += $(FT_PRINTF_SRC:.c=.o)
OBJ += $(addprefix $(LIBFT_PATH),$(LIBFT_SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

CLEAR_LINE = \033[2K\c

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\nCreating $@"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo "$(CLEAR_LINE)"
	@echo "Compiling $<\r\c"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re