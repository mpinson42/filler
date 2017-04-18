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

static char	*other(int i, int n, int neg, int fd)
{
	char *str;

	if (neg == 0)
	{
		ft_putstr_fd("if\n", fd);
		if (!(str = (char *)malloc(sizeof(char) * i + 2)))
			return (NULL);
		str[0] = '-';
		str[i + 1] = '\0';
		while (i > 0)
		{
			str[i] = n % 10 + 48;
			n = n / 10;
			i--;
		}
		ft_putstr_fd("if fin\n", fd);
	}
	else
	{
		ft_putstr_fd("else\n", fd);
		if (!(str = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		ft_putstr_fd("else-\n", fd);
		str[i] = '\0';
		ft_putstr_fd("else--\n", fd);
		while (i >= 0)
		{
			str[i-- - 1] = n % 10 + 48;
			n = n / 10;
		}
		ft_putstr_fd("else fin\n", fd);
	}
	return (str);
}

char		*ft_itoa_fd(int m , int fd)
{
	int		i;
	int		len;
	int		neg;
	int n;

	n = m;
	neg = 1;
	len = n;
	i = 0;
	if (n < 0)
	{
		neg = 0;
		n = -n;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (len != 0)
	{
		len = len / 10;
		i++;
	}
	ft_putstr_fd("non mais lol-oui\n", fd);
	return (other(i, n, neg, fd));
}
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

int	ft_check(char **plateau, t_env *e)
{
	int		x;
	int		y;
	char	*str;
	char	*str2;
	int test;

	test = 0;
	x = -1;
	write(e->fd, "nosegfault--befor\n", 18);
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
	write(e->fd, "nosegfault--befor-befor\n", 24);
	if (e->sop_size <= 0 || (e->sopx[0] <= 0 && e->sopy[0] <= 0))
		return (0);
	write(e->fd, "nosegfault--befor-befor-befor\n", 30);
	y = ft_sop_chr(e);

	write(e->fd, "il est la\n", 10);
//	write(e->fd, ft_itoa(y), ft_strlen(ft_itoa(y)));
//	write(e->fd, "\n", 1);
	write(e->fd, ft_itoa(y), 5);
	write(e->fd, "\n", 1);
	test = e->sopx[y] - e->co_1erx;
	write(e->fd, "il est la-\n", 11);


	str = ft_strjoin(ft_itoa_base(e->sopx[y] - e->co_1erx, 10), " ");
	write(e->fd, "il est la2\n", 11);
	str2 = ft_strjoin(ft_itoa_base(e->sopy[y] - e->co_1ery, 10), "\n");
	write(e->fd, "il est la3\n", 11);
	ft_putstr(ft_strjoin(str, str2));
	write(e->fd, "il est la4\n", 11);
	return (1);
}
