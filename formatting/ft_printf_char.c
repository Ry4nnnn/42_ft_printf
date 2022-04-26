#include "../includes/ft_printf.h"

void	ft_printf_char(t_format *frmt)
{
	const char	c = va_arg(frmt->args, int);

	if (frmt->minus == 0)
	{
		while (frmt->width > 1)
		{
			frmt->size += ft_putchar_fd(' ', 1);
			frmt->width--;
		}
		frmt->size += ft_putchar_fd(c, 1);
	}
	else
	{
		frmt->size += ft_putchar_fd(c, 1);
		while (frmt->width > 1)
		{
			frmt->size += ft_putchar_fd(' ', 1);
			frmt->width--;
		}
	}
}