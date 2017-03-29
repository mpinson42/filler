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
//	ft_putstr_fd("non", fd);
	str = ft_strstr(str, "Plateau ");
	x = ft_atoi(&str[8]);
	while(ft_isdigit(str[i]))
		i++;
	y = ft_atoi(&str[i]);
	if(!(map = (char **)malloc(sizeof(char *) * (x + 1))))
		return(NULL);
	map[x + 1] = NULL;
	i = 0;

	while(map[i])
	{
		if(!(map[i] = (char *)malloc(sizeof(char) * (y + 1))))
			return(NULL);
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


int ft_get_piece(t_env *e, char *str, int fd)
{
	int i;
	int y;
	int posx;
	int posy;
	int bol;
	int count;
	char **tmp;
	int first;
	int segond;

	i = 6;
	bol = 0;
	count = 0;
	str = ft_strstr(str, "Piece");
	first = ft_atoi(&str[6]);
	while(ft_isdigit(str[i]))
		i++;
	segond = ft_atoi(&str[i]);

/*	ft_putstr_fd("\nchifffffffre\n", fd);
	ft_putstr_fd("first = ", fd);
	ft_putstr_fd(ft_itoa(first), fd);
	ft_putstr_fd("segond = ", fd);
	ft_putstr_fd(ft_itoa(segond), fd);*/

	i = 0;
	while(str[i] && str[i] != '.' && str[i] != '*')
		i++;
	str = ft_strsub(str, i, first * (segond + 1));
	i = 0;
	while(str[i])
	{
		if(str[i] == '*')
			count++;
		i++;
	}
	count = count - 1;
	if(!(e->x = (int *)malloc(sizeof(int) * (count))))
		return(-1);
	if(!(e->y = (int *)malloc(sizeof(int) * (count))))
		return(-1);
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
				e->co_1erx = i;
				e->co_1ery = y - 1;
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

/*
	ft_putstr_fd("\n----------------------\n", fd);
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
	ft_putstr_fd("\n----------------------\n", fd);*/

	return(0);
}

int main(int argv, char **argc)
{
	char *str;
	char **plateau;
	t_env e;
	int fd;
	int lol;

	//ft_bzero(str, 8096);
	system("rm test");
	system("touch test");
	fd = open("./test", O_RDWR);
	if(!(str = (char *)malloc(sizeof(char) * 8096)))
		return(-1);
//	ft_putstr("11 13\n");
	while(1)
	{
		ft_memset(str, 0, 8096);
		lol = 0;
		while(lol < 9999999)
			lol++;
		if(read(0, str, 8095) == -1)
			return(0);
		if(!(plateau = ft_get_plateau(str, fd)))
			return(0);
		if(ft_get_piece(&e, str, fd) == -1)
			return(0);

//		ft_putstr_fd(str, fd);
//		ft_putstr_fd("\n\n\n\n\n\n\n", fd);

		if(ft_check(plateau, &e, fd) == 0)
			return(0);
	}


	
	return(0);
}