/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:16:12 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/05 16:50:02 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/*
** <<xX>> type conversion
*/
char	*ft_xX_conv(char *format_info, va_list args, int i)
{
	long int	num;
	long int	aux;
	int 		size;
	char		*hex;
	(void)format_info;

	size = 0;
	num = va_arg(args, long int);
	aux = num;
	while (aux)
	{
		aux = aux / 10;
		size++;
	}
	if (!(hex = malloc(size * sizeof(char))))
		return (NULL);
	if (format_info[i] == 'x')
		ft_convert_hex(hex, num, 0);
	else 
		ft_convert_hex(hex, num, 1);
	ft_str_rev(hex);
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
char	*ft_e_conv(char *format_info, va_list args);
char	*ft_g_conv(char *format_info, va_list args);
char	*ft_n_conv(char *format_info, va_list args);
*/
