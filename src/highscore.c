#include "../include/snake.h"

void    highscore(int score)
{
    int     fd;
    char    buf[7];

    fd = open(".highscore", O_RDWR | O_CREAT);
    if (fd < 0)
        return ;
    read(fd, buf, 7);
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
        return ;
    write(fd, ft_itoa(score), ft_strlen(ft_itoa(score)));
    close(fd);
}