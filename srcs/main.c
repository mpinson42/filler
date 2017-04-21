/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:54:09 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/02 13:30:24 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

void	ft_cible(char **tableau, t_env *e)
{
	int			x;
	int			y;
	static int	bol = 1;

	x = 0;
	(void)tableau;
	while (bol == 0 && x < e->leng_map && e->nb_map != 1)
	{
/*			ft_putstr_fd("c est ici -->", e->fd);
			int w = ft_strlen_tab(e->befor);
			ft_putstr_fd(ft_itoa(w), e->fd);
			ft_putstr_fd("\n", e->fd);
			(void)w;*/
		y = 0;
		while (y < 99 && e->map2[x][y] != 0)
		{
			if (e->joueur == 2 && e->map2[x][y] == 'O' &&
				e->befor[x][y] != e->map2[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
			if (e->joueur == 1 && e->map2[x][y] == 'X' &&
				e->befor[x][y] != e->map2[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
			y++;
		}
		x++;
	}
	if(e->nb_map == 1)
	{
		e->ciblex = 8;
		e->cibley = 8;
	}
	bol = 0;
}

int		key_pressed(int kc, t_env *e)
{
	int lol;

	lol = 0;
	if (kc == 36)
	{
		ft_putstr_fd("coucou\n", e->fd);
		while (e->plateau && e->plateau[lol])
		{
			ft_strdel(&e->plateau[lol]);
			lol++;
		}
		free(e->plateau);
//		lol = 0;
//		while (e->befor[lol])
//		{
//			ft_strdel(&e->befor[lol]);
//			lol++;
//		}
//		free(e->befor);
//		free(e->str);
		while(1)
			;
		ft_putstr("5 5\n");
	}
	return (0);
}

int red_cross(t_env *e)
{
	int lol;

	lol = 0;
	while (e->plateau[lol])
	{
		ft_strdel(&e->plateau[lol]);
		lol++;
	}
	free(e->plateau);
//	lol = 0;
//	while (e->befor[lol])
//	{
//		ft_strdel(&e->befor[lol]);
//		lol++;
//	}
//	free(e->befor);
	free(e->str);
	ft_putstr("5 5\n");
	return(0);
}

void ft_join(char *str, t_env *e)
{
	int i;

	i = 0;
	while(str[i])
	{
		e->str[e->count] = str[i];
		i++;
		e->count++;
	}
}

int ft_read(t_env *e)
{
	char c[1];
	int ret;
	int i;

	ret = 0;
	i = 0;
	ft_bzero(e->test3, 500);
	while((ret = read(0, &c, 1) >= 0))
	{
		if(ret == -1)
			return(-1);
//		ft_putstr_fd("lalalalala\n", e->fd);
		e->test3[i] = c[0];
		i++;
		if(i >= 500 || c[0] == '\n')
			return(1);
		if(c[0] == 0)
			return(-1);
	}
	return(-1);
}

int		ft_delay(t_env *e)
{
	int			lol;
//	char *tmp;
	int i;
//	static int	map = 3;
	e->nb_map = 0;
	e->plateau = NULL;
	ft_bzero(e->str, 20000);
	lol = 0;
/*	while (lol < (int)(110000000 * 0.8) && map == 3)
		lol++;
	while (lol < (int)(110000000 / 1.0f) && map == 2)
		lol++;
	while (lol < (int)(100000000 * 0.257) && map == 1)
		lol++;*/
//	if (read(0, e->str, 161910) == -1)
//		return (0);
//	e->save = e->plateau;
	write(e->fd, "il est la7\n", 11);
	while((lol = ft_read(e)) >= 1)
	{
		if(lol == -1)
			return(0);
//		write(e->fd, "il est la8\n", 11);
//		ft_bzero(e->test2, 500);
//		ft_strcpy(e->test2, tmp);
//		ft_putstr_fd("1et gnl\n" ,e->fd);
		if(ft_strncmp("Piece", e->test3, 5) == 0)
		{
//			e->test2[ft_strlen(e->test2)] = '\n';
			ft_join(e->test3, e);
			i = ft_atoi(e->test3 + 5);
//			ft_putstr_fd(e->test2 + 5, e->fd);
//			write(fd, ft_itoa(i), ft_strlen(ft_itoa(i)));
			while(i)
			{
				ft_putstr_fd("2et gnl\n" ,e->fd);
				if(ft_read(e) == -1)
					return(0);
		//		ft_bzero(e->test2, 500);
		//		ft_strcpy(e->test2, tmp);
		//		e->test2[ft_strlen(e->test2)] = '\n';
				ft_join(e->test3, e);
			//	ft_putstr_fd(e->str, fd);
				i--;
			}
			break;
		}
//		e->test2[ft_strlen(e->test2)] = '\n';
		ft_join(e->test3, e);
	}
	if(lol == -1 || e->str[0] == 0)
		return(0);
	write(e->fd, e->str, ft_strlen(e->str));
	write(e->fd, "--->", 4);
	write(e->fd, &e->str[0], 3);
	write(e->fd, "\nil est la8\n", 12);
	write(e->fd, e->str, ft_strlen(e->str));
	write(e->fd, "il est la9\n", 11);
	write(e->fd, "\n\n\n", 6);
	if (lol == -1 )
		return (0);
	ft_get_plateau(e->str, e);
	write(e->fd, "il est la10\n", 12);
	if (ft_strlen(e->map2[0]) <= 17 || e->leng_map <= 15)
		e->nb_map = 1;
	write(e->fd, "il est la11\n", 12);
	ft_cible(e->plateau, e);
	write(e->fd, "il est la12\n", 12);
	return (1);
}

int	checkx(char **tableau, t_env *e)
{
	int			x;
	int			y;
	static int	bol = 1;

	x = -1;
	while (bol == 0 && tableau[++x])
	{
		y = -1;
		while (tableau[x][++y] != 0)
		{
			if (e->joueur == 2 && tableau[x][y] == 'O' &&
				e->befor[x][y] != tableau[x][y])
			{
				return(0);
			}
			if (e->joueur == 1 && tableau[x][y] == 'X' &&
				e->befor[x][y] != tableau[x][y])
			{
				return(0);
			}
		}
	}
	bol = 0;
	return(1);
}

void ft_copytab(t_env *e, char **tab2)
{
	int i;
	int y;

	i = 0;
	y = 0;
	(void)tab2;
	while(e->map2[i][0] && i < e->leng_map)
	{
		y = 0;
		ft_bzero(e->befor[i], 200);
		while(e->map2[i][y])
		{
			e->befor[i][y] = e->map2[i][y];
			y++;
		}
		i++;
	}
}

int		main(void)
{
	t_env		e;
	int i;
	static int	truc = 0;

//	e.befor = NULL;
//	e.map2 = NULL;
	system("rm test");
	system("touch test");
	e.fd = open("./test", O_RDWR);
//	e.sopx[10048] = 255;
//	e.sopy[10048] = 255;
	ft_memset(e.str, 0, 20000);
//	if (!(e.str = (char *)malloc(sizeof(char) * 20000)))
//		return (-1);
	while (1)
	{
		i = 0;
		e.count = 0;
		if ((( i = ft_delay(&e)) == 0) || (ft_get_piece(&e, e.str) == -1))
		{
			write(e.fd, "no segfault !\n", 14);
		//	ft_putstr("5 5\n");
		//	exit(0);
			if (!(e.mlx = mlx_init()))
				return (0);
			if (!(e.win = mlx_new_window(e.mlx, 2560, 1440, "filler")))
				return (0);
			write(e.fd, "no segfault ?\n", 14);
			truc == 0 ? ft_affichage(e, e.befor2, &truc) : 0;
			mlx_hook(e.win, 2, 1L << 0, &key_pressed, &e);
			mlx_hook(e.win, 17, (1L << 17), &red_cross, &e);
			mlx_loop(e.mlx);
		}
		write(e.fd, "nosegfault--\n", 13);
		if (ft_check(e.plateau, &e) == 0)
		{
			ft_putstr("5 5\n");
			write(e.fd, "no segfault ?\n", 14);
		//	exit(0);
			if (!(e.mlx = mlx_init()))
				return (0);
			if (!(e.win = mlx_new_window(e.mlx, 2560, 1440, "filler")))
				return (0);
			truc == 0 ? ft_affichage(e, e.befor2, &truc) : 0;
			mlx_hook(e.win, 2, 1L << 0, &key_pressed, &e);
			mlx_hook(e.win, 17, (1L << 17), &red_cross, &e);
			mlx_loop(e.mlx);
		}
		write(e.fd, "il est la5\n", 11);
		ft_putstr_fd("--------------->", e.fd);
	//	ft_putnbr_fd((int)e.plateau[200], e.fd);
		ft_putstr_fd("\n", e.fd);
	//	if(e.plateau)
	//	{
			//e.befor2 = e.plateau;
			ft_putstr_fd("haha trouver\n", e.fd);
			ft_copytab(&e, e.plateau);
	//	}
		write(e.fd, "il est la6\n", 11);
	}
	return (0);
}
