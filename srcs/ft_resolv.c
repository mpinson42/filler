/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:54:22 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/22 10:44:32 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int			ft_sop_chr(t_env *e)
{
	int	i;
	int	ciblex;
	int	cibley;
	int	save;
	int	save2;

	i = -1;
	save = 99999;
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

void		ft_join_str(t_env *e)
{
	char	rendu[50];
	int		i;
	int		j;

	j = 0;
	i = 0;
	ft_bzero(rendu, 50);
	while (e->chiffre2[i])
	{
		rendu[i] = e->chiffre2[i];
		i++;
	}
	rendu[i] = ' ';
	i++;
	while (e->chiffre1[j])
	{
		rendu[i] = e->chiffre1[j];
		j++;
		i++;
	}
	rendu[i] = '\n';
	ft_putstr(rendu);
}

void		ft_last_cpy(t_env *e)
{
	int i;

	i = 0;
	while (e->chiffre1[i])
	{
		e->chiffre2[i] = e->chiffre1[i];
		i++;
	}
	e->chiffre2[i] = 0;
}

int			ft_check(t_env *e)
{
	int	x;
	int	y;
	int test;

	test = 0;
	x = -1;
	while (e->map2[++x][0])
	{
		y = -1;
		while (e->map2[x][++y] != 0)
			if ((e->joueur == 2 && ft_check_placex(e, x, y) == 0)
				|| (e->joueur == 1 && ft_check_placeo(e, x, y) == 0))
				return (1);
	}
	if (e->sop_size <= 0 || (e->sopx[0] <= 0 && e->sopy[0] <= 0))
		return (0);
	y = ft_sop_chr(e);
	test = e->sopx[y] - e->co_1erx;
	ft_itoa_stack(e->sopx[y] - e->co_1erx, e);
	ft_last_cpy(e);
	ft_itoa_stack(e->sopy[y] - e->co_1ery, e);
	ft_join_str(e);
	return (1);
}
