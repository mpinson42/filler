/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:30:10 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/17 14:49:35 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char **ft_bnull(char **s, size_t n)
{
	size_t			b;

	b = 0;
	while (b < n)
	{
		s[b] = NULL;
		b++;
	}
	return (s);
}

char	**get_plat_piece(char *str, int *count)
{
	char	**tmp;
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
	str = ft_strsub(str, i, first * (segond + 1));
	tmp = ft_strsplit(str, '\n');
	i = -1;
	while (str[++i])
	{
		if (str[i] == '*')
			count[0]++;
	}
	count[0] = count[0] - 1;
	return (tmp);
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
	e->tmp = get_plat_piece(str, &count);
	ft_bzero(e->x, 10000);
	ft_bzero(e->y, 10000);
	i = -1;
	while (e->tmp[++i] != NULL)
	{
		ft_putstr_fd(e->tmp[i], e->fd);
		ft_putstr_fd("\n", e->fd);
		y = -1;
		while (e->tmp[i][++y] != 0)
			retest(e, i, y, &bol);
	}
	if(e->tmp)
	{	i = 0;
		while(e->tmp[i + 1])
		{
			free(e->tmp[i]);
			i++;
		}
		free(e->tmp);
	}
	//e->tmp[i] = NULL;
	e->taille = count;
	e->sop_size = 0;
	e->bol = 0;
	ft_bzero(e->sopx, 10000);
	ft_bzero(e->sopy, 10000);
	return (0);
}
