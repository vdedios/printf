/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:30:51 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/21 20:52:48 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int *s)
{
	size_t cont;

	cont = 0;
	if (!s)
		return (0);
	while (s[cont] != -1)
	{
		cont++;
	}
	return (cont);
}
