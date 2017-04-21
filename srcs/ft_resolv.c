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
//************************************************************************************//

 //************************************************************************************
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

void ft_join_str(char *str1, char *str2)
{
	char rendu[50];
	int i;
	int j;

	j = 0;
	i = 0;
	ft_bzero(rendu, 50);
	while(str1[i])
	{
		rendu[i] = str1[i];
		i++;
	}
	rendu[i] = ' ';
	i++;
	while(str2[j])
	{
		rendu[i] = str2[j];
		j++;
		i++;
	}
	rendu[i] = '\n';
	free(str1);
	free(str2);
	ft_putstr(rendu);
}

int	ft_check(char **plateau, t_env *e)
{
	int		x;
	int		y;
//	char	*str;
//	char	*str2;
	int test;

	test = 0;
	x = -1;
	write(e->fd, "nosegfault--befor\n", 18);
	while (e->map2[++x][0])
	{
		y = -1;
		while (e->map2[x][++y] != 0)
		{
			if (e->joueur == 2 && ft_check_placex(plateau, e, x, y) == 0)
				return (1);
			if (e->joueur == 1 && ft_check_placeo(plateau, e, x, y) == 0)
				return (1);
		}
	}
	write(e->fd, "nosegfault--befor-befor\n", 24);
	if (e->sop_size <= 0 || (e->sopx[0] <= 0 && e->sopy[0] <= 0))
		return (0);
	write(e->fd, "nosegfault--befor-befor-befor\n", 30);
	y = ft_sop_chr(e);

	write(e->fd, "il est la\n", 10);
//	write(e->fd, ft_itoa(y), ft_strlen(ft_itoa(y)));
//	write(e->fd, "\n", 1);
//	write(e->fd, ft_itoa(y), 5);
	write(e->fd, "\n", 1);
	test = e->sopx[y] - e->co_1erx;
	write(e->fd, "il est la-\n", 11);


	ft_join_str(ft_itoa(e->sopx[y] - e->co_1erx), ft_itoa(e->sopy[y] - e->co_1ery));
//while(1)
//		;
/*	str = ft_strjoin(ft_itoa_base(e->sopx[y] - e->co_1erx, 10), " ");
	write(e->fd, "il est la2\n", 11);
	str2 = ft_strjoin(ft_itoa_base(e->sopy[y] - e->co_1ery, 10), "\n");
	write(e->fd, "il est la3\n", 11);
	ft_putstr(ft_strjoin(str, str2));
	write(e->fd, "il est la4\n", 11);*/
	return (1);
}
