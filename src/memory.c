/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:25:27 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/07 15:25:29 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = (void*)malloc(size);
	if (fresh == NULL)
		return (NULL);
	ft_memset(fresh, '\0', size);
	return (fresh);
}

void	ft_memfree(void **ptr)
{
	NULL_GUARD_NR(ptr);
	free(*ptr);
	*ptr = NULL;
}

char	*ft_strnew(size_t size)
{
	char	*freshmeat;

	freshmeat = ft_memalloc(size + sizeof(char));
	if (freshmeat == NULL)
		return (NULL);
	ft_memset(freshmeat, '\0', size + sizeof(char));
	return (freshmeat);
}

void	ft_memcpy(void *dest, void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (size--)
		*d++ = *s++;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pos;

	pos = s;
	while (n--)
		*pos++ = (unsigned char)c;
	return (s);
}
