/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:54:09 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/01 22:54:15 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

static int i = 0;


char **ft_get_plateau(char *str, t_env *e)
{
	char **map;
	char **tmp;
	int y;
	int x;
	int i;
	static int bol = 0;
	int test;

	test = -1;
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
	while(++test < x + 1)
		map[test] = NULL;
	i = -1;
	while(map[++i])
	{
		if(!(map[i] = (char *)malloc(sizeof(char) * (y + 2))))
			return(NULL);
		ft_memset(map[i],0, y + 2);
	}
	if(!(str = ft_strstr(str, "000")))
		return(NULL);
	if(!(tmp = ft_strsplit(ft_strsub(str, 0, (y + 5) * x), '\n')))
		return(NULL);
	i = -1;
	while(tmp[++i])
	{
		if(!(map[i] = ft_strsub(tmp[i], 4, ft_strlen(tmp[i]))))
			return(NULL);
		y = -1;
		while(map[i][++y] && bol == 0)
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
		}
	}
	bol = 1;
	return(map);
}

char **get_plat_piece(char *str, t_env *e, int *count)
{
	char **tmp;
	int i;
	int first;
	int segond;

	i = 6;
	count[0] = 0;
	str = ft_strstr(str, "Piece");
	first = ft_atoi(&str[6]);
	while(str[i] && ft_isdigit(str[i]))
		i++;
	segond = ft_atoi(&str[i]);
	i = 0;
	while(str[i] && str[i] != '.' && str[i] != '*')
		i++;
	str = ft_strsub(str, i, first * (segond + 1));
	tmp = ft_strsplit(str, '\n');
	i = -1;
	while(str[++i])
	{
		if(str[i] == '*')
			count[0]++;
	}
	count[0] = count[0] - 1;
	return(tmp);
}

int retest(t_env *e, int i ,int y, int *bol)
{
	int posx;
	int posy;

	if(e->tmp[i][y] == '*' && bol[0] < 1)
	{
		posx = i;
		posy = y;
		e->co_1erx = i;
		e->co_1ery = y;
		bol[0]++;
	}
	else if(e->tmp[i][y] == '*')
	{
		e->x[bol[0] - 1] = i - posx;
		e->y[bol[0] - 1] = y - posy;
		bol[0]++;
	}
	return(0);
}

int ft_get_piece(t_env *e, char *str)
{
	int i;
	int y;
	int bol;    //
	int count;

	bol = 0;
	e->tmp = get_plat_piece(str, e, &count);
	if(!(e->x = (int *)malloc(sizeof(int) * (count))))
		return(-1);
	if(!(e->y = (int *)malloc(sizeof(int) * (count))))
		return(-1);
	i = -1;
	while(e->tmp[++i] != NULL)
	{
		y = -1;
		while(e->tmp[i][++y] != 0)
			retest(e, i, y, &bol);
	}
	e->taille = count;
	e->sop_size = 0;
	e->bol = 0;
	ft_bzero(e->sopx, 255);
	ft_bzero(e->sopy, 255);
	return(0);
}

void ft_cible(char **tableau, t_env *e)
{
	int x;
	int y;
	static int bol = 1;

	y = 0;
	x = -1;
	while(bol == 0 && tableau[++x])
	{
		y = -1;
		while(tableau[x][++y] != 0)
		{
			if(e->joueur == 2 && tableau[x][y] == 'O' && e->befor[x][y] != tableau[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
			if(e->joueur == 1 && tableau[x][y] == 'X' && e->befor[x][y] != tableau[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
		}
	}
	bol = 0;
}

void ft_draw_red(t_env e, int i,int  j, char **plateau)
{
	int x;
	int y;
	int largeur;
	int grandeur;

	y = 1000 / (ft_strlen(plateau[0] + 2)); // taille case
	x = 1000 / (ft_strlen_tab(plateau) + 2);
	largeur = y * i;
	grandeur = x * j;
	while(largeur < y * (i + 1))
	{
		grandeur = x * j;
		while(grandeur < x * (j + 1))
		{
			mlx_pixel_put(e.mlx, e.win, grandeur, largeur, 0x00990000);
			grandeur++;
		}
		largeur++;
	}
}

void ft_draw_blue(t_env e, int  i,int  j, char **plateau)
{
	int x;
	int y;
	int largeur;
	int grandeur;

	y = 1000 / (ft_strlen(plateau[0] + 2)); // taille case
	x = 1000 / (ft_strlen_tab(plateau) + 2);
	largeur = y * i;
	grandeur = x * j;
	while(largeur < y * (i + 1))
	{
		grandeur = x * j;
		while(grandeur < x * (j + 1))
		{
			mlx_pixel_put(e.mlx, e.win, grandeur, largeur, 0x000000FF);
			grandeur++;
		}
		largeur++;
	}
}

void ft_draw_grille(t_env e, char **plateau ,int i, int j)
{
	int x;
	int y;
	int lx;
	int ly;
	int draw;

	y = 1000 / (ft_strlen(plateau[0] + 2)); // taille case
	x = 1000 / (ft_strlen_tab(plateau) + 2);
	lx = x;
	ly = y;
	while(lx < x * (ft_strlen(plateau[0]) + 1))
	{
		draw = -1;
		while(++draw < y * (ft_strlen_tab(plateau)))
			mlx_pixel_put(e.mlx, e.win, lx, draw, 0x00FFFFFF);
		lx = lx + x;
	}
	while(ly < y * (ft_strlen_tab(plateau) + 1))
	{
		draw = -1;
		while(++draw < x * (ft_strlen(plateau[0])))
			mlx_pixel_put(e.mlx, e.win, draw, ly, 0x00FFFFFF);
		ly = ly + y;
	}
}

void ft_affichage(t_env e, char **plateau)
{
	uintmax_t i;
	int j;

	i = -1;
	while(plateau[++i] != NULL)
	{
		j = -1;
		while(plateau[i][++j] != 0)
		{
			if(plateau[i][j] == 'X')
				ft_draw_blue(e, i, j, plateau);
			if(plateau[i][j] == 'O')
				ft_draw_red(e, i, j, plateau);
		}
	}
	ft_draw_grille(e, plateau, i - 1, j - 1);
}

int		key_pressed(int kc, t_env *e)
{
	int lol;

	lol = 0;
	if(kc == 36)
	{
		ft_putstr("5 5\n");
		while(e->plateau[lol])
		{
			ft_strdel(&e->plateau[lol]);
			lol++;
		}
		free(e->plateau);
		lol = 0;
		while(e->befor[lol])
		{
			ft_strdel(&e->befor[lol]);
			lol++;
		}
		free(e->befor);
		free(e->str);
		free(e->x);
		free(e->y);
		exit(0);
	}
	return(0);
}

int ft_delay(t_env *e)
{
	int lol;
	static int map = 3;

	e->plateau = NULL;
	ft_memset(e->str, 0, 16192);
	lol = 0;
	while(lol < (int)(110000000 * 2) && map == 3)
		lol++;
	while(lol < (int)(110000000 / 1.0f) && map == 2)
		lol++;
	while(lol < (int)(100000000 / 1.0f) && map == 1)
		lol++;
	if(read(0, e->str, 16191) == -1)
		return(0);
	if(!(e->plateau = ft_get_plateau(e->str, e)))
		return(0);
	ft_cible(e->plateau, e);
	if(ft_strlen(e->plateau[0]) <= 17 || ft_strlen_tab(e->plateau) <= 15)
		map = 1;
	else if(ft_strlen(e->plateau[0]) <= 40 || ft_strlen_tab(e->plateau) <= 24)
		map = 2;
	else
		map = 3;
	return(1);
}

int main(int argv, char **argc)
{
	t_env e;
	static int truc = 0;

	e.befor = NULL;
	if(!(e.str = (char *)malloc(sizeof(char) * 16192)))
		return(-1);
	while(1)
	{
		if((ft_delay(&e) == 0) || (ft_get_piece(&e, e.str) == -1))
			return(0);
		if(ft_check(e.plateau, &e) == 0)
		{
			if (!(e.mlx = mlx_init()))
				return(0);
			if (!(e.win = mlx_new_window(e.mlx, 1000, 1000, "filler")))
				return(0);
			if(truc == 0)
				ft_affichage(e, e.plateau);
			truc = 1;
			mlx_hook(e.win, 2, 1L << 0, &key_pressed, &e);
			mlx_loop(e.mlx);
		}
		e.befor = e.plateau;
	}
	return(0);
}
