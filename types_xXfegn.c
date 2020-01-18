/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_xXfegn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:16:41 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/18 17:18:16 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** <<xX>> type conversion
*/
char	*ft_xX_conv(t_format format, va_list args, int i)
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
	ft_print_hex(hex, num, format.type);
	return (hex);
}

/*
** <<f>> <<e>> <<g>> type conversion
*/
char	*ft_floatpoint_conv(t_format format, va_list args, int i)
{
	double				num;
	int					exp;
	unsigned long long	aux;

	exp = 0;
	num = va_arg(args, double);
	aux = *((unsigned long long int *)&num);
	if (aux >= INF && aux < NAN)
		return (ft_strjoin_none("inf", 0));
	else if (aux >= NAN && aux < MINF)
		return (ft_strjoin_none("nan", 0));
	else if (aux >= MINF)
		return (ft_strjoin_none("-inf", 0));
	if (format.type == 'f' || format.type == 'F')
		return (ft_float_str(num, format));
	else if (format.type == 'e' || format.type == 'E')
		return (ft_exp_str(num, &exp, format));
	else if (format.type == 'g' || format.type == 'G')
		return (ft_g_conv(num, &exp, format));
	return (0);
}

void	ft_n_conv(t_format format, va_list args, char *printf_buf)
{
	long int	dir;
	int			*num;
	(void)format;

	dir = (long int)va_arg(args, int *);
	//dir = (long int)va_arg(args, char *);
	num = (int *)dir;
	*num = (int)ft_strlen(printf_buf);
}
