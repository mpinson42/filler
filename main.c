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
	int test;

	test = 0;
	i = 8;
	map = NULL;
	tmp = NULL;
	if(!(str = ft_strstr(str, "Plateau ")))
		return(0);
	x = ft_atoi(&str[8]);
	while(str[i] && ft_isdigit(str[i]))
		i++;
	y = ft_atoi(&str[i]);
	if(!(map = (char **)malloc(sizeof(char *) * (x + 1))))
		return(NULL);
	while(test < x + 1)
	{
		map[test] = NULL;
		test++;
	}
	i = 0;

	while(map[i])
	{
		if(!(map[i] = (char *)malloc(sizeof(char) * (y + 2))))
			return(NULL);
		ft_memset(map[i],0, y + 2);
		i++;
	}
	if(!(str = ft_strstr(str, "000")))
		return(NULL);
	if(!(tmp = ft_strsplit(ft_strsub(str, 0, (y + 5) * x), '\n')))
		return(NULL);
	i = 0;
	while(tmp[i])
	{
		if(!(map[i] = ft_strsub(tmp[i], 4, ft_strlen(tmp[i]))))
			return(NULL);
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
	y = 0;
	posy = 0;
	posy = 0;
	tmp = NULL;
	if(!(str = ft_strstr(str, "Piece")))
		return(-1);
	first = ft_atoi(&str[6]);
	while(str[i] && ft_isdigit(str[i]))
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
	if(!(str = ft_strsub(str, i, first * (segond + 1))))
		return(-1);
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
	if(!(tmp = ft_strsplit(str, '\n')))
		return(-1);

	i = 0;
	while(tmp[i] != NULL)
	{
		y = 0;
		while(tmp[i][y] != 0)
		{
			if(tmp[i][y] == '*' && bol < 1)
			{
				posx = i;
				posy = y;
				e->co_1erx = i;
				e->co_1ery = y;
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
	ft_putstr_fd("\n----------------------\n", fd);

	return(0);
}

int main(int argv, char **argc)
{
	char *str;
	char **plateau;
	t_env e;
	int fd = 0;
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
		plateau = NULL;
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




		ft_putstr_fd(str, fd);
		ft_putstr_fd("\n\n\n\n\n\n\n", fd);

		if(ft_check(plateau, &e, fd) == 0)
			return(0);
		//ft_putstr_fd("\nhaha\n", fd)

	}


	
	return(0);
}