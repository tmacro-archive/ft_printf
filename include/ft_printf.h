/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:19:37 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/15 14:10:36 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "constants.h"

# define NULL_GUARD(val)  if (val == NULL) return NULL
# define NULL_GUARD_NR(val) if (val == NULL) return
# define ERR_CHECK(val, err) if (val == err) return NULL
# define ERR_CNR(val, err, ret) if (val == err) return (ret)
# define ERR_NR(val, err) if (val == err) return

# define BREAK(val, err) if (val == err) break
# define IF_RET(val, ret) if (val) return (ret)
# define IF(bool, true) if ((bool)) { true; }
# define IFTR(bool, true, ret) if ((bool)) { true; return (ret);}
# define IFE(bool, true, false) if ((bool)) { true; } else { false ;}
# define CA(bool, var, true, false) if ((bool)) { var = true; } else { var = false; }

# define SET_FLAG(flags, key) (flags->key |= 1)
# define CLR_FLAG(token, key) ((token->flags)->key &= ~1)
# define TOG_FLAG(token, key) ((token->flags)->key ^= 1)
# define GET_FLAG(token, key) ((token->flags)->key & 1)

typedef  struct					s_segment
{
	void						*handler;
	char						*flags;
	size_t						len;
}								t_segment;

struct							s_flags
{
	int							alt:1;
	int							zpad:1;
	int							ladj:1;
	int							sign:1;
	int							spc:1;
	size_t						fwidth;
	int							precision;
	int							lmod;
};

typedef struct s_flags			*t_flags;

struct							s_token
{
	int							type;
	int							width;
	t_flags						flags;
	void						*data;
	char						*text;
	char						symbol;
	size_t						len;
	struct s_token				*next;
};

typedef struct s_token			*t_token;

typedef short int				sint;
typedef long int				lint;
typedef long long int			llint;
typedef unsigned int			uint;
typedef short unsigned int		usint;
typedef long unsigned int		ulint;
typedef long long unsigned int	ullint;
typedef unsigned char			uchar;

int								ft_printf( const char * format, ... );
void							*ft_memalloc(size_t size);
void							ft_memfree(void **ptr);
void							*ft_memset(void *s, int c, size_t n);
void							ft_memcpy(void *dest, void *src, size_t size);
size_t							ft_strlen(char *s);
char							*ft_strnew(size_t len);
char							*ft_strsub(char const *s, unsigned int start , size_t len);
char							*ft_strsub_p(char *start, char *end);
char							*ft_strncpy(char *s1, const char *s2, size_t n);
char							*ft_strjoin(char *s1, char *s2);
char							*ft_strdup(char *s);
char							*rpad(char *s, size_t width, char c);
char							*lpad(char *s, size_t width, char c);
char							*lpad_int(char *s, size_t width, char c);
char							*ft_itoa(intmax_t num);
int								ft_atoi(char const *s);
char							*ft_uitoa(uintmax_t num);
uintmax_t						ft_itoo(uintmax_t in);
int								count_digits(intmax_t num);
t_flags 						parse_flags(const char *token);
int								parse_type(const char *fmt);
int								type_to_const(char c);
t_token							extract_token(const char *fmt);
t_token							extract_text_token(const char *fmt);
int								is_type(char *c);
int								is_token(char *s);
int								is_lmod(char *s);
int								is_flag(char *c);
int								is_int_type(int type);
int								is_width(int t, int l);
int								is_num(char c);
int								is_uint_type(int type);
int								is_char_type(int type);
int								is_wchar_type(int type);
int								is_str_type(int type);
int								is_wstr_type(int type);
int								f_print(char *c);
int								render_token(t_token token);
int								render_string(t_token token);
int								render_integer(t_token token);
int								render_uinteger(t_token token);
int	    						render_octal(t_token token);
void							*wrap_int(intmax_t arg);
void							*wrap_uint(uintmax_t arg);
void							*wrap_char(char arg);
void							*wrap_wchar(char arg);
char							*ft_itoh(uintmax_t in, int cse);
int								render_hex(t_token token);

#endif