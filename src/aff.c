#include "../include/snake.h"

void	aff(char **map, snake *head, obj fruit, int h, int l)
{
	int	i;
	int	j;

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	i = 0;
	init_map(map, h, l);
	map[head->y][head->x] = 'O';
	map[fruit.y][fruit.x] = '@';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == fruit.y && j == fruit.x)
			{
				attron(COLOR_PAIR(1));
				printw("%c", map[i][j]);
				attroff(COLOR_PAIR(1));
			}
			else if (i == head->y && j == head->x)
			{
				attron(COLOR_PAIR(2));
				printw("%c", map[i][j]);
				attroff(COLOR_PAIR(2));
			}
			else
				printw("%c", map[i][j]);
			j++;
		}
		i++;
		printw("\n");
	}
}
