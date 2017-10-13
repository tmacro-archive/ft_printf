/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:26:23 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/07 13:26:24 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "constants.h"

int	render_token(t_token token)
{
	IF_RET((token->width == 0), render_string(token));
	IF_RET((token->symbol == 'o'), render_octal(token));
	IF_RET((token->symbol  == 'x'), render_hex(token));
	IF_RET((token->symbol  == 'X'), render_hex(token));
	IF_RET((token->width == PFT_STR), render_string(token));
	IF_RET((token->width >= PFT_INT &&
		token->width <= PFT_MXINT), render_integer(token));
	IF_RET((token->width >= PFT_UINT &&
		token->width <= PFT_UMXINT), render_uinteger(token));
	return (0);
}
