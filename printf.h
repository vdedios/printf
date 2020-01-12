/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:15:51 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/12 17:11:45 by vde-dios         ###   ########.fr       */
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
char					*ft_f_conv(char *format_info, va_list args);
char					*ft_e_conv(char *format_info, va_list args);
/*
char	*ft_g_conv(char *format_info, va_list args);
char	*ft_n_conv(char *format_info, va_list args);
*/

/*
** type conversion utils functions
*/
void					ft_print_hex(char *hex, long long int num, char uplow);
double					ft_ten_power(int p);
int                     ft_count_figures(long long int num);
char					*ft_float_str(float num);
char    				*ft_exp_str(float num);

#endif
