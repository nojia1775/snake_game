#include "../include/snake.h"

int	param(int argc, char **argv, int *h, int *l)
{
	if (argc > 3)
		return (printf("Trop d'arguments\n"));
	if (argc == 2)
	{
		if (!(ft_strncmp(argv[1], "-h", 3)))
			return (help());
		else
			return (printf("Argument %s invalide\n", argv[1]));
	}
	if (argc == 3)
	{
		*h = ft_atoi(argv[1]);
		*l = ft_atoi(argv[2]);
		if (*h > 50 || *h < 10 || *l > 100 || *l < 20)
			return (printf("Arguments invalides\n10 <= hauteur <= 50\n20 <= largeur <= 100\n"));
	}
	return (0);
}
