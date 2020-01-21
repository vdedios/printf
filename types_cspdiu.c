/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_cspdiu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:16:13 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/21 19:27:34 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** <<c>> type conversion
*/
char	*ft_c_conv(t_format format, va_list args)
{
	char *aux;
	(void)format;

	if (!(aux = malloc(2 * sizeof(char))))
		return (NULL);
	*aux = va_arg(args, int);
	*(aux + 1) = '\0';
	if (*aux == '\0')
	{
		*aux = 1;
	}
	return (aux);
}

/*
** <<s>> type conversion
*/
char	*ft_s_conv(t_format format, va_list args)
{
	char	*aux;
	char	*aux2;
	int		l;
	(void)format;

	aux = va_arg(args, char *);
	l = ft_strlen(aux);
	if (!(aux2 = malloc(l * sizeof(char) + 1)))
		return (NULL);
	while (*aux)
		*aux2++ = *aux++;
	*aux2 = '\0';
	if (format.precision)
		return (ft_precision(format, aux2 - l));
	return (aux2 - l);
}

/*
** <<p>> type conversion
*/
char	*ft_p_conv(t_format format, va_list args)
{
	long int	dir;
	long int	aux;
	int 		size;
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
	ft_print_hex(hex, dir, 'x');
	hex = ft_strjoin_second("0x", hex);
	return (hex);
}

/*
** <<d/i>> type conversion
*/
char	*ft_di_conv(t_format format, va_list args)
{
	long long	int		num;
	(void)format;

	//1º gestión de error
	//2º conversión de tipo
	if (format.length == 'l')
		num = va_arg(args, long int);
	else if (format.length == 'L')
		num = va_arg(args, long long int);
	else
		num = va_arg(args, int);
	if (format.precision)
		return (ft_precision(format, ft_itoa(num)));
	return (ft_itoa(num));
}

/*
** <<u>> type conversion
*/
char	*ft_u_conv(t_format format, va_list args)
{
	long long int	num;
	(void)format;

	//1º gestión de error
	//2º conversión de tipo
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
	return (ft_itoa(num));
}
