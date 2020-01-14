/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:16:12 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/14 13:49:51 by vde-dios         ###   ########.fr       */
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
	double				num;
	int					exp;
	int 				precision;
	unsigned long long	aux;

	exp = 0;
	precision = 6;
	num = va_arg(args, double);
	aux = *((unsigned long long int *)&num);
	if (aux >= INF && aux < NAN)
		return (ft_strjoin_none("inf", 0));
	else if (aux >= NAN && aux < MINF)
		return (ft_strjoin_none("nan", 0));
	else if (aux >= MINF)
		return (ft_strjoin_none("-inf", 0));
	if (format_info[i] == 'f' || format_info[i] == 'F')
		return (ft_float_str(num, precision));
	else if (format_info[i] == 'e' || format_info[i] == 'E')
		return (ft_exp_str(num, &exp, precision, format_info[i]));
	else if (format_info[i] == 'g' || format_info[i] == 'G')
		return (ft_g_conv(num, &exp, precision, format_info[i]));
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
