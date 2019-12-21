/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:15:51 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/21 19:41:01 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PRINTF_H
# define PRINTF_H
//METER PROTOTIPOS DE FUNCIONES QUE FALTAN!!
int		ft_printf(const char *s, ...);
char	*ft_extract_format(const char *s);
char	*ft_string_to_char(char *s);
char 	*ft_c_conv(char *format_info, va_list args);
char	*ft_s_conv(char *format_info, va_list args);
/*
char	*ft_p_conv(char *format_info, va_list args);
char	*ft_di_conv(char *format_info, va_list args);
char	*ft_u_conv(char *format_info, va_list args);
char	*ft_xX_conv(char *format_info, va_list args);
char	*ft_n_conv(char *format_info, va_list args);
char	*ft_f_conv(char *format_info, va_list args);
char	*ft_e_conv(char *format_info, va_list args);
char	*ft_g_conv(char *format_info, va_list args);
*/
#endif
