#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "..libft/libft.h"

//struct that stores types of format

// typedef struct s_print
// {
// 	va_list	args;
// 	int		tl;//total length
// 	int		wdt;//width
// 	int		prc;//precision
// 	int		zero;// is number zero
// 	int		pnt;// .
// 	int		dash;// -
// 	int		hash;
// 	int		sign;//positive or negative number
// 	int		spc;//space flags
// 	int		cap_x;// X
// }	t_print;

typedef struct s_print
{
	va_list  args;//	arg to print out
	int		wdt;//		width
	int		prc;//		precision
	int		zero;//		zero padding
	int		dot;//		.
	int		dash;//		-
	int		tl;//		total_length (return value)
	int		sign;//		positive or negative number
	int		is_zero;//	is number zero
	int		perc;//		%
	int		sp;//		space flag ' '
}		t_print;

//main function
int ft_printf(const char *str, ...);

#endif