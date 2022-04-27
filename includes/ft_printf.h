#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

//struct that stores types of format
typedef struct s_format
{
	va_list  args;//	arg to print out
	int			plus;
	int			precision;
	int			dot;
	int			minus;
	int			count;
	int			width;
	int			space;
	int			zero;
	int			cap_x;
	int			hash;
	// int 		zeroes;
	int			size;
}				t_format;

//main function
int ft_printf(const char *str, ...);

//handling specifier functions
void	ft_printf_int(t_format *frmt);
void	ft_printf_char(t_format *frmt);
void	ft_printf_str(t_format *frmt);
void	ft_printf_uint(t_format *frmt);
void	ft_printf_hex(t_format *frmt);
void	ft_printf_ptr(t_format *frmt);


#endif