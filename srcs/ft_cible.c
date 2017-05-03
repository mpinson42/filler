/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cible.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:02:53 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/26 16:02:57 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
