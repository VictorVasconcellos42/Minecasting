/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:58:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/06 14:29:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_cube *cub, void **addr, char **head)
{
	char	*aux;
	int		i;
	int		jnk;

	i = -1;
	while (*(head + ++i))
	{
		aux = *(head + i);
		*(addr + i) = mlx_xpm_file_to_image(cub->mlx.init, aux + 3, &jnk, &jnk);
		free (aux);
		*(head + i) = mlx_get_data_addr(*(addr + i), &jnk, &jnk, &jnk);
	}
}
