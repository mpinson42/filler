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
	static int test = 0;

	i = 0;
	count = 0;



	if(plateau[x][y] == 'X' || plateau[x][y] == 'X')
		count++;
	if(plateau[x][y] != '.' && plateau[x][y] != 'X' && plateau[x][y] != 'x')
		return(-1);
	ft_putstr_fd(ft_itoa(e->x[i]), fd);
	while(i < e->taille)
	{
//		ft_putstr_fd("\nppppppppppppppppppppppppp\n", fd);
//		ft_putstr_fd(ft_itoa(y + e->y[i]), fd);
//		ft_putstr_fd(" > ", fd);
//		ft_putstr_fd(ft_itoa(ft_strlen(plateau[x])), fd);
//		ft_putstr_fd("\n", fd);
//		ft_putstr_fd("\nppppppppppppppppppppppppp\n", fd);





		if(x + e->x[i] > ft_strlen_tab(plateau) - 1|| x + e->x[i] < 0)
		{
			ft_putstr_fd(ft_itoa(test), fd);
			ft_putstr_fd("\n", fd);
			return(-1);
		}
		if(y + e->y[i] > ft_strlen(plateau[x]) || y + e->y[i] < 0)
		{
			ft_putstr_fd(ft_itoa(test), fd);
			ft_putstr_fd("\n", fd);
			return(-1);
		}
		if(plateau[x + e->x[i]][y + e->y[i]] != '.' && plateau[x + e->x[i]][y + e->y[i]] != 'X' && plateau[x + e->x[i]][y + e->y[i]] != 'x')
			return(-1);
		if(plateau[e->x[i] + x][y + e->y[i]] == 'x' || plateau[e->x[i] + x][y + e->y[i]] == 'X')
			count++;











		i++;
	}
	test++;
//	ft_putstr_fd(ft_itoa(count), fd);
	if(count != 1)
		return(-1);

	if(test == 100)
		exit(0);
	str = ft_strjoin(ft_itoa(x - e->co_1erx), " ");
	str2 = ft_strjoin(ft_itoa(y - e->co_1ery), "\n");
	ft_putstr_fd(ft_strjoin(str, str2), fd);
	ft_putstr(ft_strjoin(str, str2));

	return(0);
}

int ft_check(char **plateau, t_env *e, int fd)
{
	int x;
	int y;
	int i;
	int j;
	int test = 0;

	x = 0;
	i = 0;
/*	while(plateau[x] != NULL)
	{
		ft_putstr_fd(plateau[x], fd);
		ft_putstr_fd("\n", fd);
		x++;
	}*/
	while(plateau[x])
	{
		y = 0;
		while(plateau[x][y] != 0)
		{
			if(x == ft_strlen_tab(plateau) && y == ft_strlen(plateau[x]))
				exit(0);
			if(ft_check_place(plateau, e, fd, x, y) == 0)
				return(1);
//			ft_putstr_fd(ft_itoa(test), fd);
//			ft_putstr_fd("\n", fd);
			test++;
			y++;
		}
		x++;
	}
	exit(0);
}






//plateau = 24
//plateau[] = 39