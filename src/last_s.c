#include "../include/snake.h"

snake	*last_s(snake *head)
{
	snake	*cur;

	cur = head;
	while (cur->child != NULL)
		cur = cur->child;
	return (cur);
}
