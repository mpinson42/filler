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
	int		y[10000];
	int		x[10000];
	int		co_1erx;
	int		co_1ery;
	int		taille;
	int		sopy[10000];
	int		sopx[10000];
	int		sop_size;
	int		bol;
	int		ciblex;
	int		cibley;
	int		joueur;
	char	**befor;
	void	*win;
	void	*mlx;
	void	*img;
	char	**plateau;
	char	*str;
	char	**tmp;
	int		fd;
	char	**map2;
	char	**tmp2;
	char 	**draw;
	int 	test;
	int 	nb_map;
}				t_env;

char **ft_bnull(char **s, size_t n);
void			ft_affichage(t_env e, char **plateau, int *truc);
int				ft_check(char **plateau, t_env *e);
int				ft_strlen_tab(char **tab);
char			**ft_get_plateau(char *str, t_env *e);
int				ft_get_piece(t_env *e, char *str);
int				ft_check_placeo(char **plateau, t_env *e, int x, int y);
int				ft_check_placex(char **plateau, t_env *e, int x, int y);

#endif
