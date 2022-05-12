# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 11:18:45 by gfaviere          #+#    #+#              #
#    Updated: 2021/06/10 14:23:57 by gfaviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK_NAME = checker
PUSH_NAME = push_swap
FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/ -I$(LIB_DIR)/

CHECK_SRC_NAME = checker.c commands_utils.c commands.c sort_utils.c \
sort.c stack_pop.c stack_push.c stack.c stack2.c utils.c valid.c

CHECK_OBJ_NAME = $(CHECK_SRC_NAME:.c=.o)
CHECK_OBJ = $(addprefix $(OBJ_DIR),$(CHECK_OBJ_NAME))

PUSH_SRC_NAME = push_swap.c commands_utils.c commands.c sort_utils.c \
sort.c stack_pop.c stack_push.c stack.c stack2.c utils.c valid.c

PUSH_OBJ_NAME = $(PUSH_SRC_NAME:.c=.o)
PUSH_OBJ = $(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

LIB_DIR = libft/
SRC_DIR = src/
OBJ_DIR = objs/

all: $(CHECK_NAME) $(PUSH_NAME)

$(CHECK_NAME): $(CHECK_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(CHECK_NAME) $(CHECK_OBJ) -L $(LIB_DIR) -lft
	@echo "##### checker compiling finished! #####"

$(PUSH_NAME): $(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft
	@echo "##### push_swap compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(CHECK_NAME) $(PUSH_NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re