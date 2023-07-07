/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:58:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/07 18:17:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_cube *cub, char **files)
{
	t_text	**text;
	void	*addr;
	int		hei;
	int		wid;
	int		i;

	i = -1;
	text = ft_calloc(sizeof(t_text), 5);
	if (!text)
		return ;
	while (*(files + ++i))
	{
		addr = mlx_xpm_file_to_image(cub->mlx.init, *(files + i) + 3,
				&wid, &hei);
		*(text + i) = textnew(addr, wid, hei);
		text[i]->head = mlx_get_data_addr(addr, &text[i]->bpp,
				&text[i]->slen, &text[i]->end);
		free (*(files + i));
		*(files + i) = 0;
	}
	free (files);
	cub->text = text;
}

t_text	*textnew(void *addr, int width, int height)
{
	t_text	*text;

	text = ft_calloc(sizeof(t_text), 1);
	if (text)
	{
		text->addr = addr;
		text->width = width;
		text->height = height;
	}
	else
		errno = ENOMEM;
	return (text);
}
