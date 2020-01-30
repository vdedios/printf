/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_cspdiu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:16:13 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/30 14:52:34 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** <<c>> type conversion
*/

char	*ft_c_conv(t_format *format, va_list args, int pos)
{
	char	*aux;
	int		*pos_zero;

	(void)format;
	if (!(aux = malloc(2 * sizeof(char))))
		return (NULL);
	*aux = va_arg(args, int);
	*(aux + 1) = '\0';
	if (*aux == '\0')
	{
		if (!(pos_zero = malloc(2 * sizeof(int))))
			return (NULL);
		*aux = 1;
		pos_zero[0] = pos;
		format->last_pos = pos;
		pos_zero[1] = -1;
		format->print_l = ft_intjoin(format->print_l, pos_zero);
	}
	return (aux);
}

/*
** <<s>> type conversion
*/

char	*ft_s_conv(t_format format, va_list args)
{
	char	*aux;

	(void)format;
	aux = va_arg(args, char *);
	if (aux)
		aux = ft_strjoin_none(aux, NULL);
	else
		aux = ft_strjoin_none("(null)", NULL);
	if (format.precision != -1)
		return (ft_precision(format, aux));
	return (aux);
}

/*
** <<p>> type conversion
*/

char	*ft_p_conv(t_format format, va_list args)
{
	long int	dir;
	long int	aux;
	int			size;
	char		*hex;

	(void)format;
	size = 0;
	dir = (long int)va_arg(args, char *);
	aux = dir;
	while (aux)
	{
		aux = aux / 10;
		size++;
	}
	if (!(hex = malloc(size * sizeof(char))))
		return (NULL);
	if (format.precision != -1 && dir == 0)
		return (ft_strjoin_second("0x", ft_precision(format, hex)));
	ft_print_hex(hex, dir, 'x');
	hex = ft_strjoin_second("0x", hex);
	return (hex);
}

/*
** <<d/i>> type conversion
*/

char	*ft_di_conv(t_format format, va_list args)
{
	long long int		num;

	(void)format;
	if (format.length == 'l')
		num = va_arg(args, long int);
	else if (format.length == 'L')
		num = va_arg(args, long long int);
	else
		num = va_arg(args, int);
	if (format.precision)
		return (ft_precision(format, ft_itoa(num)));
	else if (!format.precision && !num)
		return (ft_strjoin_none(NULL, NULL));
	return (ft_itoa(num));
}

/*
** <<u>> type conversion
*/

char	*ft_u_conv(t_format format, va_list args)
{
	long long int	num;

	(void)format;
	if (format.length == 'l')
		num = va_arg(args, long int);
	else if (format.length == 'L')
		num = va_arg(args, long long int);
	else
		num = va_arg(args, int);
	if (num < 0)
		num = num + 4294967296;
	if (format.precision)
		return (ft_precision(format, ft_itoa(num)));
	else if (!format.precision && !num)
		return (ft_strjoin_none(NULL, NULL));
	return (ft_itoa(num));
}