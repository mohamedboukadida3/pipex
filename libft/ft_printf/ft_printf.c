/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:32:19 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/14 18:04:27 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(const char s)
{
	return (ft_strchr("cspdiuxX%", s) != 0);
}

static int	ft_arg(const char s, va_list ap, int len)
{
	if (s == '%')
		len = len + ft_putchar(s);
	if (s == 'c')
		len = len + ft_putchar(va_arg(ap, int));
	else if (s == 's')
		len = len + ft_putstr(va_arg(ap, char *));
	else if (s == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_ptr(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	else if (s == 'd')
		len = len + ft_putnbr(va_arg(ap, int));
	else if (s == 'i')
		len = len + ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		len = len + ft_putunbr(va_arg(ap, unsigned int));
	else if (s == 'x')
		len += ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		len += ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF");
	return (len);
}

static int	ft_final_arg(const char *s, va_list ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%' && ft_check(*(s + 1)))
		{
			s++;
			len = ft_arg(*s, ap, len);
		}
		else
		{
			ft_putchar(*s);
			len ++;
		}
		s++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, s);
	len = ft_final_arg(s, ap);
	va_end(ap);
	return (len);
}
/*va_start(), qui nous permet de commencer 
à parcourir la liste d'arguments passés à notre fonction;
va_arg(), qui nous permet de récupérer 
un argument de cette liste à chaque appel ;
va_end(), qui permet de signaler qu'on
a fini de lire la liste d'arguments ;*/