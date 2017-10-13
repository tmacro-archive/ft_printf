/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_simple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:30:39 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/11 12:33:26 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		f_print(char *c)
{
	size_t len;

	len = ft_strlen(c);
	write(1, c, len);
	return (len);
}

int		render_string(t_token token)
{
	size_t	len;

	len = ft_strlen(token->data);
	if (token->flags && len < (token->flags)->fwidth)
	{
		if (GET_FLAG(token, ladj))
			return (f_print(rpad(token->data, token->flags->fwidth, ' ')));
		else
			return (f_print(lpad(token->data, token->flags->fwidth, ' ')));
	}
	return (f_print(ft_strdup(token->data)));
}