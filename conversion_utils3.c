/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:26:26 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/14 13:45:57 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_trim_f_zeros(char *num)
{
	int		i;
	int		j;
	char	*num_trimmed;

	j = 0;
	i = ft_strlen(num);
	i--;
	while (num[i] == '0')
		i--;
	if(!(num_trimmed = malloc((ft_strlen(num) - i) * sizeof(char))))
		return (NULL);
	if (num[i] == '.')
		i--;
	while (j < i + 1)
	{
		num_trimmed[j] = num[j];
		j++;
	}
	num_trimmed[j] = '\0';
	free(num);
	num = NULL;
	return (num_trimmed);
}

char	*ft_trim_e_zeros(char *num)
{
	int		i;
	int		k;
	char	*num_trimmed;

	k = 0;
	i = ft_strlen(num) - 5;
	while (num[i] == '0')
		i--;
	if(!(num_trimmed = malloc((ft_strlen(num) - i + 5) * sizeof(char))))
		return (NULL);
	while (k < i + 1)
	{
		num_trimmed[k] = num[k];
		k++;
	}
	i = ft_strlen(num) - 4;
	while (num[i])
		num_trimmed[k++] = num[i++];
	num_trimmed[k] = '\0';
	free(num);
	num = NULL;
	return (num_trimmed);
}

/*
** As found in C11 standard, %g conversion must be:
** if P > X ≥ −4, the conversion is with style f (or F) 
** and precision P − (X + 1). Otherwise, the conversion 
** is with style e (or E) and precision P − 1.
** In both cases insignificant trailing zeros are removed 
** from the significand, and the decimal point is also 
** removed if there are no remaining digits following it.
** A precision of 0 is treated as equivalent to a 
** precision of 1
*/
char	*ft_g_conv(double num, int *exp, int precision, char type)
{
	char	*aux;

	if (type == 'G')
		type = 'E';
	else
		type = 'e';
	aux = ft_exp_str(num, exp, precision, type);
	free(aux);
	aux = NULL;
	if (precision == 0)
		precision = 1;
	*exp = - (*exp);
	if (precision > *exp && *exp >= -4)
		return (ft_trim_f_zeros(ft_float_str(num, precision - (*exp + 1))));
	return (ft_trim_e_zeros(ft_exp_str(num, exp, precision - 1, type)));
}
