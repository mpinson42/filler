/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:29:45 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/02 13:42:51 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_fat_conditionx(t_env *e, int i, int x, int y)
{
	if (x + e->x[i] > e->leng_map - 1 || x + e->x[i] < 0 ||
			y + e->y[i] > (int)ft_strlen(e->map2[x]) || y + e->y[i] < 0 ||
			(e->map2[x + e->x[i]][y + e->y[i]] != '.' &&
				e->map2[x + e->x[i]][y + e->y[i]] != 'X' &&
				e->map2[x + e->x[i]][y + e->y[i]] != 'x') ||
			(e->map2[x][y] != '.' && e->map2[x][y] != 'X'
				&& e->map2[x][y] != 'x'))
		return (-1);
	return (0);
}

int	ft_check_placex(char **plateau, t_env *e, int x, int y)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	(void)plateau;
	if (e->map2[x][y] == 'X' || e->map2[x][y] == 'X')
		count++;
	if (ft_fat_conditionx(e, 0, x, y) == -1)
			return (-1);
	while (++i < e->taille)
	{
		if (ft_fat_conditionx(e, i, x, y) == -1)
			return (-1);
		if (e->map2[e->x[i] + x][y + e->y[i]] == 'x' ||
				e->map2[e->x[i] + x][y + e->y[i]] == 'X')
			count++;
	}
	if (count != 1)
		return (-1);
	e->sopx[e->sop_size] = x;
	e->sopy[e->sop_size] = y;
	e->sop_size++;
	return (-1);
}

int	ft_fat_conditiono(t_env *e, int i, int x, int y)
{
	if (x + e->x[i] > e->leng_map - 1 || x + e->x[i] < 0 ||
		y + e->y[i] > (int)ft_strlen(e->map2[x]) || y + e->y[i] < 0 ||
		(e->map2[x + e->x[i]][y + e->y[i]] != '.' &&
			e->map2[x + e->x[i]][y + e->y[i]] != 'O' &&
			e->map2[x + e->x[i]][y + e->y[i]] != 'o') ||
		(e->map2[x][y] != '.' && e->map2[x][y] != 'O' &&
			e->map2[x][y] != 'O'))
		return (-1);
	return (0);
}

int	ft_check_placeo(char **plateau, t_env *e, int x, int y)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	(void)plateau;
	if (e->map2[x][y] == 'O' || e->map2[x][y] == 'O')
		count++;
	if (ft_fat_conditiono(e, 0, x, y) == -1)
			return (-1);
	while (++i < e->taille)
	{
		if (ft_fat_conditiono(e, i, x, y) == -1)
			return (-1);
		if (e->map2[e->x[i] + x][y + e->y[i]] == 'o' ||
				e->map2[e->x[i] + x][y + e->y[i]] == 'O')
			count++;
	}
	if (count != 1)
		return (-1);
	e->sopx[e->sop_size] = x;
	e->sopy[e->sop_size] = y;
	e->sop_size++;
	return (-1);
}
