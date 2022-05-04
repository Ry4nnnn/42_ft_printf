#include "../includes/ft_printf.h"

static void	count_spc_prc(t_format *frmt, char *str)
{
	int	sub_len;
	int	len;

	len = (int) ft_strlen(str);
	sub_len = (int) ft_strlen(str);
	if (str[0] == '-')
		sub_len -= 1;
	if (sub_len >= frmt->precision)
		frmt->precision = 0;
	if (frmt->precision > sub_len)
		frmt->precision = frmt->precision - sub_len;
	if (frmt->width <= 0 || (frmt->minus && frmt->width <= sub_len))
		frmt->width = 0;
	if (frmt->width)
		frmt->width = frmt->width - len - frmt->precision;
	if (frmt->width <= 0)
		frmt->width = 0;
	if (frmt->precision <= 0)
		frmt->precision = 0;
}

static void	print_nint(t_format *frmt, char *str)
{
	if (frmt->zero)
	{
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', frmt->width, 1);
		ft_putstr_fd(&str[1], 1);
	}
	else
	{
		if  (frmt->minus)
		{
			ft_putchar_fd('-', 1);
			ft_putnchar_fd('0', frmt->precision, 1);
			ft_putstr_fd(&str[1], 1);
			ft_putnchar_fd(' ', frmt->width, 1);
		}
		else if (!frmt->minus)
		{
			ft_putnchar_fd(' ', frmt->width, 1);
			ft_putchar_fd('-', 1);
			ft_putnchar_fd('0', frmt->precision, 1);
			ft_putstr_fd(&str[1], 1);
		}
	}
	frmt->size += ft_strlen(&str[1]) + frmt->width + frmt->precision + 1;
}

static void	print_spc_plus(t_format *frmt)
{
	if (frmt->space)
		ft_putchar_fd(' ' , 1);
	if (frmt->plus)
		ft_putchar_fd('+', 1);
}

static void	print_pint(t_format *frmt, char *str)
{
	print_spc_plus(frmt);
	if (frmt->zero)
	{
		ft_putnchar_fd('0', frmt->width, 1);
		ft_putstr_fd(&str[0], 1);
	}
	else
	{
		if (frmt->minus)
		{
			ft_putnchar_fd('0', frmt->precision, 1);
			ft_putstr_fd(str, 1);
			ft_putnchar_fd(' ', frmt->width, 1);
		}
		else if (!frmt->minus)
		{
			ft_putnchar_fd(' ', frmt->width, 1);
			ft_putnchar_fd('0', frmt->precision, 1);
			ft_putstr_fd(str, 1);
		}
	}
	frmt->size += ft_strlen(&str[0]) + frmt->width + frmt->precision
		+ frmt->plus + frmt->space;
}

void	ft_printf_int(t_format *frmt)
{
	int		number;
	char	*str;

	number = va_arg(frmt->args, int);
	str = ft_itoa(number);
	count_spc_prc(frmt, str);
	if (number < 0)
	{
		print_nint(frmt, str);
	}
	else
	{
		print_pint(frmt, str);
	}
	free(str);
}