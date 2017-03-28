#ifndef FILLER_H
# define FILLER_H


#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_env
{
	int *y;
	int *x;
	int taille;
}				t_env;



#endif