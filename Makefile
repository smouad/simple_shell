NAME = shell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

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