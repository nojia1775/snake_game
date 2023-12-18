#include "../include/snake.h"

int	main(int argc, char **argv)
{
	char	**map;
	snake	*head;
	obj		fruit;
	int		h;
	int		l;
	int		score;

	score = 0;
	srand(time(NULL));
	h = 10;
	l = 20;
	if (param(argc, argv, &h, &l))
		return (2);
	initscr();
	map = create_map(h, l);
	head = init_snake(h, l);
	fruit = init_fruit(h, l, head);
	if (!head || !map)
		return (3);
	aff(map, head, fruit, h, l, &score);
	deplacement(map, head, fruit, h, l, &score);
	ft_free(map, head);
	system("clear");
	if (score == l * h * 10)
	{
		printf("Bravo tu as gagne !\nScore : %d", score);
		return (0);
	}
	printf("Game Over\nScore : %d\n", score);
	highscore(score);
	return (0);
}
