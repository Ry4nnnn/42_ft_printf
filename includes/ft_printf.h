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
	int			minus;
	int			space;
	int			width;
	int			precision;
	int			zero;
	int			plus;
	int			hash;
	int			dot;
	int			cap_x;
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

//utils
void	ft_putnchar_fd(char c, int n, int fd);
void	ft_putnbr_fd_long(unsigned int num, int fd);
char	*ft_rev(char *str);
char	*to_hex(unsigned long long num);
char	*ft_long_itoa(long long n);

#endif