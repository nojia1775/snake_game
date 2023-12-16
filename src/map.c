#include "../include/snake.h"

static void	init_map(char **map, int h, int l);

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
	while (map[i])
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

static void	init_map(char **map, int h, int l)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
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
