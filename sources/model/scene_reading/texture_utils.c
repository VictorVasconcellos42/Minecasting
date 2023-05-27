/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:24:13 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/17 16:44:33 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	count_n(char *src, int start)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (src[start] != '\n')
	{
		if (src[0] == ' ' && !flag)
			while (src[start] == ' ')
				start++;
		flag = 1;
		if (!src[start] || src[start] == '\n')
			return (start);
		start++;
		j++;
	}
	return (j);
}

int	locate_char(char *src, int start, char key)
{
	int	size;

	size = 0;
	if (src[start] == key)
	{
		size = count_n(src, start);
		return (size);
	}
	else
		return (0);
}

int	count_char(char *src, char key)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != key)
	{
		if (src[0] == ' ')
			while (src[i] == ' ')
				i++;
		if (src[i] == key)
			return (i);
		i++;
		j++;
	}
	return (j);
}

int	count_space(char *src)
{
	int	i;

	i = 0;
	while (src[i] == ' ')
		i++;
	return (i);
}

char	*create_vector(char *src, int start, int size)
{
	char	*res;
	int		j;
	int		flag;

	if (size < 1)
		return (NULL);
	res = ft_calloc(sizeof(char), size + 1);
	j = 0;
	while (src[start] != '\n')
	{
		if (src[0] == ' ' && !flag)
			while (src[start] == ' ')
				start++;
		flag = 1;
		res[j] = src[start];
		start++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
