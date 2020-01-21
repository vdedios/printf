/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:35:34 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/21 11:32:35 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

//Chequear tipos que llevan mayúsculas - fF eE gG 
//Puede que haya fugas de memoria en extract_format
//Inicializar estructura para controlar valores -> hacer una función que inicialice
char	*ft_extract_format(const char *s)
{
	int 	l;
	int		l_types;
	char	*types;

	l = 0;
	types = "cspdiuxXnfgeFGE";
	l_types = ft_strlen(types);
	while (s[l] != *types++ && s[l])
	{
		if (!*types)
		{
			types = types - l_types;
			l++;
		}
	}
	return (ft_substr(s, 0, l + 1));
}

char	*ft_pre_format(va_list args, t_format format, char *print_buf)
{
	if (format.type == 'c')
		return (ft_c_conv(format, args));
	if (format.type == 's')
		return (ft_s_conv(format, args));
	if (format.type == 'p')
		return (ft_p_conv(format, args));
	if (format.type == 'd' || format.type == 'i')
		return (ft_di_conv(format, args));
	if (format.type == 'u')
		return (ft_u_conv(format, args));
	if (format.type == 'x' || format.type == 'X')
		return (ft_xX_conv(format, args));
	if (format.type == 'f' || format.type == 'e'||
			format.type == 'g'||format.type == 'F'|| 
			format.type == 'E' || format.type == 'G')
		return (ft_floatpoint_conv(format, args));
	if (format.type == 'n')
		ft_n_conv(format, args, print_buf);
	return (0);
}

char	*ft_formater(const char **s, char **print_buf, va_list args)
{
	char		*format_info;
	char		*format_aux;
	t_format	format;
	t_flags		flags;
	(void ) args;	

	format.flags = &flags;
	//0 -> INITIALIZE FORMAT -> defaut prec = 6
	ft_initialize_format(&format);
	
	//1 -> extract format
	format_info = ft_extract_format(*s);

	//2 -> classify format in struct
	ft_classify_format(format_info, &format, args);

	//3 -> get values and pre-process
	format_aux = ft_pre_format(args, format, *print_buf);

	//4 -> apply post-process flags
	format_aux = ft_post_format(format_aux, format);
	
	//5 -> copy to buf and forward string
	*print_buf = ft_strjoin(*print_buf, format_aux);
	*s = *s + ft_strlen(format_info) - 1;
	return (0);
}

int		ft_printf(const char *s, ...)
{
	char	*print_buf;
	va_list	args;

	va_start(args, s);
	if (!(print_buf = malloc(1)))
		return (0);
	*print_buf = 0;	
	while(*s)
	{
		if (*s == '%' && (*s + 1) != '%')
			ft_formater(&s, &print_buf, args);
		else
		print_buf = ft_strjoin(print_buf, ft_string_to_char((char *)s));
		s++;
	}
	va_end(args);
	ft_putstr_fd(print_buf, 1);
	return (ft_strlen(NULL));
}
