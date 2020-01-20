/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_cspdiu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:16:13 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/20 10:57:08 by vde-dios         ###   ########.fr       */
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

	if (!(aux = malloc(sizeof(char))))
		return (NULL);
	//1º gestión de error
	//2º conversión de tipo
	*aux = va_arg(args, int);
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

	//1º gestión de error
	//2º conversión de tipo
	aux = va_arg(args, char *);
	l = ft_strlen(aux);
	if (!(aux2 = malloc(l * sizeof(char) + 1)))
		return (NULL);
	while (*aux)
		*aux2++ = *aux++;
	*aux2 = '\0';
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
	int		num;
	(void)format;

	//1º gestión de error
	//2º conversión de tipo
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
	long int	num;
	(void)format;

	//1º gestión de error
	//2º conversión de tipo
	num = va_arg(args, int);
	if (num < 0)	
		num = num + 4294967296;
	if (format.precision)
		return (ft_precision(format, ft_itoa(num)));
	return (ft_itoa(num));
}
