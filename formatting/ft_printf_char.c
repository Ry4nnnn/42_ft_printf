#include "../includes/ft_printf.h"

void	ft_printf_char(t_format *frmt)
{
	const char	c = va_arg(frmt->args, int);

	if (frmt->minus == 0)
	{
		while (frmt->width-- > 1)
			frmt->size += ft_putchar(' ');
		frmt->size += ft_putchar(c);
	}
	else
	{
		frmt->size += ft_putchar(c);
		while (frmt->width-- > 1)
			frmt->size += ft_putchar(' ');
	}
}
