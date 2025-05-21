NAME = Animal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Dog.cpp Cat.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp

OBJ = $(CFILES:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
