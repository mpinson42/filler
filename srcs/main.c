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

	x = -1;
	while (bol == 0 && e->nb_map != 1 && tableau[++x])
	{
		y = -1;
		while (tableau[x][++y] != 0)
		{
			if (e->joueur == 2 && tableau[x][y] == 'O' &&
				e->befor[x][y] != tableau[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
			if (e->joueur == 1 && tableau[x][y] == 'X' &&
				e->befor[x][y] != tableau[x][y])
			{
				e->ciblex = x;
				e->cibley = y;
			}
		}
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

int		ft_delay(t_env *e)
{
	int			lol;
	char *tmp;
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
	while((lol = get_next_line(0, &tmp)) >= 1)
	{
		ft_bzero(e->test2, 500);
		ft_strcpy(e->test2, tmp);
//		ft_putstr_fd("1et gnl\n" ,e->fd);
		if(ft_strncmp("Piece", e->test2, 5) == 0)
		{
			e->test2[ft_strlen(e->test2)] = '\n';
			ft_join(e->test2, e);
			i = ft_atoi(e->test2 + 5);
			ft_putstr_fd(e->test2 + 5, e->fd);
//			write(fd, ft_itoa(i), ft_strlen(ft_itoa(i)));
			while(i)
			{
				ft_putstr_fd("2et gnl\n" ,e->fd);
				if(get_next_line(0, &tmp) == -1)
					return(0);
				ft_bzero(e->test2, 500);
				ft_strcpy(e->test2, tmp);
				e->test2[ft_strlen(e->test2)] = '\n';
				ft_join(e->test2, e);
			//	ft_putstr_fd(e->str, fd);
				i--;
			}
			break;
		}
		e->test2[ft_strlen(e->test2)] = '\n';
		ft_join(e->test2, e);
	}
	write(e->fd, "il est la9\n", 11);
	write(e->fd, e->str, ft_strlen(e->str));
	write(e->fd, "\n\n\n-->", 6);
	write(e->fd, ft_itoa_base(e->str[2], 10), 3);
	write(e->fd, "il est la9\n", 11);
	if(e->str[0] == 0)
		return(0);

	if (lol == -1 || !(e->plateau = ft_get_plateau(e->str, e)))
		return (0);
	if (ft_strlen(e->plateau[0]) <= 17 || ft_strlen_tab(e->plateau) <= 15)
		e->nb_map = 1;
	ft_cible(e->plateau, e);
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


int		main(void)
{
	t_env		e;
	int i;
	static int	truc = 0;

	e.befor = NULL;
	e.map2 = NULL;
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
		e.count = 0;
		if (( i = ft_delay(&e)) == 0 || (ft_get_piece(&e, e.str) == -1))
		{
			write(e.fd, "no segfault ?\n", 14);
		//	ft_putstr("5 5\n");
		//	exit(0);
			if (!(e.mlx = mlx_init()))
				return (0);
			if (!(e.win = mlx_new_window(e.mlx, 2560, 1440, "filler")))
				return (0);
			write(e.fd, "no segfault ?\n", 14);
			truc == 0 ? ft_affichage(e, e.befor, &truc) : 0;
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
			truc == 0 ? ft_affichage(e, e.plateau, &truc) : 0;
			mlx_hook(e.win, 2, 1L << 0, &key_pressed, &e);
			mlx_hook(e.win, 17, (1L << 17), &red_cross, &e);
			mlx_loop(e.mlx);
		}
		write(e.fd, "il est la5\n", 11);
		if(e.plateau)
			e.befor = e.plateau;
		write(e.fd, "il est la6\n", 11);
	}
	return (0);
}
