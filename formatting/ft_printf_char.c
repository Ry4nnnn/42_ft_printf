#include "../includes/ft_printf.h"

void	ft_printf_char(t_format *frmt)
{
	if (!frmt->width && !frmt->minus)
		print_char(frmt);
	else if (frmt->width && !frmt->minus)
		print_width(frmt);
	else if (frmt->width && frmt->minus)
		print_width_minus(frmt);
}

static void	print_char(t_format *frmt)
{
	int c;

	c = va_arg(frmt->args, int);
	frmt->size += 1;
	write(1, &c, 1);
}

static void	print_width(t_format *frmt)
{
	int width;
	int c;

	width = frmt->width;
	while (width-- > 1)
	{
		frmt->size += 1;
		ft_putchar_fd(' ', 1);
	}
	c = va_arg(frmt->args, int);
	frmt->size += 1;
	ft_putchar_fd(c, 1);
}

static void	print_width_minus(t_format *frmt)
{
	int	width;
	int	c;

	width = frmt->width;
	c = va_arg(frmt->args, int);
	ft_putchar_fd(c, 1);
	frmt->size += 1;
	while (width-- > 1)
	{
		ft_putchar_fd(' ', 1);
		frmt->size += 1;
	}
}