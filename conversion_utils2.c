/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:30:49 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/12 20:13:39 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

char				*ft_get_decimals(double num)
{
	int 				i;
	int 				decimals;
	unsigned long long	f_num;
	char				*f_str;

	i = 0;
	decimals = 0;
	i = ft_get_integer(num, 'f');
	f_num =	num * ft_ten_power(6 + i) -
		(unsigned long long)(num * ft_ten_power(i)) * ft_ten_power(6);
	if ((num * ft_ten_power(6 + i) - (long long int)(num * ft_ten_power(6 + i)) >= 0.5))
		f_num = f_num + 1;
	f_str = ft_itoa(f_num);
	f_num = (unsigned long long)ft_strlen(f_str);
	while (decimals++ < 6 - (int)f_num) 
		f_str = ft_strjoin_second("0", f_str);
	f_str = ft_strjoin_first(f_str, "e");
	f_str = ft_strjoin(f_str, ft_itoa_special(-i));
	return (f_str);
}

char				*ft_exp_str(float num)
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

