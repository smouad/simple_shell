NAME = hsh

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 #-fsanitize=address -g

SRC = *.c

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean

re: fclean all

run: re
	./$(NAME)