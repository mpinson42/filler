#include "filler.h"

int ft_strlen_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i] != NULL)
		i++;
	return(i - 1);
}


int ft_check_place(char **plateau, t_env *e, int fd, int x, int y)
{
	int i;
	int bol;
	char *str;
	char *str2;
	int count;

	i = 0;
	bol = 0;
	count = 0;
	while(i <= e->taille)
	{
		if(plateau[x][y] == 'x' || plateau[x][y] == 'X')
			count++;
		if(plateau[x][y] != 'x' && plateau[x][y] != 'X' && plateau[x][y] != '.')
			return(-1);
		if(e->x[i] + x > ft_strlen(plateau[0]) || e->x[i] + x < 0)
			return(-1);
		if(e->y[i] + y > ft_strlen_tab(plateau) || e->y[i] + y < 0)
			return(-1);
		

		if(plateau[e->x[i] + x][e->y[i] + y] == 'x' || plateau[e->x[i] + x][e->y[i] + y] == 'X')
			count++;
		if(plateau[e->x[i] + x][e->y[i] + y] != 'x' && plateau[e->x[i] + x][e->y[i] + y] != 'X' && plateau[e->x[i] + x][e->y[i] + y] != '.')
			return(-1);
		i++;
	}
	//ft_putstr_fd("strop putin\n", fd);
	if(count != 1)
			return(-1);

	ft_putstr_fd("\n\n ----->", fd);
	ft_putstr_fd(ft_itoa(x), fd);
	ft_putstr_fd(" - ", fd);
	ft_putstr_fd(ft_itoa(e->co_1erx), fd);
	ft_putstr_fd(" ------ ", fd);
	ft_putstr_fd(ft_itoa(y), fd);
	ft_putstr_fd(" - ", fd);
	ft_putstr_fd(ft_itoa(e->co_1ery), fd);
	ft_putstr_fd("\n", fd);




	str = ft_strjoin(ft_itoa(x - e->co_1erx), " ");
	str2 = ft_strjoin(ft_itoa(y - e->co_1ery), "\n");
	ft_putstr_fd(ft_strjoin(str, str2), fd);
	ft_putstr(ft_strjoin(str, str2));
	//	ft_putstr_fd("oui", fd);
	//	ft_putstr_fd(ft_itoa(ft_strlen(ft_strjoin(str, str2))), fd);
	return(1);

	i = 0;







	return(-1);
}




int ft_check(char **plateau, t_env *e, int fd)
{
	int x;
	int y;

	x = 0;
//	ft_putstr_fd("---------bite", fd);
	while(plateau[x] != NULL)
	{
		y = 0;
		while(plateau[x][y])
		{
			if(ft_check_place(plateau, e, fd, x, y) == 1)
				return(1);
			y++;
		}
		x++;
	}
	return(0);
}





//x piece -> ligne
//y piece -> colone