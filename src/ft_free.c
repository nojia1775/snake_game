#include "../include/snake.h"

void	ft_free(char **map, snake *head)
{
	int		i;
	
	i = 0;
	while (map[i++])
	{
		printf("free map %d\n", i);
		free(map[i]);
	}
	free(map);
	printf("free map\n");
	free_snake(head);
}
