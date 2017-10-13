/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:57:36 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/01 15:57:38 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_digits(intmax_t num)
{
	int	digits;

	digits = 0;
	(num < 0) ? ((num *= -1)) : (0);
	IF_RET((!num), 1);
	while (num > 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

char		*ft_itoa(intmax_t num)
{
	char	*res;
	int		digits;

	IF_RET((num == -9223372036854775807 - 1), \
		ft_strdup("-9223372036854775808"));
	IF_RET((num == 0), ft_strdup("+0"));
	digits = count_digits(num) + 1;
	res = ft_strnew(digits);
	CA((num < 0), *res, '-', '+');
	IF((num < 0), (num *= -1));
	res += digits - 1;
	while (num > 0)
	{
		*res-- = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

int			ft_atoi(char const *s)
{
	intmax_t	res;
	int			sign;
	char		*pos;

	pos = (char*)s;
	sign = 1;
	res = 0;
	while (*pos == ' ' || (*pos >= 9 && *pos <= 13))
		pos++;
	if (*pos == '-')
		sign = -1;
	if (*pos == '+' || *pos == '-')
		pos++;
	pos--;
	while (*++pos)
		if (*pos >= '0' && *pos <= '9')
			res = res * 10 + (*pos - '0');
		else
			break ;
	res *= sign;
	return ((int)res);
}

char		*ft_uitoa(uintmax_t num)
{
	char	*res;
	int		digits;

	digits = count_digits(num) + 1;
	res = ft_strnew(digits);
	res += digits - 1;
	while (num > 0)
	{
		*res-- = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

uintmax_t	ft_itoo(uintmax_t in)
{
	uintmax_t	out;
	uintmax_t	i;

	out = 0;
	i = 1;
	while (in != 0)
	{
		out += (in % 8) * i;
		in /= 8;
		i *= 10;
	}
	return (out);
}

char	*ft_itoh(uintmax_t in, int cse)
{
	char	out[33];
	int		i = 31;

	IF_RET((in == 0), ft_strdup("0"));
	out[32] = '\0';
	while (in != 0)
	{
		out[i--] = (in % 16 < 10) ? ('0' + (in % 16)) : (cse + (in % 16 - 10));
		in /= 16;
	}
	return (ft_strdup(&out[i + 1]));
}