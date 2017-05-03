/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:58:49 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/26 15:58:59 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_strsub_stack(t_env *e, int start, int leng, int pos)
{
	int i;

	i = 0;
	while (e->tmp2[pos] && i < leng)
	{
		e->map2[pos][i] = e->tmp2[pos][start];
		i++;
		start++;
	}
}

static void	intmax(t_env *e)
{
	e->chiffre1[0] = '-';
	e->chiffre1[1] = 2 + 48;
	e->chiffre1[2] = 1 + 48;
	e->chiffre1[3] = 4 + 48;
	e->chiffre1[4] = 7 + 48;
	e->chiffre1[5] = 4 + 48;
	e->chiffre1[6] = 8 + 48;
	e->chiffre1[7] = 3 + 48;
	e->chiffre1[8] = 6 + 48;
	e->chiffre1[9] = 4 + 48;
	e->chiffre1[10] = 8 + 48;
	e->chiffre1[11] = '\0';
}

static void	zero(t_env *e)
{
	e->chiffre1[0] = '0';
	e->chiffre1[1] = '\0';
}

static void	other(int i, size_t n, int neg, t_env *e)
{
	if (neg == 0)
	{
		e->chiffre1[0] = '-';
		e->chiffre1[i + 1] = '\0';
		while (i > 0)
		{
			e->chiffre1[i] = n % 10 + 48;
			n = n / 10;
			i--;
		}
	}
	else
	{
		e->chiffre1[i] = '\0';
		while (i >= 0)
		{
			e->chiffre1[i-- - 1] = n % 10 + 48;
			n = n / 10;
		}
	}
}

void		ft_itoa_stack(int n, t_env *e)
{
	int		i;
	int		len;
	int		neg;
	char	*str;

	neg = 1;
	len = n;
	i = 0;
	str = NULL;
	n < 0 ? neg = 0 : 0;
	n < 0 ? n = -n : 0;
	n == 0 ? zero(e) : 0;
	if (n == 0)
		return ;
	n == -2147483648 ? intmax(e) : 0;
	if (n == -2147483648)
		return ;
	while (len != 0)
	{
		len = len / 10;
		i++;
	}
	other(i, n, neg, e);
}
