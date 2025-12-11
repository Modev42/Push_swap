NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
       text_operations.c \
       text_operations2.c \
       tokenizer.c \
       tokenizer2.c \
       stack_implementation.c \
       stack_utils.c \
       operations.c \
       operations2.c \
       validation.c \
       validation2.c \
       algorithm_helpers.c \
       median_calculator.c \
       sort_small_sets.c \
       sort_large_sets.c \
       sort_large_utils.c \
       sort_controller.c \
       memory_management.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re