/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:07:32 by bduron            #+#    #+#             */
/*   Updated: 2016/12/14 18:11:09 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

int  ft_printf(const char *format, ...)
{
	t_flags f;

	f.plen = 0;
	va_start(f.ap, format);
	fmt(&f, format);
	va_end(f.ap);
	return (f.plen);
}

void fmt(t_flags *f, const char *format)
{
	char *s = (char *)format;

	reset_flags(f);
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar(*s);
			f->plen++;
		}
		else
		{
			s = get_flags(s, f);
			launch_conv(f);
			reset_flags(f);
		}
		s++;
	}
}

char *get_flags(char *s, t_flags *f)
{
	s++;
	while (is_flag(*s))
		f->flags[(int)*s++]++;
	if (ft_isdigit(*s))
		f->width = ft_atoi((const char*)s);
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
	{
		f->precision = ft_atoi((const char*)++s);
		f->flags['.']++;
	}
	while (ft_isdigit(*s))
		s++;
	while (is_mod(*s))
	{
		*s == *(s + 1) ? f->mod[(int)ft_toupper(*s++)]++ : f->mod[(int)*s++]++;
		*s == *(s - 1) ? s++ : 0;
	}
	if (is_id(*s))
		f->id = *s;
	else
		exit(-1); /* si !id (ex: % ou @ ou Y) mettre en place la regle %% */
	return (s);
}

int is_flag(char c)
{
	if (c == '0')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '-')
		return (1);
	if (c == '#')
		return (1);
	if (c == '+')
		return (1);
	if (c == '\'')
		return (1);
	return (0);
}

int is_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int is_id(char id)
{
	if (id == 's' || id == 'S')
		return (1);
	if (id == 'd' || id == 'D')
		return (1);
	if (id == 'o' || id == 'O')
		return (1);
	if (id == 'u' || id == 'U')
		return (1);
	if (id == 'x' || id == 'X')
		return (1);
	if (id == 'c' || id == 'C')
		return (1);
	if (id == 'p' || id == 'i')
		return (1);
	if (id == '%' || ft_isalpha(id))
		return (1);
	return (0);
}

void reset_flags(t_flags *f)
{
	ft_memset(f->flags, 0, sizeof(int) * 256);
	ft_memset(f->mod, 0, sizeof(int) * 256);
	ft_memset(f->str, 0, 256);
	f->width = 0; /* pas indispensable */
	f->precision = -1;
	f->sign = 0;
	f->s_bool = 0;
	f->h_bool = 0;
}

int count_digits(int nb)
{
	int len;

	len = (nb == 0) ? 1 : 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int max(int x, int y, int z)
{
	int max;

	max = (x >= y) ? x : y;
	max = (max >= z) ? max : z;
	return (max);
}

int is_x(t_flags *f)
{
	return (f->id == 'x' || f->id == 'X' ? 1 : 0);
}

int pad(int len, char c)
{
	int i;

	i = 0;
	while (len)
	{
		ft_putchar(c);
		i++;
		len--;
	}
	return (0);
}

void launch_conv(t_flags *f)
{
	(f->id == 'd' || f->id == 'i' || f->id == 'o' || is_x(f)) ? conv_d(f) : 0;
	(f->id == 'c' || f->id == 'C') ? put_c(f) : 0 ;
	if (f->id == 'p')
	{	
		f->id = 'x';
		f->flags['#'] = 1;
		f->flags['p'] = 1;
		f->mod['l'] = 1;
		conv_d(f);
	}
	f->id == '%' ? conv_d(f) : 0;
}

long long  get_arg(t_flags *f)
{
	if (f->mod['z'])
		return (va_arg(f->ap, size_t));
	if (f->mod['j'])
		return (va_arg(f->ap, intmax_t));
	if (f->mod['L'])
		return (va_arg(f->ap, long long));
	if (f->mod['l'])
		return (va_arg(f->ap, long));
	if (f->mod['h'])
		return ((short)va_arg(f->ap, int));
	if (f->mod['H'])
		return ((signed char)va_arg(f->ap, int));

	return (va_arg(f->ap, int));
}

long long  get_arg_u(t_flags *f)
{
	if (f->mod['z'])
		return (va_arg(f->ap, size_t));
	if (f->mod['j'])
		return (va_arg(f->ap, uintmax_t));
	if (f->mod['L'])
		return (va_arg(f->ap, unsigned long long));
	if (f->mod['l'])
		return (va_arg(f->ap, unsigned long));
	if (f->mod['h'])
		return ((unsigned short)va_arg(f->ap, unsigned int));
	if (f->mod['H'])
		return ((unsigned char)va_arg(f->ap, unsigned int));

	return (va_arg(f->ap, unsigned int));
  }

char *itob(t_flags *f, unsigned long long n)
{
	char *p;

	p = &f->str[255];
	if (f->id == 'o')
	{
		*--p = (n & 0x7) + '0';
		while (n >>= 3)
			*--p = (n & 0x7) + '0';
		if ((f->flags['#'] && *p != '0') && (f->precision < (int)ft_strlen(p)))
			*--p = '0';
		return (p);
	}
	if (is_x(f))
	{
		*--p = (f->id == 'x') ? HEX_L[n & 0xf] : HEX_U[n & 0xf];
		while (n >>= 4)
			*--p = (f->id == 'x') ? HEX_L[n & 0xf] : HEX_U[n & 0xf];
		return (p);
	}
		*--p = n % 10 + '0';
		while (n /= 10)
			*--p = n % 10 + '0';
		return (p);
}

void conv_d(t_flags *f)
{
	char *s;
	long long nb;
	unsigned long m;

	nb = (f->id == 'd' || f->id == 'i') ? get_arg(f) : get_arg_u(f);
	//if (nb == 0 && f->precision == 0)
	//{
	//	f->plen += max(f->width, f->precision + f->s_bool, 0);
	//	//return;
	//}
	if (nb < 0 && f->id != 'o' && !is_x(f))
		f->sign = '-';
	else if (f->flags['+'] && f->id != 'o' && !is_x(f))
		f->sign = '+';
	else if (f->flags[' '])
		f->sign = ' ';
	f->s_bool = (f->sign) ? 1 : 0;
	if (f->flags['.'])
		f->flags['0'] = 0;
	m = (nb > 0) ? nb : -nb;
	s = (is_x(f) || f->id == 'o') ? itob(f, nb) : itob(f, m);
	s = (nb == 0 && f->precision == 0) ? "" : s;
	f->h_bool = (f->flags['#'] && *s != '0' && *s && is_x(f)) ? 2 : 0;
	put_d(f, s, ft_strlen(s) + f->s_bool + f->h_bool); // + s_bool to check (size)
}



void put_d(t_flags *f, char *s, int len)
{
	int n;

	n = (f->precision > len - f->s_bool) ? f->precision : len - f->s_bool;
	(f->sign && f->flags['0']) ? ft_putchar(f->sign) : 0;
//	if (f->width > n && !f->flags['-'])
//		(f->flags['0']) ? pad(f->width - n - f->s_bool, '0') : pad(f->width - n - f->s_bool, ' ');
	if (f->width > n && !f->flags['-'] && !f->flags['0'])
		pad(f->width - n - f->s_bool /*- f->h_bool*/, ' ');
	if (f->flags['#'] && is_x(f) && ((*s != '0' && *s) || f->flags['p']))
	{
		ft_putchar('0');
		(f->id == 'x') ? ft_putchar('x') : ft_putchar('X');
	}
	if (f->width > n && !f->flags['-'] && f->flags['0'])
		pad(f->width - n - f->s_bool, '0');
	(f->sign && !f->flags['0']) ? ft_putchar(f->sign) : 0;
	if (f->precision > len - f->s_bool - f->h_bool)
		pad(f->precision - len + f->s_bool + f->h_bool, '0');
	ft_putstr(s);
	(f->width > n && f->flags['-']) ? pad(f->width - n - f->s_bool, ' ') : 0;
	f->plen += max(f->width, f->precision + f->s_bool + f->h_bool, len);
}

void put_c(t_flags *f)
{
	unsigned char c;

	c = get_arg_u(f);
	ft_putchar(c);
}
