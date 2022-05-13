/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:02:47 by welim             #+#    #+#             */
/*   Updated: 2022/05/13 22:04:11 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//way #1
// static char	*ft_itoa_hex(long long num, t_format *frmt)
// {
// 	char	res[1024];
// 	int		i;
// 	char	*hex_base;

// 	if (num == 0)
// 		return (ft_rev("0"));
// 	if (frmt->cap_x)
// 		hex_base = "0123456789ABCDEF";
// 	else
// 		hex_base = "0123456789abcdef";
// 	i = 0;
// 	while (num > 0)
// 	{
// 		res[i++] = hex_base[(num % 16)];
// 		num /= 16;
// 	}
// 	res[i] = '\0';
// 	return (ft_rev(res));
// }

//way #2
static char	*ft_itoa_hex(long long num, t_format *frmt)
{
	char	res[1024];
	int		i;
	int		offset;

	if (num == 0)
		return (ft_rev("0"));
	if (!frmt->cap_x)
		offset = 87;
	else
		offset = 55;
	i = 0;
	while (num > 0)
	{
		res[i] = (num % 16) + 48;
		if ((num % 16) + 48 > 57)
			res[i] = (num % 16) + offset;
		num /= 16;
		i++;
	}
	res[i] = 0;
	return (ft_rev(res));
}

static void	count_spc_prc(t_format *frmt, char *str)
{
	int	sub_len;
	int	len;

	len = (int) ft_strlen(str);
	sub_len = (int) ft_strlen(str);
	if (atoi(str))
		sub_len += frmt->hash;
	if (str[0] == '-')
		sub_len--;
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

static void	printf_x(t_format *frmt, char *hex, char *sign)
{
	if (frmt->zero)
	{
		ft_putnchar_fd('0', frmt->width, 1);
		ft_putstr_fd(hex, 1);
		return ;
	}
	if (frmt->minus)
	{
		if (frmt->hash)
			ft_putstr_fd(sign, 1);
		ft_putnchar_fd('0', frmt->precision, 2);
		ft_putstr_fd(hex, 1);
		ft_putnchar_fd(' ', frmt->width, 1);
	}
	else if (!frmt->minus)
	{
		ft_putnchar_fd(' ', frmt->width, 1);
		if (frmt->hash)
			ft_putstr_fd(sign, 1);
		ft_putnchar_fd('0', frmt->precision, 1);
		ft_putstr_fd(hex, 1);
	}	
}

void	ft_printf_hex(t_format *frmt)
{
	long long	num;
	char		*sign;
	char		*hex;

	sign = "0x";
	num = va_arg(frmt->args, int);
	if (num < 0)
		num = UINT_MAX + num + 1;
	hex = ft_itoa_hex(num, frmt);
	count_spc_prc(frmt, hex);
	if (hex[0] == '0' && frmt->hash && ft_strlen(hex) == 1)
	{
		ft_putchar_fd('0', 1);
		frmt->size += 1;
	}
	else
	{
		if (frmt->cap_x)
			sign = "0X";
		printf_x(frmt, hex, sign);
		frmt->size += ft_strlen(hex) + frmt->width + frmt->precision
			+ frmt->plus + frmt->space + frmt->hash;
	}
	free(hex);
}
