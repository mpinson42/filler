#ifndef FILLER_H
# define FILLER_H


#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

typedef struct s_env
{
	int *y;
	int *x;
	int co_1erx;
	int co_1ery;
	int taille;
	int sopy[255];
	int sopx[255];
	int sop_size;
	int bol;
	int ciblex;
	int cibley;
	int joueur;
	char **befor;
}				t_env;

int ft_check(char **plateau, t_env *e, int fd);
int ft_strlen_tab(char **tab);

#endif