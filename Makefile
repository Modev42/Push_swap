NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = main.c \
      ops_push.c \
      ops_swap.c \
      ops_rotate.c \
      utils.c \
      sort_small.c \
      sort_main.c \
      ft_split.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re