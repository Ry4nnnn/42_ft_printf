/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:02:56 by welim             #+#    #+#             */
/*   Updated: 2022/05/13 22:07:49 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	count_spc_prc(t_format *frmt, int *space, char *str)
{
	*space = 0;
	if (!frmt->precision && frmt->dot)
		frmt->precision = 0;
	else if (!frmt->precision || frmt->precision > (int) ft_strlen(str))
		frmt->precision = ft_strlen(str);
	if (frmt->width > frmt->precision)
		*space = frmt->width - frmt->precision;
}

void	ft_printf_str(t_format *frmt)
{
	char	*str;
	int		space;

	str = va_arg(frmt->args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		frmt->size += 6 ;
		return ;
	}
	count_spc_prc(frmt, &space, str);
	if (frmt->minus)
	{
		write(1, str, frmt->precision);
		ft_putnchar_fd(' ', space, 1);
	}
	else
	{
		ft_putnchar_fd(' ', space, 1);
		write(1, str, frmt->precision);
	}
	frmt->size += frmt->precision + space;
}
