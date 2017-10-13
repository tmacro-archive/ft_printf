/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_base.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:43:50 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/07 16:43:52 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    render_octal(t_token token)
{
    int	    	width;
    uintmax_t   octal;
	char	    *conv;
	char	    pad;

	width = token->width;
	// IF((width == PFT_UINT), (octal = ft_itoo(*(uint*)(token->data))));
	IF((width == PFT_UINT), (octal = ft_itoo(AS(uint, token->data))));
    IF((width == PFT_UCHAR), (octal = ft_itoo(AS(uchar, token->data))));
	IF((width == PFT_USINT), (octal = ft_itoo(*(usint*)(token->data))));
	IF((width == PFT_ULINT), (octal = ft_itoo(*(ulint*)(token->data))));
	IF((width == PFT_ULLINT), (octal = ft_itoo(*(ullint*)(token->data))));
	IF((width == PFT_UMXINT), (octal = ft_itoo(*(uintmax_t*)(token->data))));
	IF((width == PFT_SIZET), (octal = ft_itoo(*(size_t*)(token->data))));
	// octal = ft_itoo(*(uintmax_t*)(token->data));
	// printf("%ju\n", octal);
    CA(GET_FLAG(token, zpad), pad, '0', ' ');
    conv = ft_uitoa(octal);
	printf("\nconv: '%s'\n", conv + 1);
    if (GET_FLAG(token, ladj))
		return (f_print(rpad(conv, token->flags->fwidth, ' ') + 1));
	else
		return (f_print(lpad_int(conv, token->flags->fwidth, pad) + 1));
	ft_memfree((void**)&conv);
}

int	render_hex(t_token token)
{
	// char	*conv;
	char	pad;
	char	cse;
	char	*conv;
	char	*temp;

    CA(GET_FLAG(token, zpad), pad, '0', ' ');
	CA((token->symbol == 'x'), cse, 'a', 'A');
	conv = ft_itoh(AS(umxint, token->data), cse);
	if (GET_FLAG(token, alt))
	{
		temp = conv;
		conv = ft_strjoin(((token->symbol == 'x') ? "0x" : "0X"), conv);
		ft_memfree((void**)&temp);
	}
	if (GET_FLAG(token, ladj))
		return (f_print(rpad(conv, token->flags->fwidth, ' ')));
	else
		return (f_print(lpad(conv, token->flags->fwidth, pad)));
	ft_memfree((void**)&conv);
}