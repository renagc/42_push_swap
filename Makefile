NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = main.c list_utils.c libft_utils.c ft_exit.c rules.c moves.c calc_utils.c sort_utils.c cost_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) ft_printf/libftprintf.a -o push_swap
	rm -rf $(OBJECTS)

sanita:
	$(CC) $(SOURCES) ft_printf/libftprintf.a -fsanitize=address -g -o push_swap

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME) push_swap

make re: fclean all
