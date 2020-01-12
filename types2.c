/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:16:12 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/12 17:07:45 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/*
** <<xX>> type conversion
*/
char	*ft_xX_conv(char *format_info, va_list args, int i)
{
	long int	num;
	int 		s;
	int 		aux;
	char		*hex;

	s = 0;
	aux = 0;
	num = va_arg(args, long int);
	while (aux)
	{
		aux = aux / 10;
		s++;
	}
	if (!(hex = malloc(s * sizeof(char))))
		return (NULL);
	ft_print_hex(hex, num, format_info[i]);
	return (hex);
}

/*
** <<f>> type conversion
*/
char	*ft_f_conv(char *format_info, va_list args)
{
	char	*f_str;
	float	num;
	(void)format_info;

	num = (float)va_arg(args, double);
	f_str = ft_float_str(num);
	return (f_str);
}

/*
** <<e>> type conversion
*/
char	*ft_e_conv(char *format_info, va_list args)
{
	char	*f_str;
	float	num;
	(void)format_info;

	num = (float)va_arg(args, double);
	f_str = ft_exp_str(num);
	return (f_str);
}

/*
char	*ft_g_conv(char *format_info, va_list args);
char	*ft_n_conv(char *format_info, va_list args);
*/
