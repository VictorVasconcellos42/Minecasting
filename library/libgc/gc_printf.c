/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:21:13 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/23 01:22:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

static int	gc_putformatted_fd(char mask, va_list *ap, int fd);

int	gc_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	if (!format)
		return (0);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len += gc_putformatted_fd(*++format, &ap, 1);
		else
			len += gc_putchar_fd(*format, 1);
		format ++;
	}
	va_end(ap);
	return (len);
}

static int	gc_putformatted_fd(char mask, va_list *ap, int fd)
{
	int		len;
	char	*str;

	len = 0;
	if ((mask == 'd') || (mask == 'i'))
		len += gc_putnbr_fd(va_arg(*ap, int), fd);
	else if (mask == 'u')
		len += gc_putunbr_fd(va_arg(*ap, unsigned int), fd);
	else if ((mask == 'p') || (mask == 'x') || (mask == 'X'))
		len += gc_puthex_fd(va_arg(*ap, long unsigned int), (mask - 'X'), fd);
	else if (mask == 'c')
		len += gc_putchar_fd(va_arg(*ap, int), fd);
	else if (mask == '%')
		len += gc_putchar_fd('%', fd);
	else if (mask == 's')
	{
		str = va_arg(*ap, char *);
		if (!str)
			len += gc_putstr_fd("(null)", fd);
		else
			len += gc_putstr_fd(str, fd);
	}
	return (len);
}
