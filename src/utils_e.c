/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:17:00 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/22 16:00:42 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int							ft_count_figures(long long int num)
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

unsigned long long			ft_get_integer(double num, char type, int *exp)
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
	*exp = i;
	if (type == 'i')
		return (i_num);
	else
		return (i);
}

static void					ft_round_exp(t_format format, unsigned long long *i_num,
		unsigned long long *f_num, int *exp)
{
	unsigned long long	i_aux;
	unsigned long long 	f_aux;

	f_aux = *i_num * ft_ten_power(format.precision) +
		*f_num / ft_ten_power(10 - format.precision);
	i_aux = (*i_num * ft_ten_power(format.precision + 1)) +
		(*f_num / ft_ten_power(10 - format.precision - 1));
	if (i_aux >= f_aux * 10 + 5)
	{
		i_aux = f_aux;
		f_aux = f_aux + 1;
	}
	if (ft_count_figures(f_aux) > ft_count_figures(i_aux))
	{	
		*exp = *exp - 1;
		format.precision = format.precision + 1;
	}
	*i_num = f_aux / (unsigned long long)ft_ten_power(format.precision);
	*f_num = f_aux % (unsigned long long)ft_ten_power(format.precision);
}

char						*ft_get_decimals(unsigned long long f_num, int *exp,
		t_format format)
{
	char 	*f_str;

	f_str = ft_itoa(f_num);
	f_str = ft_add_zeroes(f_str, format.precision);
	if (!format.precision)
	{
		free(f_str);
		f_str = NULL;
	}
	if (format.type == 'e')
		f_str = ft_strjoin_first(f_str, "e");
	else
		f_str = ft_strjoin_first(f_str, "E");
	f_str = ft_strjoin(f_str, ft_itoa_special(-*exp));
	return (f_str);
}

char						*ft_exp_str(double num, int *exp, t_format format)
{
	unsigned long long	i_num;
	unsigned long long	f_num;
	char				*f_str;
	char				*i_str;

	i_str = 0;
	if (num < 0)
	{
		num = -num;
		i_str = "-";
	}
	i_num = ft_get_integer(num, 'i', exp);
	f_num = num * ft_ten_power(10 + *exp) -
		(unsigned long long)(num * ft_ten_power(*exp)) *
		ft_ten_power(10);
	ft_round_exp(format, &i_num, &f_num, exp);
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	f_str = ft_get_decimals(f_num, exp, format);
	if (format.precision != 0 || format.flags->hash)
		i_str = ft_strjoin_first(i_str, ".");
	return (ft_strjoin(i_str, f_str));
}
