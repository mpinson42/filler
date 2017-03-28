#include "filler.h"
#include <limits.h>

static int i = 0;


char **ft_get_plateau(char *str, int fd)
{
	char **map;
	char **tmp;
	int y;
	int x;
	int i;

	i = 8;
	str = ft_strstr(str, "Plateau ");
	x = ft_atoi(&str[8]);
	while(ft_isdigit(str[i]))
		i++;
	y = ft_atoi(&str[i]);
	map = (char **)malloc(sizeof(char *) * (x + 1));
	map[x + 1] = NULL;
	i = 0;
	while(map[i])
	{
		map[i] = (char *)malloc(sizeof(char) * (y + 1));
		ft_bzero(map[i], y + 1);
		i++;
	}
	str = ft_strstr(str, "000");
	tmp = ft_strsplit(ft_strsub(str, 0, (y + 5) * x), '\n');
	i = 0;
	while(tmp[i])
	{
		map[i] = ft_strsub(tmp[i], 5, y);
		i++;
	}
	return(map);
}


void ft_get_piece(t_env *e, char *str, int fd)
{
	int i;
	int y;
	int posx;
	int posy;
	int bol;
	int count;
	char **tmp;

	i = 0;
	bol = 0;
	count = 0;
	str = ft_strstr(str, "Piece");
	while(str[i] && str[i] != '.' && str[i] != '*')
		i++;
	str = ft_strsub(str, i, ft_strlen(str));
	i = 0;
	while(str[i])
	{
		if(str[i] == '*')
			count++;
		i++;
	}
	count = count - 1;
	e->x = (int *)malloc(sizeof(int) * (count));
	e->y = (int *)malloc(sizeof(int) * (count));
	tmp = ft_strsplit(str, '\n');

	i = 0;
	while(tmp[i])
	{
		y = 0;
		while(tmp[i][y])
		{
			if(tmp[i][y] == '*' && bol < 1)
			{
				posx = i;
				posy = y;
				bol++;
			}
			else if(tmp[i][y] == '*')
			{
				e->x[bol - 1] = i - posx;
				e->y[bol - 1] = y - posy;
				bol++;
			}
			y++;
		}
		i++;
	}
	e->taille = count;


	ft_putstr_fd("----------------------\n", fd);
	i = 0;
	while(i < count)
	{
		ft_putstr_fd(ft_itoa(e->x[i]), fd);
		ft_putstr_fd(" ", fd);
		i++;
	}
	ft_putstr_fd("\n", fd);
	i = 0;
	while(i < count)
	{
		ft_putstr_fd(ft_itoa(e->y[i]), fd);
		ft_putstr_fd(" ", fd);
		i++;
	}
	ft_putstr_fd("\n----------------------", fd);


}

int main(int argv, char **argc)
{
	char *str;
	char **plateau;
	t_env e;
	int fd;

	fd = open("./test", O_RDWR);
	str = (char *)malloc(sizeof(char) * 2001);
	while(1)
	{
		if(i == 2)
			return(0);

		sleep(1);
		read(0, str, 2000);
		plateau = ft_get_plateau(str, fd);
		ft_get_piece(&e, str, fd);






		ft_putstr_fd(str, fd);
		ft_putstr_fd("\n\n\n\n\n\n\n", fd);
		ft_putstr("11 13\n");
		free(str);
		i++;
	}


	
	return(0);
}