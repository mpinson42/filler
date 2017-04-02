/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:54:09 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/02 13:30:24 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

void	ft_cible(char **tableau, t_env *e)
{
	int			x;
	int			y;
	static int	bol = 1;

	x = -1;
	while (bol == 0 && tableau[++x])
	{
		y = -1;
		while (tableau[x][++y] != 0)
		{
			if (e->joueur == 2 && tableau[x][y] == 'O' &&
				e->befor[x][y] != tableau[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
			if (e->joueur == 1 && tableau[x][y] == 'X' &&
				e->befor[x][y] != tableau[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
		}
	}
	bol = 0;
}

int		key_pressed(int kc, t_env *e)
{
	int lol;

	lol = 0;
	if (kc == 36)
	{
		while (e->plateau[lol])
		{
			ft_strdel(&e->plateau[lol]);
			lol++;
		}
		free(e->plateau);
		lol = 0;
		while (e->befor[lol])
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
	return (0);
}

int		ft_delay(t_env *e)
{
	int			lol;
	static int	map = 3;

	e->plateau = NULL;
	ft_memset(e->str, 0, 16192);
	lol = 0;
	while (lol < (int)(110000000 * 2) && map == 3)
		lol++;
	while (lol < (int)(110000000 / 1.0f) && map == 2)
		lol++;
	while (lol < (int)(100000000 / 1.0f) && map == 1)
		lol++;
	if (read(0, e->str, 16191) == -1)
		return (0);
	if (!(e->plateau = ft_get_plateau(e->str, e)))
		return (0);
	ft_cible(e->plateau, e);
	if (ft_strlen(e->plateau[0]) <= 17 || ft_strlen_tab(e->plateau) <= 15)
		map = 1;
	else if (ft_strlen(e->plateau[0]) <= 40 || ft_strlen_tab(e->plateau) <= 24)
		map = 2;
	else
		map = 3;
	return (1);
}

int		main(void)
{
	t_env		e;
	static int	truc = 0;

	e.befor = NULL;
	if (!(e.str = (char *)malloc(sizeof(char) * 16192)))
		return (-1);
	while (1)
	{
		if ((ft_delay(&e) == 0) || (ft_get_piece(&e, e.str) == -1))
			return (0);
		if (ft_check(e.plateau, &e) == 0)
		{
			ft_putstr("5 5\n");
			if (!(e.mlx = mlx_init()))
				return (0);
			if (!(e.win = mlx_new_window(e.mlx, 1000, 1000, "filler")))
				return (0);
			if (truc == 0)
				ft_affichage(e, e.plateau, &truc);
			mlx_hook(e.win, 2, 1L << 0, &key_pressed, &e);
			mlx_loop(e.mlx);
		}
		e.befor = e.plateau;
	}
	return (0);
}
