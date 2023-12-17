#include "../include/snake.h"

int	queue(snake *head)
{
	snake	*last;
	snake	*new;

	last = last_s(head);
	last->child = (snake *)malloc(sizeof(*last));
	if (!(last->child))
		return (0);
	new = last->child;
	new->parent = last;
	new->x = new->parent->av_x;
	new->y = new->parent->av_y;
	new->av_x = new->x;
	new->av_y = new->y;
	new->child = NULL;
	return (1);
}
