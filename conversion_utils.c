/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:18:41 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/11 14:34:17 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Decimal to hex conversion applying bit shift
*/
void					ft_print_hex(char *hex, long long int num, char uplow)
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

double					ft_ten_power(int p)
{
	if (p > 1)	
		return (ft_ten_power(p - 1) * 10);
	else if (p < 0)
		return (ft_ten_power(p + 1) / 10);
	return ((double)10);
}

int						ft_count_figures(int num)
{
	int d;
	
	d = 0;
	while (num)		
	{
		num = num / 10;
		d++;
	}
	return (d);
}

char					*ft_float_str(float num)
{
	unsigned long long	i_num;
	unsigned long long	f_num;
	int					decimals;
	char				*f_str;
	char				*i_str;

	i_str = 0;
	decimals = 0;
	if (num < 0)
	{
		num = - num;
		i_str = "-";
	}
	i_num = (num);
	f_num = num *  ft_ten_power(6) - i_num * ft_ten_power(6);
	if (f_num + 0.5 <= (num - i_num) * ft_ten_power(6))
		f_num = f_num + 1;	
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	f_str = ft_itoa(f_num);
	while (decimals++ < 6 - ft_count_figures(f_num)) 
		f_str = ft_strjoin_second("0", f_str);
	i_str = ft_strjoin_first(i_str, ".");
	return (ft_strjoin(i_str, f_str));
}
