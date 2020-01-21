/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:17:00 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/18 17:09:09 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_count_figures(long long int num)
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

unsigned long long	ft_get_integer(double num, char type)
{
	unsigned long long	i_num; 
	int					i;
	
	i = 0;
	if (*((long long int *)&num) == 0)
		return (0);
	i_num = (int)num;
	while (ft_count_figures(i_num) != 1)
	{
		if (ft_count_figures(i_num) < 1)
		{
			i++;
			i_num = (long long int)(num * ft_ten_power(i));	
		}
		else 
		{
			i--;
			i_num = (long long int)num * ft_ten_power(i);	
		}
	}
	if (type == 'i')
		return (i_num);
	else 
		return (i);
}

char				*ft_get_decimals(double num, int *exp, t_format format)
{
	int 				decimals;
	unsigned long long	f_num;
	char				*f_str;

	decimals = 0;
	*exp = ft_get_integer(num, 'f');
	if (format.precision == 0)
		return (ft_strjoin_second("e", ft_itoa_special(-*exp)));
	f_num =	num * ft_ten_power(format.precision + *exp) -
		(unsigned long long)(num * ft_ten_power(*exp)) * ft_ten_power(format.precision);
	if ((num * ft_ten_power(format.precision + *exp) - (long long int)(num * ft_ten_power(format.precision + *exp)) >= 0.5))
		f_num = f_num + 1;
	f_str = ft_itoa(f_num);
	f_num = (unsigned long long)ft_strlen(f_str);
	while (decimals++ < format.precision - (int)f_num) 
		f_str = ft_strjoin_second("0", f_str);
	if (format.type == 'E')
		f_str = ft_strjoin_first(f_str, "E");
	else
		f_str = ft_strjoin_first(f_str, "e");
	f_str = ft_strjoin(f_str, ft_itoa_special(-*exp));
	return (f_str);
}

char				*ft_exp_str(double num, int *exp, t_format format)
{
	unsigned long long	i_num;
	char				*f_str;
	char				*i_str;

	i_str = 0;
	if (num < 0)
	{
		num = - num;
		i_str = "-";
	}
	i_num = ft_get_integer(num, 'i');
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	if (format.precision != 0)
		i_str = ft_strjoin_first(i_str, ".");
	f_str = ft_get_decimals(num, exp, format);
	return (ft_strjoin(i_str, f_str));
}
