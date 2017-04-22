/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:29:54 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/22 10:42:45 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_draw_red(t_env e, int i, int j)
{
	int	x;
	int	y;
	int	largeur;
	int	grandeur;

	y = 1000 / (ft_strlen(e.map2[0] + 2));
	x = 1000 / (e.leng_map + 2);
	largeur = y * i;
	grandeur = x * j;
	while (largeur < y * (i + 1))
	{
		grandeur = x * j;
		while (grandeur < x * (j + 1))
		{
			mlx_pixel_put(e.mlx, e.win, grandeur, largeur, 0x00990000);
			grandeur++;
		}
		largeur++;
	}
}

void	ft_draw_blue(t_env e, int i, int j)
{
	int x;
	int y;
	int largeur;
	int grandeur;

	y = 1000 / (ft_strlen(e.map2[0] + 2));
	x = 1000 / (e.leng_map + 2);
	largeur = y * i;
	grandeur = x * j;
	while (largeur < y * (i + 1))
	{
		grandeur = x * j;
		while (grandeur < x * (j + 1))
		{
			mlx_pixel_put(e.mlx, e.win, grandeur, largeur, 0x000000FF);
			grandeur++;
		}
		largeur++;
	}
}

void	ft_draw_grille(t_env e)
{
	int	x;
	int	y;
	int	lx;
	int	ly;
	int	draw;

	y = 1000 / ((int)ft_strlen(e.map2[0] + 2));
	x = 1000 / (e.leng_map + 2);
	lx = x;
	ly = y;
	while (lx < x * ((int)ft_strlen(e.map2[0]) + 1))
	{
		draw = -1;
		while (++draw < y * e.leng_map)
			mlx_pixel_put(e.mlx, e.win, lx, draw, 0x00FFFFFF);
		lx = lx + x;
	}
	while (ly < y * (e.leng_map + 1))
	{
		draw = -1;
		while (++draw < x * ((int)ft_strlen(e.map2[0])))
			mlx_pixel_put(e.mlx, e.win, draw, ly, 0x00FFFFFF);
		ly = ly + y;
	}
}

void	ft_affichage(t_env e, int *truc)
{
	uintmax_t	i;
	int			j;

	i = -1;
	while (++i < (uintmax_t)e.leng_map)
	{
		j = -1;
		while (e.map2[i][++j] != 0)
		{
			if (e.map2[i][j] == 'X')
				ft_draw_blue(e, i, j);
			if (e.map2[i][j] == 'O')
				ft_draw_red(e, i, j);
		}
	}
	ft_draw_grille(e);
	truc[0] = 0;
}
