/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:51:26 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/22 17:37:30 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_to_ten(char *num, int l_a)
{

}

char	*ft_base_conversion(char *num, char *base_a, char *base_b)
{
	int l_a;
	int l_b;

	l_a = ft_strlen(base_a);
	l_b = ft_strlen(base_b);
	if (l_a != 10)
		ft_to_ten(num, base_a)
	if (l_b != 10)
		ft_from_ten(num, base_b)
}

char 	*ft_string_to_char(char *s)
{
	char *aux;

	if (!(aux = malloc(2 * sizeof(char))))
				return (0);
	*aux = *s;
	*(aux + 1 ) = '\0';
	return (aux);
}
