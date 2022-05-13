/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:11:12 by welim             #+#    #+#             */
/*   Updated: 2022/05/13 22:12:31 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long	count_len(long long n)
{
	if (n == 0)
		return (0);
	else
		return (1 + count_len(n / 10));
}

static long long	convert(long long n)
{
	long long	res;

	if (n < 0)
		res = (unsigned int)(n * -1);
	else
		res = (unsigned int)n;
	return (res);
}

static char	last_digit_to_char(long long n)
{
	if (n == 0)
		return ('0');
	else
		return ((char) '0' + n % 10);
}

char	*ft_long_itoa(long long n)
{
	char			*res;
	int				x;
	long long		copy;
	int				len;

	len = 1 + count_len(n / 10);
	if (n < 0)
		len++;
	res = malloc(len + 1);
	if (!res)
		return (res);
	res[len] = '\0';
	if (n < 1 && n > -1)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	copy = convert(n);
	x = len;
	while (copy)
	{
		res[--x] = last_digit_to_char(copy);
		copy = copy / 10;
	}
	return (res);
}
