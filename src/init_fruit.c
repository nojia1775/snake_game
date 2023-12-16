#include "../include/snake.h"

obj	init_fruit(int h, int l, snake *head)
{
	obj	fruit;

	do
	{
		fruit.y = rand() % (h - 1) + 1;
		fruit.x = rand() % (l - 1) + 1;
	}
	while (fruit.y == head->y && fruit.x == head->x);
	return (fruit);
}
