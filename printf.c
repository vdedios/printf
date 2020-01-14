/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:35:34 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/14 13:55:21 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Versión simplificada sin va_args que saca las marcas de cadena
//ojo funciones de string.h 

#include "libft/libft.h"
#include "printf.h"

//ft_extract_format -> extrae el formato
//Falta que chequee errores de formato -> como va por zonas, sería interesante que se comportara como un atoi
//Chequear tipos que llevan mayúsculas - fF eE gG 
//Chequear por qué en %p cojo dir de un char y no de un int
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

char	*ft_analyse(char *format_info, va_list args, char *printf_buf)
{
	int i;

	i = 0;
	while (format_info[i])
		i++;
	if (format_info[--i] == 'c')
		return (ft_c_conv(format_info, args));
	if (format_info[i] == 's')
		return (ft_s_conv(format_info, args));
	if (format_info[i] == 'p')
		return (ft_p_conv(format_info, args));
	if (format_info[i] == 'd' || format_info[i] == 'i')
		return (ft_di_conv(format_info, args));
	if (format_info[i] == 'u')
		return (ft_u_conv(format_info, args));
	if (format_info[i] == 'x' || format_info[i] == 'X')
		return (ft_xX_conv(format_info, args, i));
	if (format_info[i] == 'f' || format_info[i] == 'e'||
			format_info[i] == 'g'||format_info[i] == 'F'|| 
			format_info[i] == 'E' || format_info[i] == 'G')
		return (ft_floatpoint_conv(format_info, args, i));
	if (format_info[i] == 'n')
		ft_n_conv(format_info, args, printf_buf);
	return (0);
}

//Ejecuta formato. Avanza s en format_info y concatena en print_buf el valor a extraído y formateado
char	*ft_formater(const char **s, char **print_buf, va_list args)
{
	char	*format_info;
	char	*format_aux;
	(void ) args;	

	//1 -> extract
	format_info = ft_extract_format(*s);
	//2 -> ft_analyse (errors) -> ft_type_conv
	format_aux = ft_analyse(format_info, args, *print_buf);
	//4 -> ft_flag_conv	
	//5 -> copy to buf and forward string
	
	*print_buf = ft_strjoin(*print_buf, format_aux);
	*s = *s + ft_strlen(format_info) - 1;
	return (0);
}

//(ft_read)
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
