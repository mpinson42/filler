/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:40:19 by mpinson           #+#    #+#             */
/*   Updated: 2016/12/28 13:27:46 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	det_size(uintmax_t n, int base)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

static void	ft_calcul_rec(uintmax_t n, int base, char *str)
{
	if (n != 0)
	{
		ft_calcul_rec(n / base, base, str);
		while (*str)
			str++;
		if (n % base < 10)
			*str = (n % base) + '0';
		else
			*str = (n % base) - 10 + 'a';
	}
}

char		*ft_itoa_base(intmax_t n, int base)
{
	uintmax_t	val;
	int			size;
	int			neg;
	char		*str;

	neg = 0;
	if (n < 0)
	{
		val = n * (-1);
		neg = 1;
	}
	else
		val = n;
	size = det_size(val, base);
	str = (char*)malloc((size + 2) * sizeof(char));
	ft_bzero(str, size + 2);
	if (n == 0)
		ft_strcpy(str, "0");
	if (neg == 1)
		str[0] = '-';
	ft_calcul_rec(val, base, str + neg);
	return (str);
}
