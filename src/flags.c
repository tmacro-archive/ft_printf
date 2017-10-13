/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:30:39 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/01 15:58:41 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int		parse_fwidth(char *token)
{
	if (is_num(*token) && *token != '0')
		return (ft_atoi(token));
	return (0);
}

t_flags	parse_flags(const char *token)
{
	t_flags flags;

	NULL_GUARD((flags = (t_flags)ft_memalloc(sizeof(struct s_flags))));
	while (*token)
	{
		IF_RET((is_type((char*)token)), flags);
		(*token == '#') ? SET_FLAG(flags, alt) : (0);
		(*token == '0') ? SET_FLAG(flags, zpad) : (0);
		(*token == '-') ? SET_FLAG(flags, ladj) : (0);
		(*token == ' ') ? SET_FLAG(flags, spc) : (0);
		(*token == '+') ? SET_FLAG(flags, sign) : (0);
		if (is_num(*token))
		{
			flags->fwidth = parse_fwidth((char*)token);
			token = token + count_digits(flags->fwidth);
			continue ;
		}
		if (is_lmod((char*)token))
		{
			flags->lmod = is_lmod((char*)token);
			IF((flags->lmod == PFW_LL || flags->lmod == PFW_HH), (token++));
		}
		token++;
	}
	return (flags);
}
