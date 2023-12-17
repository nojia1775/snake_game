#ifndef SNAKE_H

# define SNAKE_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <time.h>
# include <ncurses.h>

typedef struct s_snake	snake;
typedef struct s_obj	obj;

int	help(void);
char	**create_map(int h, int l);
void	ft_free(char **map, snake *head);
snake	*init_snake(int h, int l);
int	param(int argc, char **argv, int *h, int *l);
void	aff(char **map, snake *head, obj fruit, int h, int l);
obj	init_fruit(int h, int l, snake *head);
void	deplacement(char **map, snake *head, obj fruit, int h, int l);
void	init_map(char **map, int h, int l);
int	collision(snake *head, obj *fruit, int h, int l);
int	queue(snake *head);
snake	*last_s(snake *head);
void	maj_snake(snake *head);
void	free_snake(snake *head);

struct	s_snake
{
	int	x;
	int	y;
	int	av_x;
	int	av_y;
	snake	*parent;
	snake	*child;
};

struct	s_obj
{
	int	x;
	int	y;
};

#endif
