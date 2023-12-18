#include "../include/snake.h"

void    highscore(int score)
{
    int     fd;
    char    buf[7] = {0};
    char    *pts;

    fd = open(".highscore", O_RDWR | O_CREAT);
    if (fd < 0)
        return ;
    
    if ((read(fd, buf, 7)) == 0 || score < ft_atoi(buf))
    {
        close(fd);
        return ;
    }
    close(fd);
    system("rm -f .highscore");
    system("touch .highscore");
    system("chmod +r .highscore && chmod +w .highscore");
    fd = open(".highscore", O_RDWR);
    if (fd < 0)
        return ;
    pts = ft_itoa(score);
    write(fd, pts, ft_strlen(pts));
    free(pts);
    close(fd);
}