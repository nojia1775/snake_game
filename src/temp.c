#include "../include/snake.h"

void	deplacement(char **map, snake *head, obj fruit, int h, int l)
{
	int	dir;
	int	av;

	noecho();
	refresh();
	dir = 0;
	while (1)
	{
		dir = getch();
		av = dir;
		switch (av)
		{
			case 'z':
				head->av_y = head->y;
				head->av_x = head->x;
				head->y--;
				maj_snake(head);
				break;
			case 's':
				head->av_y = head->y;
				head->av_x = head->x;
				head->y++;
				maj_snake(head);
				break;
			case 'q':
				head->av_y = head->y;
				head->av_x = head->x;
				head->x--;
				maj_snake(head);
				break;
			case 'd':
				head->av_y = head->y;
				head->av_x = head->x;
				head->x++;
				maj_snake(head);
				break;
			case '0':
				endwin();
				return ;
				break;
			default:
				break;
		}
		sleep(1);
		clear();
		if (collision(head, &fruit, h, l))
		{
			endwin();
			return ;
		}
		aff(map, head, fruit, h, l);
		refresh();
	}
	endwin();
}
