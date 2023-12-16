#include "../include/snake.h"

void	deplacement(char **map, snake *head, obj fruit, int h, int l)
{
	int	dir;
	int	av;

	noecho();
	refresh();
	av = 0;
	while (1)
	{
		dir = getch();
		switch (dir)
		{
			case 'z':
				if (av == 's')
					break;
				head->y--;
				break;
			case 's':
				if (av == 'z')
					break;
				head->y++;
				break;
			case 'q':
				if (av == 'd')
					break;
				head->x--;
				break;
			case 'd':
				if (av == 'q')
					break;
				head->x++;
				break;
			case '0':
				endwin();
				return ;
				break;
			default:
				printw("touch = %c\n", dir);
				break;
		}
		clear();
		if (collision(head, &fruit, h, l))
		{
			endwin();
			return ;
		}
		av = dir;
		aff(map, head, fruit, h, l);
		refresh();
	}
	endwin();
}
