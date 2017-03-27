/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 11:39:05 by mpinson           #+#    #+#             */
/*   Updated: 2016/12/28 13:21:30 by mpinson          ###   ########.fr       */
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

char		*unsigned_itoa_base(uintmax_t n, int base)
{
	int		size;
	char	*str;

	if (n == 0)
	{
		str = (char*)malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		size = det_size(n, base);
		str = (char*)malloc((size + 2) * sizeof(char));
		ft_bzero(str, size + 2);
		ft_calcul_rec(n, base, str);
	}
	return (str);
}
