/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:27:31 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/17 13:44:53 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//la funcion que los llama es porque comprueba que existen
void	ft_plus(char *str, t_format format)
{
	if (str[0] != '-')
		str = ft_strjoin_second("+", str);
}

void	ft_hash(char *str, t_format format)
{
	if (format.type == 'x')
		str = ft_strjoin_second("0x", str);
	else if (format.type == 'X')
		str = ft_strjoin_second("0X", str);
}

void	ft_space(char *str, t_format format)
{
	if (!format.plus && str[0] != '-')
		str = ft_strjoin_second("+", str);
}

char	*ft_thousands_sep(char *str, t_format format)
{
	int 	i;
	int 	new_size;
	char	*aux1;
	char	*aux2;

	i = 3;
	new_size = (ft_strlen(str) + (int)(ft_strlen(str) / 3)) * sizeof(char) + 1;
	if (!(aux1 = malloc(new_size)))
		return (NULL);
	if (!(aux2 = malloc(4 * sizeof(char))))
		return (NULL);
	while (i < new_size)
	{
		aux2[0] = str[i - 3];
		aux2[1] = str[i - 2];
		aux2[2] = str[i - 1];
		aux2[3] = '\0';
		aux2 = ft_strjoin_second(format->flags->apostrophe, aux2);
		aux1 = ft_strjoin(aux2, aux1);
		i += 3;
	}
	aux2[i] = '\0';
	free(format->flags->apostrophe)
		format->flags->apostrophe = NULL;
	return (aux1);
}

void	ft_separate_float(int i, char *integer, char *decimal, char *str)
{
	int 	k;

	k = -1;
	while (k++ < i)
		integer[k] = str[k];
	integer[k] = '\0';
	while (k++ < ft_strlen(str))
		decimals[k] = str[k];
	decimals[k] = '\0';
}

char	*ft_apostrophe(char *str, t_format format)
{
	char	*decimal;
	char	*integer;
	int 	i;

	i = 0;
	if (format.type == 'd' || format.type == 'i' || format.type == 'u')
		str = ft_thousands_sep(str, format);
	else if(format.type == 'f' || format.type == 'g')
	{
		while (str[i] != '.')
			i++;
		if (i > 2)
		{
			if (!(integer = malloc((i) * sizeof(char))))
				return (NULL);
			if (!(decimals = malloc((ft_strlen(str) - i + 1) * sizeof(char))))
				return (NULL);
			ft_separate_float(i, integer, decimal, str);
			integer = ft_thousands_sep(integer, format);
			free (str)
				str = NULL;
			return (ft_strjoin(integer, decimal));
		}
	}
	return (str);
}
