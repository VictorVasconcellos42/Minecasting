/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_pututils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:29:21 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/23 01:03:09 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

int	gc_puthex_fd(long unsigned int hex, char mode, int fd)
{
	int	len;

	len = 0;
	if (mode == ('p' - 'X'))
	{
		len += gc_putstr_fd("0x", fd);
		mode = 32;
	}
	if (hex >= 16)
		len += gc_puthex_fd((hex / 16), mode, fd);
	if ((hex % 16) < 10)
		len += gc_putchar_fd(('0' + (hex % 16)), fd);
	else
		len += gc_putchar_fd((('A' + mode) + ((hex % 16) - 10)), fd);
	return (len);
}

int	gc_putunbr_fd(unsigned int unbr, int fd)
{
	int	len;

	len = 0;
	if (unbr >= 10)
		len += gc_putunbr_fd((unbr / 10), fd);
	len += gc_putchar_fd(('0' + (unbr % 10)), fd);
	return (len);
}

int	gc_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	gc_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += gc_putchar_fd('-', fd);
		num = (n * -1);
	}
	else
		num = n;
	if (num >= 10)
	{
		len += gc_putnbr_fd((num / 10), fd);
	}
	len += gc_putchar_fd(((num % 10) + '0'), fd);
	return (len);
}

int	gc_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	if (str)
		while (*(str + len))
			len ++;
	write (fd, str, len);
	return (len);
}
