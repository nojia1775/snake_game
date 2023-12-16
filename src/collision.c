#include "../include/snake.h"

int	collision(snake *head, obj *fruit, int h, int l)
{
	if (fruit->x == head->x && fruit->y == head->y)
		*fruit = init_fruit(h, l, head);
	if (head->x == 0 || head->x == l - 1 || head->y == 0 || head->y == h - 1)
		return (1);
	return (0);
}
