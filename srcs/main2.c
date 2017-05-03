/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:59:08 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/26 15:59:16 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
