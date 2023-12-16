#include "../include/snake.h"

int	main(int argc, char **argv)
{
	char	**map;
	snake	*head;
	int	h;
	int	l;

	h = 10;
	l = 20;
	if (param(argc, argv, &h, &l))
		return (2);
	map = create_map(h, l);
	head = init_snake(h, l);
	aff(map, head);
	ft_free(map, head);
	return (0);
}
