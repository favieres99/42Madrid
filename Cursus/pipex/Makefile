NAME     = pipex
CFLAGS   = -Wall -Wextra -Werror
INC      = -Iincludes/ -I$(LIB_DIR)/

SRC      = pipex.c utils.c utils2.c

OBJ_NAME = $(SRC:.c=.o)
OBJ      = $(addprefix $(OBJ_DIR),$(OBJ_NAME)) 

LIB_DIR  = libft/
SRC_DIR  = src/
OBJ_DIR  = objs/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft
	@echo "##### Compiling finished #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean --silent
	@rm -f $(OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re