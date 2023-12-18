#include "../include/snake.h"

static int	aff_snake(snake *head, int i, int j);
static void	aff_item(char **map, snake *head, obj fruit);

void	aff(char **map, snake *head, obj fruit, int h, int l, int *score)
{
	int		i;
	int		j;
	int		fd;
	int		high;
	char	buf[7] = {0};

	fd = open(".highscore", O_RDONLY);
	if (fd < 0)
		high = 0;
	else
	{
		read(fd, buf, 7);
		high = ft_atoi(buf);
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	i = 0;
	printw("------------------------- SNAKE --------------------------\n\n");
	printw("SCORE : %d\nHIGHSCORE : %d\n\n", *score, high);
	init_map(map, h, l);
	aff_item(map, head, fruit);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (fruit.x == j && fruit.y == i)
			{
				attron(COLOR_PAIR(1));
				printw("%c", map[i][j]);
				attroff(COLOR_PAIR(1));
			}
			else if (aff_snake(head, i, j))
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
	endwin();
}

static int	aff_snake(snake *head, int i, int j)
{
	snake	*cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->x == j && cur->y == i)
			return (1);
		cur = cur->child;
	}
	return (0);
}

static void	aff_item(char **map, snake *head, obj fruit)
{
	snake	*cur;

	map[head->y][head->x] = 'O';
	map[fruit.y][fruit.x] = '@';
	cur = head->child;
	while (cur != NULL)
	{
		map[cur->y][cur->x] = 'o';
		cur = cur->child;
	}
}
