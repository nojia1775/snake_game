#include "../include/snake.h"

char	**create_map(int h, int l)
{
	char	**map;
	int	i;
	int	f;

	f = 0;
	i = 0;
	map = (char **)malloc(sizeof(char *) * (h + 1));
	if (!map)
		return (NULL);
	map[h] = NULL;
	while (i < h)
	{
		map[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!map[i])
		{
			while (map[f])
			{
				free(map[f++]);
				free(map);
			}
		}
		map[i][l] = '\0';
		i++;
	}
	init_map(map, h, l);
	return (map);
}

void	init_map(char **map, int h, int l)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < l)
		{
			if (i == 0 || i == h - 1)
				map[i][j] = '#';
			else if (j == 0 || j == l - 1)
				map[i][j] = '#';
			else
				map[i][j] = ' ';
			j++;
		}
		i++;
	}
}
