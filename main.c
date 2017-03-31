#include "filler.h"
#include <limits.h>

static int i = 0;


char **ft_get_plateau(char *str, int fd, t_env *e)
{
	char **map;
	char **tmp;
	int y;
	int x;
	int i;
	static int bol = 0;
	int test;

	test = 0;
	i = 8;
	map = NULL;
	tmp = NULL;
	if(bol == 0)
		e->joueur = ft_atoi(ft_strsub(str, 10, 1));
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
		y = 0;
		while(map[i][y] && bol == 0)
		{
			if(map[i][y] == 'X' && e->joueur == 1)
			{
				e->ciblex = i;
				e->cibley = y;
			}
			if(map[i][y] == 'O' && e->joueur == 2)
			{
				e->ciblex = i;
				e->cibley = y;
			}
			y++;
		}
		i++;
	}
	bol = 1;
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
	e->sop_size = 0;
	e->bol = 0;
	ft_bzero(e->sopx, 255);
	ft_bzero(e->sopy, 255);



/*	ft_putstr_fd("\n----------------------\n", fd);
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

void ft_cible(char **tableau, t_env *e, int fd)
{
	int x;
	int y;
	int savex;
	static int bol = 1;

	y = 0;
	x = 0;
	i = 0;
/*	ft_putstr_fd("------plateau-->\n", fd);
	while(tableau[i])
	{
		ft_putstr_fd(tableau[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	i = 0;
	ft_putstr_fd("\n\n\n\n\n\n\n", fd);
	ft_putstr_fd("------befor-->\n", fd);
	while(e->befor && e->befor[i])
	{
			
		ft_putstr_fd(e->befor[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	ft_putstr_fd("\n\n\n\n\n\n\n", fd);*/ //iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
	

ft_putstr_fd("count", fd);

	x = 0;
	while(bol == 0 && tableau[x])
	{
		y = 0;
		while(tableau[x][y] != 0)
		{
			ft_putstr_fd("count", fd);
			if(tableau[x][y] == 'O')
			{
				e->ciblex = x;
				e->cibley = y;
			}
			y++;
		}
		x++;
	}
	bol = 0;
	ft_putstr_fd("\n\n\n\n\n\n\n", fd);
}

int main(int argv, char **argc)
{
	char *str;
	char **plateau;
	t_env e;
	int fd = 0;
	int lol;
	int map;

	//ft_bzero(str, 8096);
	map = 3;
	system("rm test");
	system("touch test");
	fd = open("./test", O_RDWR);
	ft_putstr_fd("coucou", fd);
	e.befor = NULL;
	if(!(str = (char *)malloc(sizeof(char) * 16192)))
		return(-1);
	while(1)
	{
		plateau = NULL;
		ft_memset(str, 0, 16192);
		lol = 0;

		while(lol < (int)(70000000 / 1.0f) && map == 3)
			lol++;
		while(lol < (int)(40000000 / 1.0f) && map == 2)
			lol++;
		while(lol < (int)(30000000 / 1.0f) && map == 1)
			lol++;
		if(read(0, str, 16191) == -1)
			return(0);
		ft_putstr_fd(str, fd);
		if(!(plateau = ft_get_plateau(str, fd, &e)))
			return(0);
		ft_cible(plateau, &e, fd);
		if(ft_strlen(plateau[0]) <= 17 || ft_strlen_tab(plateau) <= 15)
			map = 1;
		else if(ft_strlen(plateau[0]) <= 40 || ft_strlen_tab(plateau) <= 24)
			map = 2;
		else
			map = 3;
	//	ft_putstr_fd(ft_itoa(ft_strlen(plateau[0])), fd);
	//	ft_putstr_fd("           ", fd);
	//	ft_putstr_fd(ft_itoa(ft_strlen_tab(plateau)) ,fd);
	//	ft_putstr_fd("\n", fd);
		if(ft_get_piece(&e, str, fd) == -1)
			return(0);
	//	ft_putstr_fd("11 13\n", fd);

		if(ft_check(plateau, &e, fd) == 0)
			return(0);
		e.befor = plateau;
		//ft_putstr_fd("\nhaha\n", fd)

	}


	
	return(0);
}