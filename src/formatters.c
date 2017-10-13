/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:23:05 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/07 13:23:07 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rpad(char *s, size_t width, char c)
{
	char	*freshmeat;
	size_t	len;
	size_t	needed;

	len = ft_strlen(s);
	(width < len) ? ((width = len)) : (0);
	needed = width - len;
	freshmeat = ft_strnew(width);
	freshmeat = freshmeat + width - 1;
	while (needed--)
		*freshmeat-- = c;
	s = s + len - 1;
	while (len--)
		*freshmeat-- = *s--;
	return (freshmeat + 1);
}

char	*lpad(char *s, size_t width, char c)
{
	char	*freshmeat;
	char	*ret;
	size_t	needed;
	size_t	len;

	len = ft_strlen(s);
	(width < len) ? ((width = len)) : (0);
	needed = width - ft_strlen(s);
	freshmeat = ft_strnew(width);
	ret = freshmeat;
	while (needed--)
		*freshmeat++ = c;
	while (*s)
		*freshmeat++ = *s++;
	return (ret);
}

char	*lpad_int(char *s, size_t width, char c)
{
	char	sign;
	char	*padded;

	sign = *s;
	*s = c;
	padded = lpad(s, width, c);
	*padded = sign;
	return (padded);
}
