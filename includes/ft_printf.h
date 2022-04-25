#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "..libft/libft.h"

//struct that stores types of format
typedef struct s_format
{
	va_list  args;//	arg to print out
	int			plus;
	int			prc;
	int			dot;
	int			minus;
	int			count;
	int			width;
	int			space;
	int			zero;
	// int		cap_x;
	int			hash;
	int 		zeroes;
}			t_format;

//main function
int ft_printf(const char *str, ...);

#endif