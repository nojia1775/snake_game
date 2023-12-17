#include "../include/snake.h"

void	ft_free(char **map, snake *head)
{
	int	i;
	
	i = 0;
	while (map[i++])
		free(map[i]);
	free(map);
	free_snake(head);
}
