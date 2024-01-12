#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	FILE	*fd;

	fd = fopen("/home/nadjemia/.zshrc", "a");
	if (fd != NULL)
		fprintf(fd, "\n\nalias snake=/home/nadjemia/.myBin/snake");
	else
		return (2);
	fclose(fd);
	return (0);
}
