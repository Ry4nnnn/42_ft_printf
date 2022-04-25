#include "ft_printf.h"

//this function will reset the struct values to 0
static t_format	*ft_reset_format(t_format *flags)
{
	flags->wdt = 0;
	flags->prc = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->dash = 0;
	flags->tl = 0;
	flags->sign = 0;
	flags->is_zero = 0;
	flags->perc = 0;
	flags->sp = 0;
	return (flags);
}

int ft_printf(const char *input, ...)
{
	int output;
	int i;
	t_print *flags;

	output = 0;
	flags = (t_print *)malloc(sizeof(t_print));
	if (!flags)
		return (-1);
	ft_reset_format(flags);
	va_start(flags->args, input);
	i = -1;
	while (input[++i])//	while the string exists
	{
		if (input[i] == '%')
			i = ft_handle_format(flags, (char *)input, i + 1);//i + 1 because we start evaluate after the % sign
		else
			output += write(1, &input[i], 1);
	}
	va_end(flags->args);
	output += flags->tl;
	free(flags);
	return (output);
}