/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:10:13 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/22 17:26:35 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_len(char *s, int fd, int *pos)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(s);
	if (pos)
		while (pos[i] != -1)
		{
			s[pos[i++]] = 0;
		}
	free(pos);
	pos = NULL;
	write(fd, s, l);
	return (l);
}
