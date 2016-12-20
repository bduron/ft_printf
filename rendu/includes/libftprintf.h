/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:42:08 by bduron            #+#    #+#             */
/*   Updated: 2016/12/20 15:50:07 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_LIBFTPRINTF_H
# define H_LIBFTPRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFSIZE 4096
# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct s_flags
{
	int flags[256];
	int mod[256];
	char str[256];
	int width;
	int precision;
	va_list ap;
	size_t plen;
	char id;

	char sign;
	int s_bool;
	int h_bool;
}				t_flags;

int ft_printf(const char *format, ...);
void fmt(t_flags *f, const char *format);
char * get_flags(char *flag, t_flags *f);
int is_flag(char c);
int is_id(char id);
void reset_flags(t_flags *f);
int is_mod(char c);
void launch_conv(t_flags *f);
void conv_d(t_flags *f);
void put_d(t_flags *f, char *s, int len);
int count_digits(int nb);
int max(int x, int y, int z);
long long  get_arg_u(t_flags *f);
long long  get_arg(t_flags *f);
void conv_d(t_flags *f);
int is_x(t_flags *f);
void put_c(t_flags *f);
void put_s(t_flags *f);
void put_s_maj(t_flags *f);


void			ft_putchar(char c);
void			ft_putstr(char const *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
void			ft_strdel(char **as);
char			*ft_itoa(uintmax_t n);
void			*ft_memset(void *b, int c, size_t len);

#endif
