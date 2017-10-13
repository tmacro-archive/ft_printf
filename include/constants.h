#ifndef CONSTANTS_H
# define CONSTANTS_H
# include <stdint.h>
# include "ft_printf.h"
# define PFT_STR	1
# define PFT_WSTR	2
# define PFT_PTR	3
# define PFT_INT	4
# define PFT_SINT	5
# define PFT_LINT	6
# define PFT_LLINT	7
# define PFT_MXINT  8
# define PFT_UINT	9
# define PFT_USINT	10
# define PFT_ULINT	11
# define PFT_ULLINT 12
# define PFT_UMXINT 13
# define PFT_CHAR	14
# define PFT_WCHAR	15
# define PFT_UCHAR  16
# define PFT_SIZET  17

# define PFW_H 1
# define PFW_L 2
# define PFW_LL 3
# define PFW_J 4
# define PFW_Z 5
# define PFW_HH 6

# define XARG(pft_type, x) XARG_##pft_type(x)
# define XARG_int(x) wrap_int(va_arg(x, intmax_t))
# define XARG_uint(x) wrap_uint(va_arg(x, uintmax_t))
# define XARG_char(x) wrap_char((char)va_arg(x, int))
# define XARG_wchar(x) wrap_wchar((char)va_arg(x, int))
# define XARG_void(x) va_arg(x, void*)
# define XARG_str(x) va_arg(x, char*)
# define XARG_wstr(x) va_arg(x, char*)

# define AS(type, x) AS_##type(x)
# define AS_int(x) *(int*)(x)
# define AS_sint(x) *(short int*)(x)
# define AS_lint(x) *(long int*)(x)
# define AS_llint(x) *(long long int*)(x)
# define AS_mxint(x) *(intmax_t*)(x)
# define AS_uint(x) *(unsigned int*)(x)
# define AS_usint(x) *(unsigned short int*)(x)
# define AS_ulint(x) *(unsigned long int*)(x)
# define AS_ullint(x) *(unsigned long long int*)(x)
# define AS_umxint(x) *(uintmax_t*)(x)
# define AS_uchar(x) *(unsigned char*)(x)
#endif