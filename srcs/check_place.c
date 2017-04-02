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
	if (x + e->x[i] > (int)ft_strlen_tab(e->plateau) - 1 || x + e->x[i] < 0 ||
			y + e->y[i] > (int)ft_strlen(e->plateau[x]) || y + e->y[i] < 0 ||
			(e->plateau[x + e->x[i]][y + e->y[i]] != '.' &&
				e->plateau[x + e->x[i]][y + e->y[i]] != 'X' &&
				e->plateau[x + e->x[i]][y + e->y[i]] != 'x') ||
			(e->plateau[x][y] != '.' && e->plateau[x][y] != 'X'
				&& e->plateau[x][y] != 'x'))
		return (-1);
	return (0);
}

int	ft_check_placex(char **plateau, t_env *e, int x, int y)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (plateau[x][y] == 'X' || plateau[x][y] == 'X')
		count++;
	while (++i < e->taille)
	{
		if (ft_fat_conditionx(e, i, x, y) == -1)
			return (-1);
		if (plateau[e->x[i] + x][y + e->y[i]] == 'x' ||
				plateau[e->x[i] + x][y + e->y[i]] == 'X')
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
	if (x + e->x[i] > (int)ft_strlen_tab(e->plateau) - 1 || x + e->x[i] < 0 ||
		y + e->y[i] > (int)ft_strlen(e->plateau[x]) || y + e->y[i] < 0 ||
		(e->plateau[x + e->x[i]][y + e->y[i]] != '.' &&
			e->plateau[x + e->x[i]][y + e->y[i]] != 'O' &&
			e->plateau[x + e->x[i]][y + e->y[i]] != 'o') ||
		(e->plateau[x][y] != '.' && e->plateau[x][y] != 'O' &&
			e->plateau[x][y] != 'O'))
		return (-1);
	return (0);
}

int	ft_check_placeo(char **plateau, t_env *e, int x, int y)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (plateau[x][y] == 'O' || plateau[x][y] == 'O')
		count++;
	while (++i < e->taille)
	{
		if (ft_fat_conditiono(e, i, x, y) == -1)
			return (-1);
		if (plateau[e->x[i] + x][y + e->y[i]] == 'o' ||
				plateau[e->x[i] + x][y + e->y[i]] == 'O')
			count++;
	}
	if (count != 1)
		return (-1);
	e->sopx[e->sop_size] = x;
	e->sopy[e->sop_size] = y;
	e->sop_size++;
	return (-1);
}
