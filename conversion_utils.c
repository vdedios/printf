/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:18:41 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/05 22:10:39 by vde-dios         ###   ########.fr       */
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

void	ft_convert_hex(char *hex, long int num, int uplow)
{
	int i;

	i = 0;
	while (num >= 16)
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

int	ft_nexti(float num, int i, int j)
{
	if (j < i)
		return (ft_nexti(num, i, j + 1) * 10);
		//printf("i:%d\n", ft_nexti(num, i, j + 1) * 10);
	return (num);
}

float	ft_nextf(float num, int i, int j)
{
	if (j < i)
		return (ft_nextf(num, i, j + 1) * 10);
		//printf("f%f menos \n", ft_nextf(num, i, j + 1) * 10);
	return (num);
}

char	*ft_float_str(float num)
{
	int	precision = 19;
	int 	i;
	int 	j;
	int 	k;
	int 	aux;
	unsigned long	i_part;
	char	*f_part;

	i = 0;
	j = 0;
	k = 0;
	i_part = (long)num;
	if (!(f_part = malloc(precision * sizeof(char))))
		return (0);
	while (i++ < precision)
	{
		aux = (int)ft_nextf(num, i, j);
		printf("aux: %d\n", aux);
		f_part[k++] = aux + '0';
	}
	f_part[i] = '\0';
	//if (f_part + 0.5 <= (num - i_part) * 1e19)
	//	f_part = f_part + 1;	
	printf("i_part: %ld, f_part: %s\n", i_part, f_part);
	return (0);
}
