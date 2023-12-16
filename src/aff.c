#include "../include/snake.h"

void	aff(char **map, snake *head)
{
	int	i;
	int	j;

	i = 0;
	map[head->y][head->x] = 'O';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			printf("%c", map[i][j++]);
		i++;
		printf("\n");
	}
}
