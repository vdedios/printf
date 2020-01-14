/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:15:51 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/14 15:32:52 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define LONG_MASK 0xF000000000000000
#define INF 0x7FF0000000000000
#define MINF 0xFFF0000000000000
#define NAN 0x7FF8000000000000

#ifndef PRINTF_H
# define PRINTF_H

/*
** printf.c
*/
char					*ft_extract_format(const char *s);
char					*ft_analyse(char *format_info,
							va_list args, char *printf_buf);
char					*ft_formater(const char **s,
							char **print_buf, va_list args);
int						ft_printf(const char *s, ...);


/*
** types_cspdiu.c
*/
char					*ft_c_conv(char *format_info, va_list args);
char					*ft_s_conv(char *format_info, va_list args);
char					*ft_p_conv(char *format_info, va_list args);
char					*ft_di_conv(char *format_info, va_list args);
char					*ft_u_conv(char *format_info, va_list args);


/*
** types_xXfegn.c
*/
char					*ft_xX_conv(char *format_info, va_list args, int i);
char					*ft_floatpoint_conv(char *format_info, va_list args, int i);
void					ft_n_conv(char *format_info, va_list args, char *printf_buf);

/*
** utils_e.c
*/
int						ft_count_figures(long long int num);
unsigned long long		ft_get_integer(double num, char type);
char					*ft_get_decimals(double num, int *exp, int precision, char type);
char    				*ft_exp_str(double num, int *exp, int precision, char type);

/*
** utils_e.c
*/
double					ft_ten_power(int p);
unsigned long long		ft_rounding(unsigned long long i_num,
							unsigned long long f_num, float num, int precision);
char					*ft_add_zeroes(char *f_str, int precision);
char					*ft_float_str(float num, int precision);

/*
** utils_e.c
*/
char					*ft_trim_f_zeros(char *num);
char					*ft_trim_e_zeros(char *num);
char					*ft_g_conv(double num, int *exp, int precision, char type);

/*
** printf_utils.c
*/
char					*ft_string_to_char(char *s);

/*
** utils_xXp.c
*/
void					ft_print_hex(char *hex, long long int num, char uplow);

#endif
