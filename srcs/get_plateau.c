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
		e->joueur = ft_atoi(ft_strsub(str, 10, 1));
	str = ft_strstr(str, "Plateau ");
	x[0] = ft_atoi(&str[8]);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	y[0] = ft_atoi(&str[i]);
//	if(e->map2)
//	{	i = 0;
//		while(e->map2[i + 1])
//		{
//			free(e->map2[i]);
//			i++;
//		}
//		free(e->map2);
//	}
	if (!(e->map2 = (char **)malloc(sizeof(char *) * (x[0] + 1))))
		return (-1);
	i = -1;
//	while (++i < x[0] + 1)
//		e->map2[i] = ft_strdup("");
	i = -1;
	while (++i < x[0] + 1)
	{
	//	write(e->fd, "non\n", 4);
//		if(e->map2[i])
//			free(e->map2[i]);
		if (!(e->map2[i] = (char *)malloc(sizeof(char) * (y[0] + 2))))
			return (-1);
		ft_memset(e->map2[i], 0, y[0] + 2);
	}
	e->map2[i] = NULL;
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

char	**ft_get_plateau(char *str, t_env *e)
{
	int			y;
	int			x;
	int			i;
	static int	bol = 0;

	if (ft_plat_plat(e, str, &y, &x) == -1)
		return (NULL);
	str = ft_strstr(str, "000");
	e->tmp2 = ft_strsplit(ft_strsub(str, 0, (y + 5) * x), '\n');
	i = -1;
	while (e->tmp2[++i])
	{
		e->map2[i] = ft_strsub(e->tmp2[i], 4, ft_strlen(e->tmp2[i]));
		y = -1;
		while (e->map2[i][++y] && bol == 0)
			ft_assigne_plat(e, i, y);
	}
	bol = 1;
	return (e->map2);
}
