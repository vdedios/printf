/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:15:51 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/13 11:39:22 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define LONG_MASK 0xF000000000000000

#ifndef PRINTF_H
# define PRINTF_H

/*
** main functions
*/
int						ft_printf(const char *s, ...);
char					*ft_extract_format(const char *s);

/*
** main utils functions
*/
char					*ft_string_to_char(char *s);

/*
** type conversion functions
*/
char 					*ft_c_conv(char *format_info, va_list args);
char					*ft_s_conv(char *format_info, va_list args);
char					*ft_p_conv(char *format_info, va_list args);
char					*ft_di_conv(char *format_info, va_list args);
char					*ft_u_conv(char *format_info, va_list args);
char					*ft_xX_conv(char *format_info, va_list args, int i);
char					*ft_floatpoint_conv(char *format_info, va_list args, int i);
/*
char	*ft_n_conv(char *format_info, va_list args);
*/

/*
** type conversion utils functions
*/
void					ft_print_hex(char *hex, long long int num, char uplow);
double					ft_ten_power(int p);
int                     ft_count_figures(long long int num);
char					*ft_float_str(float num, int precision);
char    				*ft_exp_str(double num, int *exp, int precision);
unsigned long long		ft_get_integer(double num, char type);
char					*ft_get_decimals(double num, int *exp, int precision);
char					*ft_trim_f_zeros(char *num);
char					*ft_trim_e_zeros(char *num);
char					*ft_g_conv(double num, int *exp, int precision);

#endif
