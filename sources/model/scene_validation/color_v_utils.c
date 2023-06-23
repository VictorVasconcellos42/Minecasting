/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:41 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/29 15:43:32 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	count_comma(char *str, int position)
{
	while (str[position] && str[position] != ',')
		position++;
	return (position);
}

int	get_r(char *str, int *position)
{
	int		i;
	int		j;
	char	*res;
	int		size;
	int		num;

	i = 2;
	j = 0;
	num = 0;
	res = NULL;
	size = count_comma(str, *position);
	res = ft_calloc(sizeof(char), size + 1);
	while (str[i] && str[i] != ',')
	{
		res[j] = str[i];
		i++;
		j++;
	}
	num = ft_atoi(res);
	free(res);
	*position = i;
	return (num);
}

int	get_g(char *str, int *position)
{
	int		j;
	int		i;
	char	*res;
	int		size;
	int		num;

	j = 0;
	i = *position + 1;
	size = count_comma(str, *position);
	res = ft_calloc(sizeof(char), size + 1);
	while (str[i] && str[i] != ',')
	{
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	num = ft_atoi(res);
	free(res);
	*position = i;
	return (num);
}

int	get_b(char *str, int position)
{
	int		j;
	char	*res;
	int		size;
	int		num;

	j = 0;
	size = count_comma(str, position);
	res = ft_calloc(sizeof(char), size + 1);
	while (str[position])
	{
		res[j] = str[position];
		position++;
		j++;
	}
	res[j] = '\0';
	num = ft_atoi(res);
	free(res);
	return (num);
}
