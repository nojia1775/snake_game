#include "../include/snake.h"

void	free_snake(snake *head)
{
	snake	*cur;
	int		i;

	i = 0;
	cur = head->child;
	if (cur == NULL)
	{
		free(head);
		printf("free head");
	}
	else
	{
		while (cur->child != NULL)
		{
			free(cur->parent);
			printf("free head %d\n", i);
			cur = cur->child;
			i++;
		}
		free(cur);
		printf("free head %d\n", i);
	}
}
