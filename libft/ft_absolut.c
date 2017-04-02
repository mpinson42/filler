/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:46:23 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/10 22:32:37 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_absolut(int i)
{
	if (i < 0)
	{
		i = -i;
		return (i);
	}
	return (i);
}
