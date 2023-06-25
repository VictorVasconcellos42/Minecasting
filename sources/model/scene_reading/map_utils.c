/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:56:45 by jsantann          #+#    #+#             */
/*   Updated: 2023/06/25 16:31:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// Verify if string is a valid map
int	is_map(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1')
			return (1);
		else
			return (0);
	}
	else if (str[0] == '1')
		return (1);
	else
		return (0);
}

// Check start of map
int	start_map(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		if (is_map(matrix[i]))
			return (i);
		i++;
	}
	return (0);
}

// Take len of map
int	size_map(char **matrix, int start)
{
	int	size;

	size = 0;
	while (matrix[start])
	{
		start++;
		size++;
	}
	return (size);
}

int	search_max_len(char **matrix, int start)
{
	int	sub;
	int	temp;

	sub = 0;
	while (matrix[start])
	{
		temp = 0;
		while (matrix[start][temp])
		{
			ft_printf ("[%c]", matrix[start][temp]);
			temp++;
		}
		ft_printf ("\ntemp = %d\n", temp);
		if (temp > sub)
			sub = temp;
		start++;
	}
	return (sub);
}

char	*ft_specialdup(const char *s1, size_t len)
{
	char	*string;
	char	*dest;
	size_t	i;

	i = 0;
	string = (char *) s1;
	dest = malloc(sizeof(char) * len + 3);
	if (!(dest))
		return (NULL);
	dest[0] = ' ';
	while (string[i] && string[i] != '\n')
	{
		dest[i + 1] = string[i];
		i++;
	}
	i++;
	while (i <= len)
		dest[i++] = ' ';
	dest[i] = '\0';
	return (dest);
}
