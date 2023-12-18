#include "../include/snake.h"

void	deplacement(char **map, snake *head, obj fruit, int h, int l, int *score)
{
	int		dir;
	int		av;

	noecho();
	refresh();
	dir = 0;
	if (dir == 'z' || dir == 's')
		timeout(4500 / h);
	else
		timeout(4500 / l);
	while (1)
	{
		av = dir;
		if ((dir = getch()) == ERR)	
			dir = av;
		switch (dir)
		{
			case 'z':
				if (av == 's')
				{
					dir = 's';
					break;
				}
				head->av_y = head->y;
				head->av_x = head->x;
				head->y--;
				maj_snake(head);
				break;
			case 's':
				if (av == 'z')
				{
					dir = 'z';
					break;
				}
				head->av_y = head->y;
				head->av_x = head->x;
				head->y++;
				maj_snake(head);
				break;
			case 'q':
				if (av == 'd')
				{
					dir = 'd';
					break;
				}
				head->av_y = head->y;
				head->av_x = head->x;
				head->x--;
				maj_snake(head);
				break;
			case 'd':
				if (av == 'q')
				{
					dir = 'q';
					break;
				}
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
		clear();
		if (collision(head, &fruit, h, l, score) || *score == l * h * 10)
		{
			endwin();
			return ;
		}
		aff(map, head, fruit, h, l, score);
		refresh();
	}
	endwin();
}
