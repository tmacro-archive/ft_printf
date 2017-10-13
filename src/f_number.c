/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_number.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:57:56 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/01 15:57:57 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	render_integer(t_token token)
{
	int		width;
	size_t	os;
	char	*conv;
	char	pad;

	width = token->width;
	//printf("-%s-\n", ft_itoa(*(long long int*)token->data));
	(width == 4) ? ((conv = ft_itoa(*(int*)(token->data)))) : (0);
	(width == 5) ? ((conv = ft_itoa(*(short int*)(token->data)))) : (0);
	(width == 6) ? ((conv = ft_itoa(*(long int*)(token->data)))) : (0);
	(width == 7) ? ((conv = ft_itoa(*(long long int*)(token->data)))) : (0);
	(width == 8) ? ((conv = ft_itoa(*(intmax_t*)(token->data)))) : (0);
	(width == 17) ? ((conv = ft_itoa(*(size_t*)(token->data)))) : (0);
	CA(GET_FLAG(token, zpad), pad, '0', ' ');
	// (GET_FLAG(token, zpad)) ? ((pad = '0')) : ((pad = ' '));
	CA((!GET_FLAG(token, sign) && !GET_FLAG(token, spc)), os, 1, 0);
	// (!GET_FLAG(token, sign) && !GET_FLAG(token, spc)) ? ((os = 1)) : (os = 0);
	(!GET_FLAG(token, sign) && GET_FLAG(token, spc)
									&& *conv != '-') ? ((*conv = ' ')) : (0);
	// printf("offset: %lu\n", os);
	// printf("sign: %i, spc: %i\n", GET_FLAG(token, sign), GET_FLAG(token, spc));
	if (GET_FLAG(token, ladj))
	{
		// printf("{{{{ladj}}}}");
		// printf("padded: '%s'\n", rpad(conv, token->flags->fwidth, ' '));
		return (f_print(rpad(conv, token->flags->fwidth, ' ') + os));
	}
	else
	{
		// printf("{{{{radj}}}}");
		return (f_print(lpad_int(conv, token->flags->fwidth, pad) + os));
	}
	// printf("conv: %s\n", conv);
	// (*conv != '+' && *conv != '-' && *conv != ' ') ? ((conv--)) : (0);
	ft_memfree((void**)&conv);
}
