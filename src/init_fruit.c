#include "../include/snake.h"

static int	col_sf(snake *head, obj fruit);

obj	init_fruit(int h, int l, snake *head)
{
	obj		fruit;

	do
	{
		fruit.y = rand() % (h - 2) + 1;
		fruit.x = rand() % (l - 2) + 1;
	}
	while (col_sf(head, fruit));
	return (fruit);
}

static int	col_sf(snake *head, obj fruit)
{
	snake	*cur;

	cur = head;
	while (cur != NULL)
	{
		if (fruit.x == cur->x && fruit.y == cur->y)
			return (1);
		cur = cur->child;
	}
	return (0);
}
