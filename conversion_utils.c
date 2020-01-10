/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:18:41 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/10 17:25:08 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** This decimal to hex conversion is done applying bit shift
*/
void	ft_print_hex(char *hex, long long int num, char uplow)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (!(num & (LONG_MASK >> i)))
		i += 4;
	while ( i < 64)
	{
		hex[j] = (num & (LONG_MASK >> i)) >> (60 - i);
		if (hex[j] > 9)
			hex[j] = hex[j] + uplow - 33;
		else
			hex[j] = hex[j] + '0';
		i += 4;
		j++;
	}
	hex[j] = '\0';
}

char	*ft_float_str(float num)
{
	unsigned long long	i_num;
	unsigned long long	f_num;
	char				*f_str;
	char				*i_str;

	i_num = (num);
	f_num = num * 1e6 - i_num * 1e6;
	if (f_num + 0.5 <= (num - i_num) * 1e7)
		f_num = f_num + 1;	
	i_str = ft_itoa(i_num);
	f_str = ft_itoa(f_num);
	i_str = ft_strjoin_first(i_str, ".");
	return (ft_strjoin(i_str, f_str));
}
