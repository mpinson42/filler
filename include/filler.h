/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:55:53 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/02 13:56:12 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>

typedef struct	s_env
{
	int			y[10000];
	int			x[10000];
	int			co_1erx;
	int			co_1ery;
	int			taille;
	int			sopy[10000];
	int			sopx[10000];
	int			sop_size;
	int			bol;
	int			ciblex;
	int			cibley;
	int			joueur;
	char		befor[200][200];
	void		*win;
	void		*mlx;
	char		str[20000];
	char		test2[500];
	char		test3[500];
	char		str2[20000];
	char		tmp[200][200];
	char		test4[20000];
	int			count;
	int			fd;
	char		map2[200][200];
	int			leng_map;
	char		tmp2[200][200];
	int			test;
	int			nb_map;
	int			chiffre1[20];
	int			chiffre2[20];
}				t_env;

char			**ft_bnull(char **s, size_t n);
void			ft_affichage(t_env e, int *truc);
int				ft_check(t_env *e);
int				ft_strlen_tab(char **tab);
void			ft_get_plateau(char *str, t_env *e);
int				ft_get_piece(t_env *e, char *str);
int				ft_check_placeo(t_env *e, int x, int y);
int				ft_check_placex(t_env *e, int x, int y);

#endif
