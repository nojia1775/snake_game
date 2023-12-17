#include "../include/snake.h"

void	maj_snake(snake *head)
{
	snake	*cur;

	cur = head->child;
	while (cur != NULL)
	{
		cur->av_x = cur->x;
		cur->av_y = cur->y;
		cur->x = cur->parent->av_x;
		cur->y = cur->parent->av_y;
		cur = cur->child;
	}
}
