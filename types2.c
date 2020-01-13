/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:16:12 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/13 15:28:51 by vde-dios         ###   ########.fr       */
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
** <<f>> <<e>> <<g>> type conversion
*/
char	*ft_floatpoint_conv(char *format_info, va_list args, int i)
{
	double	num;
	int		exp;
	int 	precision;

	exp = 0;
	precision = 6;
	num = va_arg(args, double);
	if (format_info[i] == 'f')
		return (ft_float_str(num, precision));
	else if (format_info[i] == 'e')
		return (ft_exp_str(num, &exp, precision));
	else if (format_info[i] == 'g')
		return (ft_g_conv(num, &exp, precision));
	return (0);
}

void	ft_n_conv(char *format_info, va_list args, char *printf_buf)
{
	long int	dir;
	int			*num;
	(void)format_info;

	dir = (long int)va_arg(args, int *);
	//dir = (long int)va_arg(args, char *);
	num = (int *)dir;
	*num = (int)ft_strlen(printf_buf);
}
