/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:58:55 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/01 15:58:57 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "constants.h"

int	is_int_type(int type)
{
	return (type >= PFT_INT && type <= PFT_MXINT);
}

int	is_uint_type(int type)
{
	return (type >= PFT_UINT && type <= PFT_UMXINT);
}

int	is_char_type(int type)
{
	return (type == PFT_CHAR);
}

int	is_wchar_type(int type)
{
	return (type == PFT_WCHAR);
}

int	is_str_type(int type)
{
	return (type == PFT_STR);
}

int	is_wstr_type(int type)
{
	return (type == PFT_WSTR);
}
