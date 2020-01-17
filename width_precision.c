/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:36:21 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/17 13:03:47 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_set_spaces(int num, char symbol)
{
	char	*spaces;
	int 	i;

	i = 0;
	if(!(spaces = malloc(num * sizeof(char) + 1)))	
		return (NULL);
	while (i < spaces)	
		spaces[i++] = symbol;
	spaces[i] = '\0';
	return (spaces);
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

void	ft_width(t_format format, char *str)
{
	if (format.zero && !format.minus && !format.precision)
		str = ft_strjoin(ft_set_spaces(format.width, '0'), str);
	else if (format.minus)
		str = ft_strjoin(str, ft_set_spaces(format.width, ' '));
	else 
		str = ft_strjoin(ft_set_spaces(format.width, ' '), str);
}

void	ft_precision(t_format format, char *str)
{
	//con d, i, u
	if (format.type == 'd' || format.type == 'i' ||
			format.type == 'u' || format.type == 'x'
			|| format.type == 'X')
		str = ft_strjoin(ft_set_spaces(format.width, '0'), str);
	//con s
	else if (format.type == 's')
		str = ft_trim_string(str, format.precision)
	//con f, g, e casi está: mirar como integrar con el código una vez tenga todo listo
}










