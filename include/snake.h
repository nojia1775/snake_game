#ifndef SNAKE_H

# define SNAKE_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_snake	snake;

int	help(void);
char	**create_map(int h, int l);
void	ft_free(char **map, snake *head);
snake	*init_snake(int h, int l);
int	param(int argc, char **argv, int *h, int *l);
void	aff(char **map, snake *head);

struct	s_snake
{
	int	x;
	int	y;
	snake	*parent;
	snake	*child;
};

#endif
