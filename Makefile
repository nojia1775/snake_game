CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = src/main.c \
       src/help.c \
       src/map.c \
       src/ft_free.c \
       src/init_snake.c \
       src/param.c \
       src/aff.c \
       src/init_fruit.c \
       src/deplacement.c \
       src/collision.c \
       src/queue.c \
       src/maj_snake.c \
       src/last_s.c \
       src/free_snake.c \
       src/highscore.c \
       src/my_itoa.c

SRCS_A = alias/get_next_line.c \
	 alias/get_next_line_utils.c \
	 alias/prog.c 

OBJS = $(SRCS:.c=.o)

NAME = snake

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ include/libft.a -lcurses

all: $(NAME)

install: all
	mkdir -p ~/.myBin
	mv snake ~/.myBin
	$(CC) $(CFLAGS) $(SRCS_A) -o main
	./main
	rm main
	. ~/.zshrc

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f snake

re: fclean all

.PHONY: all clean fclean re
