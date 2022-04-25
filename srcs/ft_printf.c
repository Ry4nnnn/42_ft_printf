#include "ft_printf.h"

//this function will reset the struct values to 0
static void	reset_format(t_format *flags)
{
	flags->width = 0;
	flags->prc = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	// flags->cap_x = 0;
	flags->count = 0;
	return (flags);
}

//this function check for the flags
static void	check_flags(char *str, t_format *input)
{
	if (*str == ' ')
		flags->space = 1;
	if (*str == '+')
		flags->plus = 1;
	if (*str == '-')
		flags->minus = 1;
	if (*str == '#')
		flags->hash = 1;
	if (*str == '0')
		flags->zero = 1;
}

//calculate the width precision
static char	*check_width_precision(char *str, t_format *flags)
{
	if (*str >= '1' && *str <= '9')
	{
		while (ft_isdigit(*str))
			flags->width = flags->width * 10 + *str++ - 48;
		str--;
	}
	if (*str == '.')
	{
		flags->dot = 1;
		str++;
		while (ft_isdigit(*str))
			flags->precision = flags->precision * 10 + *str++ - 48;
		str--;
	}
	return (str);
}

//check for specifier
static int	*check_specifier(char *str, t_format *flags)
{
	while (*str && (!ft_strchr("csdiuxXp%", *str)))
	{
		check_flags(str, flags);
		str = check_width_precision(str, flags);
		str++;
	}
	if (*str == 'd' || *str == 'i')//	decimal
		ft_printf_int(flags);
	if (*str == 'c')//					character
		ft_printf_char(flags);
	if (*str == 's')//					string
		ft_printf_str(flags);
	if (*str == 'u')//					unsigned int
		ft_printf_uint(flags);
	if (*str == 'x' || *str == 'X')//	hexadecimal
		ft_printf_hex(flags, *str);
	if (*str == 'p')//					pointer
		ft_printf_ptr(flags);
	if (*str == '%')//					prints '%' character
		flags->size += ft_putchar('%');
	//str++
	return (++str);
}

int ft_printf(const char *input, ...)
{
	int output;
	char	*str;
	t_format *flags;

	output = 0;
	flags = (t_format *)malloc(sizeof(t_format));
	if (!flags)
		return (-1);
	va_start(flags->args, input);
	flags->size = 0;
	while (*str)//	while the string exists
	{
		if (*str == '%')
		{
			reset_format(flags);
			str = check_specifier(++str, flags);
			//str = check_specifier(flags, (char *)input, i + 1);//i + 1 because we start evaluate after the % sign
		}
		else
		{
			output += write(1, str++, 1);
		}
		// res += flags->count;
	}
	va_end(flags->args);
	output += flags->size;
	free(flags);
	return (output);
}