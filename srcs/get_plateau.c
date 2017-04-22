/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plateau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:30:17 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/17 14:49:46 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_plat_plat(t_env *e, char *str, int *y, int *x)
{
	int			i;
	static int	bol = 0;

	i = 8;
	if (bol == 0)
		e->joueur = ft_atoi(&str[10]);
	str = ft_strstr(str, "Plateau ");
	x[0] = ft_atoi(&str[8]);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	y[0] = ft_atoi(&str[i]);
	i = -1;
	i = -1;
	while (++i < 200)
		ft_bzero(e->map2[i], y[0] + 2);
	e->leng_map = x[0] + 1;
	bol = 1;
	return (0);
}

void	ft_assigne_plat(t_env *e, int i, int y)
{
	if (e->map2[i][y] == 'X' && e->joueur == 1)
	{
		e->ciblex = i;
		e->cibley = y;
	}
	if (e->map2[i][y] == 'O' && e->joueur == 2)
	{
		e->ciblex = i;
		e->cibley = y;
	}
}

void	ft_strsub_stack(t_env *e, int start, int leng, int pos)
{
	int i;

	i = 0;
	while (e->tmp2[pos] && i < leng)
	{
		e->map2[pos][i] = e->tmp2[pos][start];
		i++;
		start++;
	}
}

void	ft_strsplit_stack(t_env *e, char *str, char c)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (str[i])
	{
		e->tmp2[x][y] = str[i];
		i++;
		y++;
		if (str[i] == c)
		{
			i++;
			y = 0;
			x++;
		}
	}
}

void	ft_strsub_stack3(char *str, int start, int leng, t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_bzero(e->test3, 20000);
	while (x < leng)
	{
		e->test3[x] = str[start];
		x++;
		start++;
	}
}

void	ft_get_plateau(char *str, t_env *e)
{
	int			y;
	int			x;
	int			i;
	static int	bol = 0;

	ft_plat_plat(e, str, &y, &x);
	str = ft_strstr(str, "000");
	ft_strsub_stack3(str, 0, (y + 5) * x, e);
	ft_strsplit_stack(e, e->test3, '\n');
	i = -1;
	while (e->tmp2[++i][0])
	{
		ft_strsub_stack(e, 4, ft_strlen(e->tmp2[i]), i);
		y = -1;
		while (e->map2[i][++y] && bol == 0)
			ft_assigne_plat(e, i, y);
	}
	bol = 1;
}
