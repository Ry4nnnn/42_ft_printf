/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:15:18 by welim             #+#    #+#             */
/*   Updated: 2022/05/13 22:15:18 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//this function will reset the struct values to 0
static t_format	*reset_format(t_format *frmt)
{
	frmt->space = 0;
	frmt->plus = 0;
	frmt->minus = 0;
	frmt->hash = 0;
	frmt->zero = 0;
	frmt->dot = 0;
	frmt->precision = 0;
	frmt->width = 0;
	frmt->cap_x = 0;
	frmt->size = 0;
	return (frmt);
}

//check for "csupdiuxX%" after the '%' sign
//	return 1 if have
//	return 0 if dont have
static int	check_specifier(char input)
{
	char	*type;

	type = "csupdiuxX%";
	if (ft_strchr(type, input))
		return (1);
	return (0);
}

static void	handle_specifier(t_format *frmt, char *input, int i)
{
	if (input[i] == 'd' || input[i] == 'i')
		ft_printf_int(frmt);
	if (input[i] == 'c')
		ft_printf_char(frmt);
	if (input[i] == 's')
		ft_printf_str(frmt);
	if (input[i] == 'u')
		ft_printf_uint(frmt);
	if (input[i] == 'x' || input[i] == 'X')
		ft_printf_hex(frmt);
	if (input[i] == 'p')
		ft_printf_ptr(frmt);
	if (input[i] == '%')
		frmt->size += write(1, &input[i], 1);
}

//this function will tranverse through the input string 
//in the case of encountering %, it does :
//1. reset the format type
//2. populate the format type
//3. process the format and print accordingly with argp
//if not, just print that character to the screen
static int	handle_flags(t_format *frmt, char *input, int i)
{
	while (!check_specifier(input[i]))
	{
		if (input[i] == '-')
			frmt->minus = 1;
		if (input[i] == ' ')
			frmt->space = 1;
		if (ft_isdigit(input[i]) && frmt->dot)
			frmt->precision = (frmt->precision * 10) + (input[i] - '0');
		if (ft_isdigit(input[i]) && !frmt->precision && input[i + 1] != '.')
			frmt->width = (frmt->width * 10) + (input[i] - '0');
		if (input[i] == '0' && frmt->width == 0
			&& !frmt->minus && !frmt->precision)
			frmt->zero = 1;
		if (input[i] == '+')
			frmt->plus = 1;
		if (input[i] == '#')
			frmt->hash = 2;
		if (input[i] == '.')
			frmt->dot = 1;
		i++;
	}
	if (input[i] == 'X')
		frmt->cap_x = 1;
	handle_specifier(frmt, input, i);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	t_format	*frmt;
	int			i;
	int			output;

	i = 0;
	output = 0;
	frmt = (t_format *)malloc(sizeof(t_format));
	if (!frmt)
		return (-1);
	i = -1;
	va_start(frmt->args, input);
	while (input[++i])
	{
		frmt = reset_format(frmt);
		if (input[i] == '%')
			i = handle_flags(frmt, (char *)input, i + 1);
		else
			output += write(1, &input[i], 1);
		output += frmt->size;
	}
	va_end(frmt->args);
	free(frmt);
	return (output);
}
