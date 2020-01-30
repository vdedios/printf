/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_hexfegn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:54:59 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/23 15:52:41 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** <<xX>> type conversion
*/

long long	ft_hex_values(t_format format, va_list args)
{
	long long int	num;

	if (format.length == 'l')
		num = va_arg(args, long int);
	else if (format.length == 'L')
		num = va_arg(args, long long int);
	else
		num = va_arg(args, unsigned int);
	return (num);
}

char		*ft_hex_conv(t_format format, va_list args)
{
	long long int	num;
	int				s;
	int				aux;
	char			*hex;

	s = 0;
	aux = 0;
	num = ft_hex_values(format, args);
	while (aux)
	{
		aux = aux / 10;
		s++;
	}
	if (!(hex = malloc(s * sizeof(char))))
		return (NULL);
	ft_print_hex(hex, num, format.type);
	if (format.precision)
		return (ft_precision(format, hex));
	else if (!format.precision && !num)
		return (ft_strjoin_none(NULL, NULL));
	return (hex);
}

/*
** <<f>> <<e>> <<g>> type conversion
*/

static char	*ft_check_specials(double num)
{
	unsigned long long	aux;

	aux = *((unsigned long long int *)&num);
	if (aux >= INF && aux < NAN)
		return (ft_strjoin_none("inf", 0));
	else if ((aux >= NAN && aux < NEGS) || aux > MINF)
		return (ft_strjoin_none("nan", 0));
	else if (aux == MINF)
		return (ft_strjoin_none("-inf", 0));
	return (NULL);
}

char		*ft_floatpoint_conv(t_format format, va_list args)
{
	double				num;
	int					exp;
	char				*ret_spe;

	exp = 0;
	num = va_arg(args, double);
	ret_spe = ft_check_specials(num);
	if (ret_spe)
		return (ret_spe);
	if (format.precision == -1)
		format.precision = 6;
	if (format.type == 'f' || format.type == 'F')
		return (ft_float_str(num, format));
	else if (format.type == 'e' || format.type == 'E')
		return (ft_exp_str(num, &exp, format));
	else if (format.type == 'g' || format.type == 'G')
		return (ft_g_conv(num, &exp, format));
	return (0);
}

/*
** <<n>> type conversion
*/

void		ft_n_conv(t_format format, va_list args, char *printf_buf)
{
	long int	dir;
	int			*num;

	(void)format;
	dir = (long int)va_arg(args, int *);
	num = (int *)dir;
	*num = (int)ft_strlen(printf_buf);
}