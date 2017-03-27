#include "filler.h"
#include <limits.h>

static int i = 0;

int main(int argv, char **argc)
{
	char *str[600];
	char *str2[600];
	int fd;

	fd = open("./test", O_RDWR);
	



	ft_bzero(str, 600);
	read(0, &str, 600);
	ft_putstr_fd(str, fd);
	ft_putstr("11 14\n");


	while(i < INT_MAX)
		i++;


	ft_bzero(str2, 600);
	read(0, &str2, 600);
	ft_putstr_fd(str2, fd);
	ft_putstr("11 14\n");

	

	i++;
	return(0);
}