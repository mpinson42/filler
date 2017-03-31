#include "filler.h"

int ft_strlen_tab(char **tab)
{
	int i;

	i = 0;
	if(tab == NULL)
	{
		return(0);
	}
	while(tab[i] != NULL)
		i++;
	return(i);
}


int ft_check_place(char **plateau, t_env *e, int fd, int x, int y)
{
	int count;
	int i;
	char *str;
	char *str2;
	int savex;
	int savey;
	int *sop_tmpy;
	int *sop_tmpx;
	static int bol = 0;
	static int test = 0;

	i = 0;
	count = 0;



	if(plateau[x][y] == 'X' || plateau[x][y] == 'X')
		count++;
	if(plateau[x][y] != '.' && plateau[x][y] != 'X' && plateau[x][y] != 'x')
		return(-1);
	while(i < e->taille)
	{
		if(x + e->x[i] > ft_strlen_tab(plateau) - 1|| x + e->x[i] < 0)
			return(-1);
		if(y + e->y[i] > ft_strlen(plateau[x]) || y + e->y[i] < 0)
			return(-1);
		if(plateau[x + e->x[i]][y + e->y[i]] != '.' && plateau[x + e->x[i]][y + e->y[i]] != 'X' && plateau[x + e->x[i]][y + e->y[i]] != 'x')
			return(-1);
		if(plateau[e->x[i] + x][y + e->y[i]] == 'x' || plateau[e->x[i] + x][y + e->y[i]] == 'X')
			count++;
		i++;
	}
	test++;
	if(count != 1)
		return(-1);
	i = 0;




	e->sopx[e->sop_size] = x;
	e->sopy[e->sop_size] = y;


/*	while(i <= e->sop_size)
	{
		ft_putstr_fd("----LA---->", fd);
		ft_putstr_fd(ft_itoa(e->sopx[i]), fd);
		ft_putstr_fd("        ", fd);
		ft_putstr_fd(ft_itoa(e->sopy[i]), fd);
		ft_putstr_fd("\n", fd);
		i++;
	}

	ft_putstr_fd("\n", fd);*/


	e->sop_size++;








	e->bol++;
	return(-1);
}

int ft_sop_chr(t_env *e, int fd)
{
	int i;
	int ciblex;
	int cibley;
	int save;
	int save2;

	i = 0;
	save = 999999999;
	save2 = 0;
	while(i < e->sop_size)
	{
		ciblex = ft_absolut(e->ciblex - e->sopx[i]);
		cibley = ft_absolut(e->cibley - e->sopy[i]);
		ciblex = ciblex + cibley;

		if(ciblex < save)
		{
			save = ciblex;
			save2 = i;
		}

		ft_putstr_fd("----LA---->", fd);
		ft_putstr_fd(ft_itoa(e->ciblex), fd);
		ft_putstr_fd("        ", fd);
		ft_putstr_fd(ft_itoa(e->cibley), fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	return(save2);
}

int ft_check(char **plateau, t_env *e, int fd)
{
	int x;
	int y;
	int i;
	int j;
	int test = 0;
	char *str;
	char *str2;

	x = 0;
	i = 0;
	while(plateau[x])
	{
		y = 0;
		while(plateau[x][y] != 0)
		{
			if(x == ft_strlen_tab(plateau) && y == ft_strlen(plateau[x]))
				exit(0);
			if(ft_check_place(plateau, e, fd, x, y) == 0)
				return(1);
			test++;
			y++;
		}
		x++;
	}


	i = ft_sop_chr(e, fd);

	str = ft_strjoin(ft_itoa(e->sopx[i] - e->co_1erx), " ");
	str2 = ft_strjoin(ft_itoa(e->sopy[i] - e->co_1ery), "\n");
	ft_putstr(ft_strjoin(str, str2));



	return(1);
}






//plateau = 24
//plateau[] = 39