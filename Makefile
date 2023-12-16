CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = src/main.c \
       src/help.c \
       src/map.c \
       src/ft_free.c \
       src/init_snake.c \
       src/param.c \
       src/aff.c \
       src/init_fruit.c

OBJS = $(SRCS:.c=.o)

NAME = snake

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ include/libft.a

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f snake

re: fclean all

.PHONY: all clean fclean re
