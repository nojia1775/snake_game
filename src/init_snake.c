#include "../include/snake.h"

snake	*init_snake(int h, int l)
{
	snake	*head;

	head = (snake *)malloc(sizeof(*head));
	if (!head)
		return (NULL);
	head->x = l / 2 - 1;
	head->y = h / 2 - 1;
	head->av_x = head->x;
	head->av_y = head->y;
	head->parent = NULL;
	head->child = NULL;
	return (head);
}
