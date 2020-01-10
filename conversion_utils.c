/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:18:41 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/10 20:02:32 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Decimal to hex conversion applying bit shift
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

static long long int	ft_ten_power(int p)
{
	if (p > 1)	
		return (ft_ten_power(p-1) * 10);
	return (10);
}

char	*ft_float_str(float num)
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
	f_num = num *  (double)ft_ten_power(6) - i_num * (double)ft_ten_power(6);
	if (f_num + 0.5 <= (num - i_num) * (double)ft_ten_power(7))
		f_num = f_num + 1;	
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	f_str = ft_itoa(f_num);
	i_str = ft_strjoin_first(i_str, ".");
	return (ft_strjoin(i_str, f_str));
}

int		ft_count_decimals(int i_num)
{
	int d;
	
	d = 0;
	while (i_num)		
	{
		i_num = i_num / 10;
		d++;
	}
	if (d < 1)
		return (1); 
	else if (d > 1)
		return (-d + 1);
	return (0);
}

char	*ft_exp_str(float num)
{
	unsigned long long	i_num;
	unsigned long long	f_num;
	int					d;
	char				*f_str;
	char				*i_str;

	d = 0;
	i_str = 0;
	if (num < 0)
	{
		num = - num;
		i_str = "-";
	}
	i_num = (num);
	f_num = num *  (double)ft_ten_power(6 + d) - i_num * (double)ft_ten_power(6 + d);
	if (f_num + 0.5 <= (num - i_num) * (double)ft_ten_power(7 + d))
		f_num = f_num + 1;	
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	f_str = ft_itoa(f_num);
	i_str = ft_strjoin_first(i_str, ".");
	return (ft_strjoin(i_str, f_str));
}
