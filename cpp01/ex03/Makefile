NAME = Zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJ = $(CFILES:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
