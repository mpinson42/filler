/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:54:09 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/22 11:01:38 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

void	ft_cible(t_env *e)
{
	int			x;
	int			y;
	static int	bol = 1;

	x = -1;
	while (bol == 0 && ++x < e->leng_map)
	{
		y = -1;
		while (++y < 99 && e->map2[x][y] != 0)
		{
			if (e->joueur == 2 && e->map2[x][y] == 'O' &&
					e->befor[x][y] != e->map2[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
			if (e->joueur == 1 && e->map2[x][y] == 'X' &&
					e->befor[x][y] != e->map2[x][y])
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
	(void)e;
	if (kc == 36)
		ft_putstr("5 5\n");
	return (0);
}

int		red_cross(t_env *e)
{
	int lol;

	lol = 0;
	(void)e;
	ft_putstr("5 5\n");
	return (0);
}

void	ft_join(char *str, t_env *e)
{
	int i;

	i = 0;
	while (str[i])
	{
		e->str[e->count] = str[i];
		i++;
		e->count++;
	}
}

int		ft_read(t_env *e)
{
	char	c[1];
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	ft_bzero(e->test3, 500);
	while ((ret = read(0, &c, 1) >= 0))
	{
		if (ret == -1)
			return (-1);
		e->test3[i] = c[0];
		i++;
		if (i >= 500 || c[0] == '\n')
			return (1);
		if (c[0] == 0)
			return (-1);
	}
	return (-1);
}

int		ft_lecteur(t_env *e, int *lol)
{
	int i;

	while ((lol[0] = ft_read(e)) >= 1)
	{
		if (lol[0] == -1)
			return (0);
		if (ft_strncmp("Piece", e->test3, 5) == 0)
		{
			ft_join(e->test3, e);
			i = ft_atoi(e->test3 + 5);
			while (i)
			{
				if (ft_read(e) == -1)
					return (0);
				ft_join(e->test3, e);
				i--;
			}
			break ;
		}
		ft_join(e->test3, e);
	}
	return (1);
}

int		ft_delay(t_env *e)
{
	int	lol;

	e->nb_map = 0;
	ft_bzero(e->str, 20000);
	lol = 0;
	if (ft_lecteur(e, &lol) == 0)
		return (0);
	if (lol == -1 || e->str[0] == 0)
		return (0);
	if (lol == -1)
		return (0);
	ft_get_plateau(e->str, e);
	if (ft_strlen(e->map2[0]) <= 17 || e->leng_map <= 15)
		e->nb_map = 1;
	ft_cible(e);
	return (1);
}

int		checkx(char **tableau, t_env *e)
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
				return (0);
			if (e->joueur == 1 && tableau[x][y] == 'X' &&
					e->befor[x][y] != tableau[x][y])
				return (0);
		}
	}
	bol = 0;
	return (1);
}

void	ft_copytab(t_env *e)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (e->map2[i][0] && i < e->leng_map)
	{
		y = 0;
		ft_bzero(e->befor[i], 200);
		while (e->map2[i][y])
		{
			e->befor[i][y] = e->map2[i][y];
			y++;
		}
		i++;
	}
}

int		ft_start_draw(t_env *e, int *truc)
{
	int i;

	if (((i = ft_delay(e)) == 0) || (ft_get_piece(e, e->str) == -1))
	{
		if (!(e->mlx = mlx_init()))
			return (0);
		if (!(e->win = mlx_new_window(e->mlx, 2560, 1440, "filler")))
			return (0);
		truc == 0 ? ft_affichage(e[0], truc) : 0;
		mlx_hook(e->win, 2, 1L << 0, &key_pressed, &e);
		mlx_hook(e->win, 17, (1L << 17), &red_cross, &e);
		mlx_loop(e->mlx);
	}
	return (1);
}

int		main(void)
{
	t_env		e;
	static int	truc = 0;

	ft_memset(e.str, 0, 20000);
	while (1)
	{
		e.count = 0;
		if (ft_start_draw(&e, &truc) == 0)
			return (0);
		if (ft_check(&e) == 0)
		{
			ft_putstr("5 5\n");
			if (!(e.mlx = mlx_init()))
				return (0);
			if (!(e.win = mlx_new_window(e.mlx, 2560, 1440, "filler")))
				return (0);
			truc == 0 ? ft_affichage(e, &truc) : 0;
			mlx_hook(e.win, 2, 1L << 0, &key_pressed, &e);
			mlx_hook(e.win, 17, (1L << 17), &red_cross, &e);
			mlx_loop(e.mlx);
		}
		ft_copytab(&e);
	}
	return (0);
}
