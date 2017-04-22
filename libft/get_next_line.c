/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:57:51 by mpinson           #+#    #+#             */
/*   Updated: 2016/11/27 11:40:06 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_static(t_env2 *e, char **line)
{
	int i;

	i = 0;
	if (ft_strchr(e->str, '\n') != NULL)
	{
		while (e->str[i] && e->str[i] != '\n')
			i++;
		line[0] = ft_strjoin(line[0], ft_strsub(e->str, 0, i));
		e->str = ft_strsub(e->str, i + 1, BUFF_SIZE);
		return (1);
	}
	else
	{
		line[0] = ft_strjoin(line[0], e->str);
		ft_strdel(&e->str);
	}
	return (0);
}

t_env2	*ft_check_fd(t_env2 *e, int fd)
{
	int		bol;
	t_env2	*tmp2;

	bol = 0;
	while (e->presed)
		e = e->presed;
	while (e->next && fd != e->fd)
		e = e->next;
	if (fd == e->fd)
		return (e);
	else
	{
		tmp2 = (t_env2 *)malloc(sizeof(t_env2));
		tmp2->next = NULL;
		tmp2->presed = e;
		tmp2->str = NULL;
		tmp2->fd = fd;
		tmp2->bol = 0;
		e->next = tmp2;
		e = e->next;
	}
	return (e);
}

int		ft_suit(char **line, t_env2 *e, int fd)
{
	char	str[BUFF_SIZE + 1];
	int		test;
	int		i;

	i = 0;
	ft_bzero(str, BUFF_SIZE + 1);
	while ((test = read(fd, str, BUFF_SIZE)) > 0)
	{
		if (ft_strchr(str, '\n') != NULL)
		{
			while (str[i] != '\0' && str[i] != '\n')
				i++;
			line[0] = ft_strjoin(line[0], ft_strsub(str, 0, i));
			e->str = ft_strsub(str, i + 1, BUFF_SIZE);
			return (1);
		}
		else
			line[0] = ft_strjoin(line[0], str);
		ft_bzero(str, BUFF_SIZE + 1);
	}
	if (fd < 0 || test == -1)
		return (-1);
	return (0);
}

int		ft_fin(t_env2 *e, char **line)
{
	if (line[0][0] != 0 && e->bol == 0)
	{
		e->bol = 1;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_env2	*e = NULL;
	int				i;

	i = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!e || e->fd != fd)
	{
		if (!(e = (t_env2 *)malloc(sizeof(t_env2))))
			return (-1);
		e->next = NULL;
		e->presed = NULL;
		e->str = NULL;
		e->fd = fd;
		e->bol = 0;
	}
	line[0] = ft_strdup("");
	e = ft_check_fd(e, fd);
	if (e->str && ft_check_static(e, line) == 1)
		return (1);
	if ((i = ft_suit(line, e, fd)) != 0)
		return (i);
	return (ft_fin(e, line));
}
