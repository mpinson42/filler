/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:54:22 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/01 23:00:02 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int ft_strlen_tab(char **tab)
{
	int i;

	i = 0;
	if(tab == NULL)
		return(0);
	while(tab[i] != NULL)
		i++;
	return(i);
}


int ft_fat_conditionX(t_env *e, int i, int x, int  y)
{
	if(x + e->x[i] > ft_strlen_tab(e->plateau) - 1 || x + e->x[i] < 0 ||
			y + e->y[i] > ft_strlen(e->plateau[x]) || y + e->y[i] < 0 ||
			(e->plateau[x + e->x[i]][y + e->y[i]] != '.' &&
			 e->plateau[x + e->x[i]][y + e->y[i]] != 'X' &&
			 e->plateau[x + e->x[i]][y + e->y[i]] != 'x')||
			(e->plateau[x][y] != '.' && e->plateau[x][y] != 'X'
				&& e->plateau[x][y] != 'x'))
		return(-1);
	return(0);
}

int ft_check_placeX(char **plateau, t_env *e, int x, int y)
{
	int count;
	int i;
	int *sop_tmpy;
	int *sop_tmpx;

	i = -1;
	count = 0;
	if(plateau[x][y] == 'X' || plateau[x][y] == 'X')
		count++;
	while(++i < e->taille)
	{
		if(ft_fat_conditionX(e, i, x, y) == -1)
			return(-1);
		if(plateau[e->x[i] + x][y + e->y[i]] == 'x' ||
				plateau[e->x[i] + x][y + e->y[i]] == 'X')
			count++;
	}
	if(count != 1)
		return(-1);
	e->sopx[e->sop_size] = x;
	e->sopy[e->sop_size] = y;
	e->sop_size++;
	return(-1);
}

int ft_fat_conditionO(t_env *e, int i, int x, int  y)
{
	if(x + e->x[i] > ft_strlen_tab(e->plateau) - 1|| x + e->x[i] < 0 ||
				y + e->y[i] > ft_strlen(e->plateau[x]) || y + e->y[i] < 0 ||
				(e->plateau[x + e->x[i]][y + e->y[i]] != '.' &&
				 e->plateau[x + e->x[i]][y + e->y[i]] != 'O' &&
				 e->plateau[x + e->x[i]][y + e->y[i]] != 'o') ||
				(e->plateau[x][y] != '.' && e->plateau[x][y] != 'O' &&
				 e->plateau[x][y] != 'O'))
		return(-1);
	return(0);
}

int ft_check_placeO(char **plateau, t_env *e, int x, int y)
{
	int count;
	int i;
	int *sop_tmpy;
	int *sop_tmpx;

	i = -1;
	count = 0;
	if(plateau[x][y] == 'O' || plateau[x][y] == 'O')
		count++;
	while(++i < e->taille)
	{
		if(ft_fat_conditionO(e, i, x, y) == -1)
			return(-1);
		if(plateau[e->x[i] + x][y + e->y[i]] == 'o' ||
				plateau[e->x[i] + x][y + e->y[i]] == 'O')
			count++;
	}
	if(count != 1)
		return(-1);
	e->sopx[e->sop_size] = x;
	e->sopy[e->sop_size] = y;
	e->sop_size++;
	return(-1);
}

int ft_sop_chr(t_env *e)
{
	int i;
	int ciblex;
	int cibley;
	int save;
	int save2;

	i = -1;
	save = 999999999;
	save2 = 0;
	while(++i < e->sop_size)
	{
		ciblex = ft_absolut(e->ciblex - e->sopx[i]);
		cibley = ft_absolut(e->cibley - e->sopy[i]);
		ciblex = ciblex + cibley;
		if(ciblex < save)
		{
			save = ciblex;
			save2 = i;
		}
	}
	return(save2);
}

int ft_check(char **plateau, t_env *e)
{
	int x;
	int y;
	int j;
	char *str;
	char *str2;

	x = -1;
	while(plateau[++x])
	{
		y = -1;
		while(plateau[x][++y] != 0)
		{
			if(e->joueur == 2 && ft_check_placeX(plateau, e, x, y) == 0)
				return(1);
			if(e->joueur == 1 && ft_check_placeO(plateau, e, x, y) == 0)
				return(1);
		}
	}
	if(e->sopx[0] == 0 && e->sopy[0] == 0)
		return(0);
	y = ft_sop_chr(e);
	str = ft_strjoin(ft_itoa(e->sopx[y] - e->co_1erx), " ");
	str2 = ft_strjoin(ft_itoa(e->sopy[y] - e->co_1ery), "\n");
	ft_putstr(ft_strjoin(str, str2));
	return(1);
}
