#include "../include/snake.h"

static int	size(int n);
static void	fill(char *result, int n, int *i);

char	*my_itoa(int n)
{
	int		i;
	int		len;
	char	*result;
	
	i = 0;
	len = size(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	fill(result, n, &i);
	return (result);
}

static int	size(int n)
{
	int		i;
	int		len;

	len = 1;
	i = 10;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / i != 0)
	{
		len++;
		i += 10;
	}
	return (len);
}

static void	fill(char *result, int n, int *i)
{
	if (n == -2147483648)
	{
		result[0] = '-';
		result[10] = '8';
		n /= -10;
		(*i)++;
	}
	else if (n < 0)
	{
		result[0] = '-';
		n *= -1;
		(*i)++;
	}
	else if (n > 10)
	{
		fill(result, n / 10, i);
		fill(result, n % 10, i);
	}
	else
		result[(*i)++] = '0' + n;
}
