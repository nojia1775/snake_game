#include "../include/snake.h"

void	free_snake(snake *head)
{
	snake	*cur;

	cur = head->child;
	if (cur == NULL)
		free(head);
	else
	{
		while (cur->child != NULL)
		{
			free(cur->parent);
			cur = cur->child;
		}
		free(cur);
	}
}
