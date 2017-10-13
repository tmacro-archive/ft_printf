/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:09:51 by tmckinno          #+#    #+#             */
/*   Updated: 2017/10/07 15:21:53 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "constants.h"

t_token	parse_format(char *fmt)
{
	t_token	tok;

	ERR_CNR(*fmt, '\0', NULL);
	if (!is_token((char*)fmt))
		tok = extract_text_token(fmt);
	else
		tok = extract_token(fmt);
	NULL_GUARD(tok);
	if (tok->type)
		tok->width = is_width(tok->type, tok->flags->lmod);
	else
		tok->width = 0;
	fmt = fmt + tok->len;
	if (fmt)
		tok->next = parse_format(fmt);
	return (tok);
}

void	parse_args(t_token token, va_list args)
{
	NULL_GUARD_NR(token);
	if (is_int_type(token->type))
		token->data = XARG(int, args);
	else if (is_char_type(token->type))
		token->data = XARG(char, args);
	else if (is_uint_type(token->type))
		token->data = XARG(uint, args);
	else if (is_wchar_type(token->type))
		token->data = XARG(wchar, args);
	else if (is_str_type(token->type))
		token->data = XARG(str, args);
	else if (is_wstr_type(token->type))
		token->data = XARG(wstr, args);
	else if (token->type)
		token->data = XARG(void, args);
	parse_args(token->next, args);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	t_token tokens;
	int		written;

	tokens = parse_format((char*)format);
	va_start(args, format);
	parse_args(tokens, args);
	written = 0;
	while (tokens)
	{
		written += render_token(tokens);
		tokens = tokens->next;
	}
	return (written);
}
