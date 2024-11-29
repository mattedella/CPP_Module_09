SRC = main.cpp src/PmergeMe.cpp src/Vector.cpp src/Deque.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -f
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Compiled $(NAME)"

%.o: %.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ)
		@echo "Removed object files"

fclean: clean
		@$(RM) $(NAME)
		@echo "Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re