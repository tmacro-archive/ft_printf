/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:39:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/07 15:39:20 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    render_uinteger(t_token token)
{
    int		width;
	char	*conv;
	char	pad;
	size_t	os;

	width = token->width;
	IF((width == PFT_UINT), (conv = ft_uitoa(*(uint*)(token->data))));
	IF((width == PFT_USINT), (conv = ft_uitoa(*(usint*)(token->data))));
	IF((width == PFT_ULINT), (conv = ft_uitoa(*(ulint*)(token->data))));
	IF((width == PFT_ULLINT), (conv = ft_uitoa(*(ullint*)(token->data))));
	IF((width == PFT_UMXINT), (conv = ft_uitoa(*(uintmax_t*)(token->data))));
	IF((width == PFT_SIZET), (conv = ft_uitoa(*(size_t*)(token->data))));
	CA(GET_FLAG(token, zpad), pad, '0', ' ');
	CA((!GET_FLAG(token, sign) && !GET_FLAG(token, spc)), os, 1, 0);
	IF((!GET_FLAG(token, sign) && GET_FLAG(token, spc)), (*conv = ' '));
	if (GET_FLAG(token, ladj))
		return (f_print(rpad(conv, token->flags->fwidth, ' ') + os));
	else
		return (f_print(lpad_int(conv, token->flags->fwidth, pad) + os));
	ft_memfree((void**)&conv);
}