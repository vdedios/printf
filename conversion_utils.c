/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:18:41 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/13 13:20:51 by vde-dios         ###   ########.fr       */
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
	double	t;
	int		i;
	
	t = 1;
	i = 0;
	if (p < 0)
	{
		p = -p;
		while (i++ < p)
			t = t / 10;
	}
	else if (p > 0)
		while (i++ < p)
			t = t * 10;
	return (t);
}

int						ft_count_figures(long long int num)
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

unsigned long long		ft_rounding(unsigned long long i_num,
							unsigned long long f_num, float num, int precision)
{
	if (precision <= 0)
	{
		if (i_num + 0.5 <= num)
			i_num = i_num + 1;	
		return (i_num);
	}
	if (f_num + 0.5 <= (num - i_num) * ft_ten_power(precision))
		f_num = f_num + 1;	
	return (f_num);

}

char					*ft_add_zeroes(char *f_str, int precision)
{
	int					decimals;
	int					i;

	decimals = 0;
	i = ft_strlen(f_str);
	while (decimals++ < precision - (int)i) 
		f_str = ft_strjoin_second("0", f_str);
	return (f_str);
}

char					*ft_float_str(float num, int precision)
{
	unsigned long long	i_num;
	unsigned long long	f_num;
	char				*f_str;
	char				*i_str;

	i_str = 0;
	if (num < 0)
	{
		num = - num;
		i_str = "-";
	}
	i_num = (num);
	f_num = num *  ft_ten_power(precision) - i_num * ft_ten_power(precision);
	if (precision <= 0)
	{
		i_num = ft_rounding(i_num, f_num, num, precision);
		i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
		return (i_str);
	}
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	i_str = ft_strjoin_first(i_str, ".");
	f_num = ft_rounding(i_num, f_num, num, precision);
	f_str = ft_itoa(f_num);
	f_str = ft_add_zeroes(f_str, precision);
	return (ft_strjoin(i_str, f_str));
}
