#include "../includes/ft_printf.h"

static char	*ft_hex_ptr(unsigned long long num)
{
	char	ret[1024];
	int		i;

	i = 0;
	while (num > 0)
	{
		ret[i] = (num % 16) + 48;
		if (((num % 16) + 48) > 57)
			ret[i] = (num % 16) + 87;
		num = num / 16;
		i++;
	}
	ret[i] = 0;
	return (ft_rev(ret));
}

static void	count_spc(t_format *frmt, int *space, int len)
{
	*space = 0;
	if (frmt->width >len)
	{
		*space = frmt->width - len;
		frmt->size += frmt->width;
	}
	else
		frmt->size += len;
}

void	ft_printf_ptr(t_format *frmt)
{
	long long num;
	char *str;
	int	space;

	num = (long long)va_arg(frmt->args, void *);
	if (!num)
	{
		ft_putstr_fd("0x0", 1);
		frmt->size += 3;
	}
	else
	{
		str = ft_hex_ptr(num);
		count_spc(frmt, &space, ft_strlen(str) + 2);
		if (!frmt->minus)
		{
			ft_putnchar_fd(' ', space, 1);
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(str, 1);
		}
		else if (frmt->minus)
		{
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(str, 1);
			ft_putnchar_fd(' ', space, 1);
		}
		free(str);
	}
}