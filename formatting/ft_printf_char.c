/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:02:44 by welim             #+#    #+#             */
/*   Updated: 2022/05/13 22:02:45 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char(t_format *frmt)
{
	int	c;

	c = va_arg(frmt->args, int);
	frmt->size += 1;
	write(1, &c, 1);
}

void	print_width(t_format *frmt)
{
	int	width;
	int	c;

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

void	print_width_minus(t_format *frmt)
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

void	ft_printf_char(t_format *frmt)
{
	if (!frmt->width && !frmt->minus)
		print_char(frmt);
	else if (frmt->width && !frmt->minus)
		print_width(frmt);
	else if (frmt->width && frmt->minus)
		print_width_minus(frmt);
}
