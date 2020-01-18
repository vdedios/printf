/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:07:37 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/18 17:31:21 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	{
		if (!(format->flags->apostrophe = malloc (2 * sizeof(char))))
			return (NULL);
		//OJO! si no se usara (por error de formato por ejemplo, liberar memoria)
		format->flags->apostrophe[0] = ',';
		format->flags->apostrophe[1] = '\0';
	}
}

int 	ft_check_number(char *format_info, int *i, va_list args, t_format *format)
{
	int		j;
	int		k;
	char	*num;
		
	if (format_info[*i] == '*')
	{
		k = va_arg(args, int);
		if (k < 0 && format_info[*i - 1] != '.')
			format->minus = 1;
		return (k);
	}
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
	if (format_info[i] > '0' ||format_info[i] <= '9'
			||format_info[i] == '*')
		format->width = ft_check_numbej(format_info, &i, args, format);
	if (format_info[i] >= '.')
	{
		i++;
		format->precision = ft_check_number(format_info, &i, args, format);
	}
	if (format_info[i] == 'h' ||format_info[i] == 'l')
		format->lenght = ft_check_lenght(format_info, &i);
	format->type = format_info[i];
}