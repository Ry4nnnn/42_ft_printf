/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:10:06 by welim             #+#    #+#             */
/*   Updated: 2022/05/13 22:10:07 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

//struct that stores types of format
typedef struct s_format
{
	va_list		args;
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
int		ft_printf(const char *str, ...);

//handling specifier functions
void	ft_printf_int(t_format *frmt);
void	ft_printf_char(t_format *frmt);
void	ft_printf_str(t_format *frmt);
void	ft_printf_uint(t_format *frmt);
void	ft_printf_hex(t_format *frmt);
void	ft_printf_ptr(t_format *frmt);

//utils
void	ft_putnchar_fd(char c, int n, int fd);
char	*ft_rev(char *str);

//utils for ft_printf_uint
char	*ft_long_itoa(long long n);

#endif