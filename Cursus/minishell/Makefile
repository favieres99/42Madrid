NAME     = minishell
CFLAGS   = -Wall -Wextra -Werror
INC      = -Iincludes/ -I$(LIB_DIR)/

SRC      = minishell.c builtins.c find_env.c ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c \
			init_path.c redir_in.c redir_out.c run_pipe.c run_pipe_aux.c signal.c split_cmd.c token.c token_aux.c

OBJ_NAME = $(SRC:.c=.o)
OBJ      = $(addprefix $(OBJ_DIR),$(OBJ_NAME)) 

LIB_DIR  = libft/
SRC_DIR  = src/
OBJ_DIR  = objs/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft -lreadline -lncurses -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
	@echo "##### Compiling finished #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p objs/builtins
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