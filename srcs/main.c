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

int		ft_start_draw(t_env *e, int *truc)
{
	int i;

	if (((i = ft_delay(e)) == 0) || (ft_get_piece(e, e->str) == -1))
	{
		ft_putstr("5 5\n");
		red_cross(e);
		(void)truc;
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
			red_cross(&e);
		}
		ft_copytab(&e);
	}
	return (0);
}
