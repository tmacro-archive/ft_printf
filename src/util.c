/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:36:37 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/15 13:52:42 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*wrap_int(intmax_t arg)
{
	void	*parg;

	NULL_GUARD((parg = ft_memalloc(sizeof(arg))));
	ft_memcpy(parg, (void*)&arg, sizeof(arg));
	return (parg);
}

void	*wrap_uint(uintmax_t arg)
{
	void	*parg;

	NULL_GUARD((parg = ft_memalloc(sizeof(arg))));
	ft_memcpy(parg, (void*)&arg, sizeof(arg));
	return (parg);
}

void	*wrap_char(char arg)
{
	void	*parg;

	NULL_GUARD((parg = ft_memalloc(sizeof(arg))));
	ft_memcpy(parg, (void*)&arg, sizeof(arg));
	return (parg);
}

void	*wrap_wchar(char arg)
{
	void	*parg;

	NULL_GUARD((parg = ft_memalloc(sizeof(arg))));
	ft_memcpy(parg, (void*)&arg, sizeof(arg));
	return (parg);
}
