/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:26:26 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/12 20:07:19 by vde-dios         ###   ########.fr       */
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

char	*ft_g_conv(double num)
{
	char	*f_out;
	char	*e_out;

	f_out = ft_trim_f_zeros(ft_float_str(num));
	e_out = ft_trim_e_zeros(ft_exp_str(num));
	if (ft_strlen(f_out) < ft_strlen(e_out))
		return (f_out);
	return (e_out);
}
