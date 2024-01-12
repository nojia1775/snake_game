#include "../include/snake.h"

void    highscore(int score)
{
	int     fd;
	char    buf[7] = {0};
	char    *pts;

	fd = open(".highscore", O_RDWR | O_CREAT);
	if (fd < 0)
		return ;
	read(fd, buf, sizeof(buf));
	if (score < ft_atoi(buf))
	{
		close(fd);
		return ;
	}
	close(fd);
	system("rm -f .highscore");
	system("touch .highscore");
	fd = open(".highscore", O_RDWR);
	if (fd < 0)
	{
		printf("pb fd 2\n");
		return ;
	}
	pts = ft_itoa(score);
	write(fd, pts, ft_strlen(pts));
	free(pts);
	close(fd);
}
