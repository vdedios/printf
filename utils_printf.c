/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:51:26 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/14 20:22:59 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char 	*ft_string_to_char(char *s)
{
	char *aux;

	if (!(aux = malloc(2 * sizeof(char))))
		return (0);
	*aux = *s;
	*(aux + 1 ) = '\0';
	return (aux);
}

void	ft_save_format(t_format *format, char *set, int set_id)
{
	(void)format;

	printf("set_id: %d set:%c\n",set_id, set[0]);
}

void	ft_classify_format(char *format_info, t_format *format)
{
	int i;
	int j;
	int k;
	char *set[5];

	i = 0;
	j = 0;
	k = 0;
	set[0] = "0+-# '";
	set[1] = "123456789*";
	set[2] = ".";
	set[3] = "lh";
	set[4] = "cspdiuxXnfgeFGE";
	while (k < 5)
	{
		while (j++ <= (int)ft_strlen(format_info))
		{
			while (format_info[j] != set[k][i] && set[k][i])
			{
				i++;
			}
			if (set[k][i] != '\0')
				ft_save_format(format, &format_info[j], k);
			i = 0;
		}	
		j = 0;
		k++;
	}
}
