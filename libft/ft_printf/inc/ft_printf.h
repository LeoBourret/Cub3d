/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:11:19 by lebourre          #+#    #+#             */
/*   Updated: 2021/05/28 15:22:47 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
	int				hash;
	int				space;
	int				plus;
}					t_flags;

int					find_size(long int nb);
int					ft_printf(const char *format, ...);
t_flags				ft_init_flags(void);
int					ft_putchar_ret(char c);
int					ft_putstr_ret(char *s);
int					ft_putstr_prec(char *s, int n);
int					ft_parser(const char *s, int n, t_flags *f, va_list lst);
int					ft_manage_type(int c, va_list list, t_flags flags, int p);
int					ft_print_width(int width, int len, int zero);
int					ft_print_int(char *s, t_flags flags, long n, int len);
int					ft_manage_hex(unsigned int n, t_flags flags, int lower);
int					ft_manage_char(char c, t_flags flags);
int					ft_manage_str(char *s, t_flags flags);
int					ft_manage_int(int n, t_flags flags);
int					ft_manage_uint(unsigned int n, t_flags flags);
int					ft_manage_percent(t_flags flags);
int					ft_manage_addr(unsigned long long addr, t_flags flags);
int					ft_parser(const char *s, int i, t_flags *f, va_list list);
long				ft_abs(long n);
int					ft_nblen(long n);
int					ft_strlen(char *s);
int					ft_isdigit(int c);
int					ft_istype(int c);
int					ft_isflag(int c);
int					ft_flag_dot(const char *s, int i, t_flags *f, va_list lst);
void				ft_flag_digit(char c, t_flags *flags);
void				ft_flag_minus(t_flags *flags);
void				ft_flag_width(t_flags *flags, va_list args);
char				*ft_strdup(char *s);
char				*ft_strcat(char *dst, char *src);
char				*ft_realloc(char *s, int n);
char				*ft_itoa_pft(long n);
char				*ft_itoa_hex(long n);
char				*ft_set_strlower(char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_addr_to_char(char *s);
char				*ft_tolower(char *s);

#endif
