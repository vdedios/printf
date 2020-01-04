/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:16:12 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/04 21:38:45 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/*
** <<xX>> type conversion
*/
char	*ft_xX_conv(char *format_info, va_list args, int i)
{
	int		num;
	int		aux;
	int 	size;
	char	*hex;
	(void)format_info;

	size = 0;
	num = (int)va_arg(args, int);
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
char	*ft_n_conv(char *format_info, va_list args);
char	*ft_f_conv(char *format_info, va_list args);
char	*ft_e_conv(char *format_info, va_list args);
char	*ft_g_conv(char *format_info, va_list args);
*/
