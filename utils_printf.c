/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:51:26 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/20 15:11:36 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char 	*ft_string_to_char(char *s)
{
	char *aux;

	if (!(aux = malloc(2 * sizeof(char))))
		return (0);
	*aux = *s;
	*(aux + 1 ) = '\0';
	return (aux);
}

void	ft_initialize_format(t_format *format)
{
	format->flags->zero = 0;
	format->flags->plus = 0;
	format->flags->minus = 0;
	format->flags->hash = 0;
	format->flags->space = 0;
	format->flags->zero = 0;
	format->flags->apostrophe = NULL;
	format->width = 0;
	format->precision = 0;
	format->float_precision = 0;
	format->lenght = '\0';
	format->type = '\0';
}

char	*ft_post_format(char *format_aux, t_format format)
{
	if (format.flags->plus && !format.flags->zero)
		format_aux = ft_plus(format_aux, format);
	if (format.flags->space)
		format_aux = ft_space(format_aux, format);
	if (format.flags->hash)
		format_aux = ft_hash(format_aux, format);
	if (format.flags->apostrophe)
		format_aux = ft_apostrophe(format_aux, format);
	if (format.width)
		format_aux = ft_width(format, format_aux);
	if (format.flags->plus && format.flags->zero)
		format_aux = ft_plus(format_aux, format);
	return (format_aux);
	//else if (format.lenght)
}

/*
void	ft_check_flags(t_format *format, char set)
{
	(void)format;

	if (set == '0')
		format->flags->zero = 1;
	else if (set == '+')
		format->flags->plus = 1;
	else if (set == '-')
		format->flags->minus = 1;
	else if (set == '#')
		format->flags->hash = 1;
	else if (set == ' ')
		format->flags->space = 1;
	else if (set == 39)
		format->flags->apostrophe = 1;
}

int 	ft_check_number(char *format_info, int *i, va_list args)
{
	int		j;
	int		k;
	char	*num;
		
	if (format_info[*i] == '*')
		return (va_arg(args, int));
	j = *i;
	k = 0;
	while (format_info[j] >= '0' && format_info[j] <= '9')
		j++;
	if (!(num = malloc((j - *i + 1) *  sizeof(char))))
		return (0);
	while (*i < j)
	{
		num[k++] = format_info[*i];
		*i = *i + 1;
	}
	num[k] = '\0';
	return (ft_atoi_free(num));
}

char	ft_check_lenght(char *format_info, int *i)
{
	if (format_info[*i + 1] == 'l')
	{
		*i = *i + 2;
		return ('L');
	}
	else if (format_info[*i + 1] == 'h')
	{
		*i = *i + 2;
		return ('H');
	}
	*i = *i + 1;
	return (format_info[*i - 1]);
}

void	ft_classify_format(char *format_info, t_format *format, va_list args)
{
	int i;

	i = 1;
	while (format_info[i] == '0' ||format_info[i] == '+'
			|| format_info[i] == '-' || format_info[i] == '#'
			|| format_info[i] == ' ' || format_info[i] == 39)
	{
		ft_check_flags(format, format_info[i]);
		i++;
	}
	if (format_info[i] >= '0' ||format_info[i] <= '9'
			||format_info[i] == '*')
		format->width = ft_check_number(format_info, &i, args);
	if (format_info[i] >= '.')
	{
		i++;
		format->precision = ft_check_number(format_info, &i, args);
	}
	if (format_info[i] == 'h' ||format_info[i] == 'l')
		format->lenght = ft_check_lenght(format_info, &i);
	format->type = format_info[i];
}
*/
