/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:26:33 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/07 15:26:35 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	char	*freshmeat;

	freshmeat = ft_strnew(ft_strlen(s));
	ft_strncpy(freshmeat, s, ft_strlen(s));
	return (freshmeat);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*freshmeat;
	char	*ret;

	NULL_GUARD((freshmeat = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)));
	ret = freshmeat;
	while (*s1)
		*freshmeat++ = *s1++;
	while (*s2)
		*freshmeat++ = *s2++;
	*freshmeat = '\0';
	return (ret);
}

size_t	ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	src = (unsigned char*)s2;
	dest = (unsigned char*)s1;
	n += 1;
	while (--n)
		if (*src)
			*dest++ = *src++;
		else
			break ;
	if (n != 0)
		ft_memset(dest, '\0', n);
	return (s1);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*pos;
	char	*freshmeat;

	NULL_GUARD((freshmeat = ft_strnew(len)));
	NULL_GUARD(s);
	pos = (char*)s + start;
	ft_strncpy(freshmeat, pos, len);
	return (freshmeat);
}
