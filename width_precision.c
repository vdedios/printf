/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:36:21 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/20 11:15:12 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_set_spaces(int num, char symbol)
{
	char	*spaces;
	int 	i;

	i = 0;
	if (num > 0)
	{
		if(!(spaces = malloc(num * sizeof(char) + 1)))	
			return (NULL);
		while (i < num)	
			spaces[i++] = symbol;
		spaces[i] = '\0';
		return (spaces);
	}
	else
		return (NULL);
}

char	*ft_trim_string(char *str, int pos)
{
	char	*trimmed;
	int		i;

	i = 0;
	if (!(trimmed = malloc(pos * sizeof(char))))
		return (NULL);
	while (i < pos)
	{
		trimmed[i] = str[i];
		i++;
	}
	trimmed[i] = '\0';
	free (str);
	str = NULL;
	return (trimmed);
}

char	*ft_width(t_format format, char *str)
{
	format.width = format.width - ft_strlen(str);
	if (format.flags->zero && !format.flags->minus)
		return (ft_strjoin(ft_set_spaces(format.width, '0'), str));
	else if (format.flags->minus)
		return (ft_strjoin(str, ft_set_spaces(format.width, ' ')));
	else 
		return (ft_strjoin(ft_set_spaces(format.width, ' '), str));
}

char	*ft_precision(t_format format, char *str)
{
	if (format.type == 'd' || format.type == 'i' ||
			format.type == 'u' ||format.type == 'x'
			|| format.type == 'X')
	{
		if (str[0] == '-')
		{
			str[0] = '0';
			format.precision = format.precision - ft_strlen(str);
			str = ft_strjoin(ft_set_spaces(format.precision, '0'), str);
			return (ft_strjoin_second("-", str));
		}
		format.precision = format.precision - ft_strlen(str);
		return (ft_strjoin(ft_set_spaces(format.precision, '0'), str));
	}
	else if (format.type == 's')
		return (ft_trim_string(str, format.precision));
	return (0);
}
