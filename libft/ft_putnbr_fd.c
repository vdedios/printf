/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:11:49 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/03 14:08:48 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int aux;

	aux = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		aux = (unsigned int)(n * -1);
	}
	if (aux > 9)
		ft_putnbr_fd(aux / 10, fd);
	ft_putchar_fd((char)(aux % 10 + '0'), fd);
}
