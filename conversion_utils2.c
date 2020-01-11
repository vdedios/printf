/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:30:49 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/11 17:05:22 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned long long	ft_get_integer(double num, char type)
{
	unsigned long long	i_num; 
	int					i;
	
	i = 0;
	i_num = (int)num;
	while (ft_count_figures(i_num) != 1)
	{
		if (ft_count_figures(i_num) < 1)
		{
			i++;
			i_num = (int)(num * ft_ten_power(i));	
		}
		else 
		{
			i--;
			i_num = (int)num * ft_ten_power(i - 1);	
		}
	}
	if (type == 'i')
		return (i_num);
	else 
		return (i);
}

char				*ft_get_decimals(double num)
{
	int 				i;
	unsigned long long	f_num;
	char				*f_str;

	i = 0;
	i = ft_get_integer(num, 'f');
	f_num =	num * ft_ten_power(6 + i) -
		(unsigned long long)(num * ft_ten_power(-1 + i)) * ft_ten_power(6);
	if (f_num + 0.5 <= num * ft_ten_power(7 + i))
		f_num = f_num + 1;
	f_str = ft_strjoin_first(ft_itoa(f_num), "e");
	f_str = ft_strjoin(f_str, ft_itoa_special(-i));
	return (f_str);
}

char						*ft_exp_str(float num)
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
	i_str = ft_strjoin_first(i_str, ".");
	f_str = ft_get_decimals(num);
	return (ft_strjoin(i_str, f_str));
}
