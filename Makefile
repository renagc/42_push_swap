NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = main.c list_utils.c libft_utils.c ft_exit.c rules.c moves.c calc_utils.c sort_utils.c cost_utils.c
BONUS_SRC = checker.c list_utils.c libft_utils.c ft_exit.c rules.c moves.c calc_utils.c sort_utils.c cost_utils.c
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	make -C ft_printf/
	$(CC) $(CFLAGS) $(SOURCES) ft_printf/libftprintf.a -o push_swap

sanita:
	$(CC) $(SOURCES) ft_printf/libftprintf.a -fsanitize=address -g -o push_swap

clean:
	$(RM) $(OBJECTS)

fclean: clean
	make fclean -C ft_printf/
	$(RM) $(NAME) push_swap

make re: fclean all
