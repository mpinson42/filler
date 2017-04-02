/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:54:22 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/02 13:30:04 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_sop_chr(t_env *e)
{
	int	i;
	int	ciblex;
	int	cibley;
	int	save;
	int	save2;

	i = -1;
	save = 999999999;
	save2 = 0;
	while (++i < e->sop_size)
	{
		ciblex = ft_absolut(e->ciblex - e->sopx[i]);
		cibley = ft_absolut(e->cibley - e->sopy[i]);
		ciblex = ciblex + cibley;
		if (ciblex < save)
		{
			save = ciblex;
			save2 = i;
		}
	}
	return (save2);
}

int	ft_check(char **plateau, t_env *e)
{
	int		x;
	int		y;
	char	*str;
	char	*str2;

	x = -1;
	while (plateau[++x])
	{
		y = -1;
		while (plateau[x][++y] != 0)
		{
			if (e->joueur == 2 && ft_check_placex(plateau, e, x, y) == 0)
				return (1);
			if (e->joueur == 1 && ft_check_placeo(plateau, e, x, y) == 0)
				return (1);
		}
	}
	if (e->sopx[0] == 0 && e->sopy[0] == 0)
		return (0);
	y = ft_sop_chr(e);
	str = ft_strjoin(ft_itoa(e->sopx[y] - e->co_1erx), " ");
	str2 = ft_strjoin(ft_itoa(e->sopy[y] - e->co_1ery), "\n");
	ft_putstr(ft_strjoin(str, str2));
	return (1);
}
