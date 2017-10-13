/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:57:18 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/01 15:57:20 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "constants.h"

int	is_flag(char *c)
{
	ERR_CNR(c, NULL, 0);
	ERR_CNR(*c, '#', 1);
	ERR_CNR(*c, '0', 1);
	ERR_CNR(*c, '-', 1);
	ERR_CNR(*c, '+', 1);
	ERR_CNR(*c, ' ', 1);
	IF_RET((is_num(*c)), 1);
	return (0);
}

int	is_type(char *c)
{
	ERR_CNR(c, NULL, 0);
	ERR_CNR(*c, 's', PFT_STR);
	ERR_CNR(*c, 'S', PFT_WSTR);
	ERR_CNR(*c, 'p', PFT_PTR);
	ERR_CNR(*c, 'd', PFT_INT);
	ERR_CNR(*c, 'D', PFT_LINT);
	ERR_CNR(*c, 'i', PFT_INT);
	ERR_CNR(*c, 'o', PFT_UINT);
	ERR_CNR(*c, 'O', PFT_ULINT);
	ERR_CNR(*c, 'u', PFT_UINT);
	ERR_CNR(*c, 'U', PFT_ULINT);
	ERR_CNR(*c, 'x', PFT_UINT);
	ERR_CNR(*c, 'X', PFT_UINT);
	ERR_CNR(*c, 'c', PFT_CHAR);
	ERR_CNR(*c, 'C', PFT_WCHAR);
	return (0);
}

int	is_lmod(char *s)
{
	size_t	len;

	ERR_CNR(s, NULL, 0);
	len = ft_strlen(s);
	IF_RET((len > 1 && *s == 'h' && *(s + 1) == 'h'), PFW_HH);
	IF_RET((len > 1 && *s == 'l' && *(s + 1) == 'l'), PFW_LL);
	IF_RET((len && *s == 'h'), PFW_H);
	IF_RET((len && *s == 'l'), PFW_L);
	IF_RET((len && *s == 'j'), PFW_J);
	IF_RET((len && *s == 'z'), PFW_Z);
	return (0);
}

int	is_token(char *s)
{
	ERR_CNR(s, NULL, 0);
	IF_RET((*s++ != '%'), 0);
	while(*s && !is_type(s))
		s++;
	if (!*s)
		return (0);	
	return (1);
	// return (*s == '%' && (is_flag((n)) || is_type((n)) || is_lmod(n)));
}

int	is_width(int t, int l)
{
	IF_RET((!t), t);
	IF_RET(((t == PFT_INT || t == PFT_UINT) && l <= PFW_J), (t + l));
	IF_RET(((t == PFT_INT || t == PFT_UINT) && l == PFW_Z), PFT_SIZET);
	IF_RET((t == PFT_INT && l == PFW_HH), PFT_CHAR);
	IF_RET((t == PFT_UINT && l == PFW_HH), PFT_UCHAR);
	IF_RET((t == PFT_STR && l == PFW_L), PFT_WSTR);
	IF_RET((t == PFT_CHAR && l == PFW_L), PFT_WCHAR);
	return (t);
}
