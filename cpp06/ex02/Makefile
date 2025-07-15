NAME = convert
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Base.cpp A.cpp B.cpp C.cpp

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
