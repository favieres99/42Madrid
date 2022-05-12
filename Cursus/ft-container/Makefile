INCLUDES =	containers/Vector.hpp\
			containers/Stack.hpp\
			iterators/iterator_traits.hpp\
			iterators/RandomAccessIterator.hpp\
			iterators/ReverseIterator.hpp\
			tools/tools.hpp\
			tools/type_traits.hpp\
			ft_tester/includes/main.hpp

SRCS =	ft_tester/vector_test.cpp\
		ft_tester/stack_test.cpp\
		ft_tester/map_test.cpp\
		ft_tester/main.cpp

INCLUDES_STL =	stl_tester/includes/main.hpp

SRCS_STL =	stl_tester/vector_test.cpp\
			stl_tester/stack_test.cpp\
			stl_tester/map_test.cpp\
			stl_tester/main.cpp

NAME = ft_containers

NAME_STL = stl_containers

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

OBJS_STL = $(SRCS_STL:.cpp=.o)

.cpp.o:
		$(CC) -g3 $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS) $(OBJS_STL) $(INCLUDES) $(INCLUDES_STL)
			$(CC) -o $(NAME) $(SRCS)
			$(CC) -o $(NAME_STL) $(SRCS_STL)
			rm -rf stl_containers.dSYM ft_containers.dSYM


all :	$(NAME)

clean :
		rm -rf $(OBJS) $(OBJS_STL)

fclean : clean
		rm -rf $(NAME) $(NAME_STL)

re :	fclean all