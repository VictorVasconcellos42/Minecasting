/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:09:56 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/23 00:10:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

char	*gc_strdup(const char *str)
{
	char	*dup;
	char	*ptr;
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (*(str + len))
		len ++;
	dup = malloc(len + 1);
	if (!dup)
	{
		errno = ENOMEM;
		return (0);
	}
	ptr = dup;
	while (*str)
		*dup++ = *str++;
	*dup = '\0';
	return (ptr);
}
