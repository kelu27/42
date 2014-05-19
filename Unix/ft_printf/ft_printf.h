/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 14:59:21 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/22 20:53:53 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

int			ft_printf(const char *format, ...);
int			ft_check_arg(const char **format, va_list args, int ret);
void		ft_putnbr(int n);
void		ft_putnbr_ld(long int);
int			ft_nsize(int n);
int			ft_nsize_ld(long int);
void		ft_putchar(char c);
size_t		ft_strlen(const char *s);
void		ft_putstr(char const *str);
int			ft_argd(const char *format, va_list args, int ret);
int			ft_argc(const char *format, va_list args, int ret);
int			ft_args(const char *format, va_list args, int ret);
int			ft_argld(const char *format, va_list args, int ret);
int			ft_isdigit(char c);
int			ft_check_num(const char **format, va_list args, va_list argss, int ret);
int			ft_atoi(const char *str);
void		ft_putnbr_ui(unsigned int n);
int			ft_nsize_ui(unsigned int n);
void		ft_putnbr_ul(unsigned long int n);
int			ft_nsize_ul(unsigned long int n);
char		*ft_dec_to_oct(unsigned int n);
char		*ft_dec_to_hex(const char **format, unsigned int n);
int			ft_nsize_hex(unsigned int n);
int			ft_printf_x(va_list args, int ret);
void		*ft_strnew(size_t size);
int			ft_nsize_oct(unsigned int n);
char		*ft_dec_to_oct_ul(unsigned long int n);
int			ft_nsize_oct_ul(unsigned long int n);
char		*ft_dec_to_hex_ul(const char **format, unsigned long n);
int			ft_nsize_hex_ul(unsigned long n);
int			ft_check_arg_o(const char **format, va_list args, int ret);
int			ft_check_diez(const char **format, va_list args, int ret);
int			ft_putchar_ret(char c, int ret);

#endif	/* !FT_PRINTF_H */
