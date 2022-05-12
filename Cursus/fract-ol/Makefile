NAME = fractol

SRC = main.c draw.c draw_0.c draw_1.c hooks.c pixel_put.c compute.c check_arg.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -I. -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) libft/libft.a $(SRC) -o $(NAME) -lpthread -lm -lmlx -framework Appkit -framework OpenGL

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
