/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:40:58 by tmckinno          #+#    #+#             */
/*   Updated: 2017/06/11 13:18:49 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_token	new_token(int type, t_flags flags, char *text, void *data)
{
	t_token token;

	NULL_GUARD((token = (t_token)ft_memalloc(sizeof(struct s_token))));
	token->type = type;
	token->flags = flags;
	token->data = data;
	token->len = ft_strlen(text);
	CA((type), token->symbol,  *(text + (token->len - 1)), '\0');
	return (token);
}

t_token	new_dumb_token(char *text)
{
	return (new_token(0, NULL, ft_strdup(text), (void*)text));
}

t_token	extract_token(const char *fmt)
{
	t_flags	flags;
	int		type;
	char	*pos;

	NULL_GUARD(fmt);
	flags = parse_flags(fmt);
	type = parse_type(fmt);
	pos = (char*)fmt;
	while (!is_type(pos))
		pos++;
	return (new_token(type, flags, ft_strsub(fmt, 0, (pos - fmt) + 1), NULL));
}

t_token	extract_text_token(const char *fmt)
{
	char	*pos;

	pos = (char*)fmt;
	while (*pos && !is_token(pos))
		pos++;
	if (pos - fmt)
		return (new_dumb_token(ft_strsub(fmt, 0, pos - fmt)));
	return (NULL);
}

int		parse_type(const char *fmt)
{
	while (!is_type((char*)fmt))
		fmt++;
	if (!*fmt)
		return (0);
	return (is_type((char*)fmt));
}
