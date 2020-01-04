/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:18:41 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/04 21:38:41 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	ft_print_hex(int c, int uplow)
{
	if (c > 9)
	{
		if (uplow == 0)
			c = c - 10 + 'a';
		else
			c = c - 10 + 'A';
	}
	else
		c = c + '0';
	return ((char)c);
}

void	ft_convert_hex(char *hex, int num, int uplow)
{
	int i;

	i = 0;
	while (num > 16)
	{
		hex[i++] = ft_print_hex(num % 16, uplow);
		num = num / 16;
	}
	hex[i++] = ft_print_hex(num, uplow);
	hex[i] = '\0';
}

char	*ft_str_rev(char *str)
{
	char *aux;
	int i;
	int j;

	i = 0;
	j = 0;
	if(!(aux = malloc(ft_strlen(str)*sizeof(char))))
		return (NULL);
	while (str[i])
		*aux++ = str[i++];
	*aux = '\0';
	while (j < i)
		str[j++] = *--aux;
	free (aux);
	aux = NULL;
	str[j] = '\0';
	return (str);
}
