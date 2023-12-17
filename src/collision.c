#include "../include/snake.h"

static	int	col_q(snake *head);

int	collision(snake *head, obj *fruit, int h, int l)
{
	if (fruit->x == head->x && fruit->y == head->y)
	{
		if (!(queue(head)))
			return (2);
		*fruit = init_fruit(h, l, head);
	}
	if (head->x == 0 || head->x == l - 1 || head->y == 0 || head->y == h - 1)
		return (1);
	if (col_q(head))
		return (1);
	return (0);
}

static int	col_q(snake *head)
{
	snake	*cur;

	if (head->child == NULL)
		return (0);
	cur = head->child;
	while (cur != NULL)
	{
		if (head->x == cur->x && head->y == cur->y)
			return (1);
		cur = cur->child;
	}
	return (0);
}
