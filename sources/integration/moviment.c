/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/01 16:53:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal_move(t_cube *cub, int key, double *dirx, double *diry);

static void	vertical_move(t_cube *cub, int key, double *dirx, double *diry);

void	moviment_engine(t_cube *cub, int key)
{
	double	*dirx;
	double	*diry;

	dirx = &cub->ray.dirx;
	diry = &cub->ray.diry;
	if ((key == KEY_W) || (key == KEY_S))
		vertical_move(cub, key, dirx, diry);
	if ((key == KEY_A) || (key == KEY_D))
		horizontal_move(cub, key, dirx, diry);
}

static void	vertical_move(t_cube *cub, int key, double *dirx, double *diry)
{
	double	*posx;
	double	*posy;

	posx = &cub->ray.posx;
	posy = &cub->ray.posy;
	if (key == KEY_W)
	{
		*posx += *dirx * cub->ray.m_spd;
		*posy += *diry * cub->ray.m_spd;
	}
	if (key == KEY_S)
	{
		*posx -= *dirx * cub->ray.m_spd;
		*posy -= *diry * cub->ray.m_spd;
	}
}

static void	horizontal_move(t_cube *cub, int key, double *dirx, double *diry)
{
	double	*posx;
	double	*posy;
	double	*pi90;

	posx = &cub->ray.posx;
	posy = &cub->ray.posy;
	pi90 = &cub->ray.rad90;
	if (key == KEY_A)
	{
		*posx -= (*dirx * cos(*pi90) + *diry * -sin(*pi90)) * cub->ray.m_spd;
		*posy -= (*dirx * sin(*pi90) + *diry * cos(*pi90)) * cub->ray.m_spd;
	}
	if (key == KEY_D)
	{
		*posx -= (*dirx * cos(-*pi90) + *diry * -sin(-*pi90)) * cub->ray.m_spd;
		*posy -= (*dirx * sin(-*pi90) + *diry * cos(-*pi90)) * cub->ray.m_spd;
	}
}

void	look_engine(t_cube *cub, int key, double *dirx, double *diry)
{
	double	*plny;
	double	*plnx;
	double	odirx;
	double	oplanex;

	odirx = cub->ray.dirx;
	oplanex = cub->ray.planex;
	plnx = &cub->ray.planex;
	plny = &cub->ray.planey;
	if (key == KEY_ARR_LEFT)
	{
		*dirx = (*dirx * cos(-cub->ray.r_spd) - *diry * sin(-cub->ray.r_spd));
		*diry = (odirx * sin(-cub->ray.r_spd) + *diry * cos(-cub->ray.r_spd));
		*plnx = (*plnx * cos(-cub->ray.r_spd) - *plny * sin(-cub->ray.r_spd));
		*plny = (oplanex * sin(-cub->ray.r_spd) + *plny * cos(-cub->ray.r_spd));
	}
	if (key == KEY_ARR_RIGHT)
	{
		*dirx = (*dirx * cos(cub->ray.r_spd) - *diry * sin(cub->ray.r_spd));
		*diry = (odirx * sin(cub->ray.r_spd) + *diry * cos(cub->ray.r_spd));
		*plnx = (*plnx * cos(cub->ray.r_spd) - *plny * sin(cub->ray.r_spd));
		*plny = (oplanex * sin(cub->ray.r_spd) + *plny * cos(cub->ray.r_spd));
	}
}
