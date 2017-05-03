/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:30:10 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/22 10:51:09 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_strsplit_stack2(t_env *e, char *str, char c)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (str[i] && i < 2000)
	{
		e->tmp[x][y] = str[i];
		i++;
		y++;
		if (str[i] == c)
		{
			e->tmp[x][y] = 0;
			i++;
			y = 0;
			x++;
		}
	}
	e->tmp[x][y] = 0;
}

void	ft_strsub_stack2(char *str, int start, int leng, t_env *e)
{
	int		i;
	char	str2[20000];

	i = 0;
	(void)e;
	ft_bzero(str2, 20000);
	while (str[i] && i < leng)
	{
		str2[i] = str[start];
		i++;
		start++;
	}
	ft_strcpy(str, str2);
}

void	get_plat_piece(char *str, int *count, t_env *e)
{
	int		i;
	int		first;
	int		segond;

	i = 6;
	count[0] = 0;
	str = ft_strstr(str, "Piece");
	first = ft_atoi(&str[6]);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	segond = ft_atoi(&str[i]);
	i = 0;
	while (str[i] && str[i] != '.' && str[i] != '*')
		i++;
	ft_strsub_stack2(str, i, first * (segond + 1), e);
	ft_strsplit_stack2(e, str, '\n');
	i = -1;
	while (str[++i])
	{
		if (str[i] == '*')
			count[0]++;
	}
	count[0] = count[0] - 1;
}

int		retest(t_env *e, int i, int y, int *bol)
{
	static int	posx = 0;
	static int	posy = 0;

	if (e->tmp[i][y] == '*' && bol[0] < 1)
	{
		posx = i;
		posy = y;
		e->co_1erx = i;
		e->co_1ery = y;
		bol[0]++;
	}
	else if (e->tmp[i][y] == '*')
	{
		e->x[bol[0] - 1] = i - posx;
		e->y[bol[0] - 1] = y - posy;
		bol[0]++;
	}
	return (0);
}

int		ft_get_piece(t_env *e, char *str)
{
	int	i;
	int	y;
	int	bol;
	int	count;

	bol = 0;
	get_plat_piece(str, &count, e);
	ft_bzero(e->x, 10000);
	ft_bzero(e->y, 10000);
	i = -1;
	while (e->tmp[++i][0])
	{
		y = -1;
		while (e->tmp[i][++y] != 0)
			retest(e, i, y, &bol);
	}
	e->taille = count;
	e->sop_size = 0;
	e->bol = 0;
	ft_bzero(e->sopx, 10000);
	ft_bzero(e->sopy, 10000);
	return (0);
}
