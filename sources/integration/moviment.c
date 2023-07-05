/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/05 18:48:09 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal_move(t_cube *cub, int key, double *dirx, double *diry);

static void	vertical_move(t_cube *cub, int key, double *dirx, double *diry);

void	set_key_a(t_cube *cub, double *dirx, double *diry)

{
	double	posx;
	double	posy;
	double	*pi90;

	pi90 = &cub->ray.rad90;
	posx -= (*dirx * cos(*pi90) + *diry * -sin(*pi90)) * cub->ray.m_spd;
	posy -= (*dirx * sin(*pi90) + *diry * cos(*pi90)) * cub->ray.m_spd;
	if (cub->world.map[(int)posy][(int)posx] != '1')
	{
		cub->ray.posx = posx;
		cub->ray.posy = posy;
	}
}

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
	double	posx;
	double	posy;

	posx = cub->ray.posx;
	posy = cub->ray.posy;
	if (key == KEY_W)
	{
		posy += *diry * cub->ray.m_spd;
		posx += *dirx * cub->ray.m_spd;
		if (cub->world.map[(int)posy][(int)posx] != '1')
		{
			cub->ray.posx = posx;
			cub->ray.posy = posy;
		}
	}
	if (key == KEY_S)
	{
		posy -= *diry * cub->ray.m_spd;
		posx -= *dirx * cub->ray.m_spd;
		if (cub->world.map[(int)posy][(int)posx] != '1')
		{
			cub->ray.posx = posx;
			cub->ray.posy = posy;
		}
	}
}

static void	horizontal_move(t_cube *cub, int key, double *dirx, double *diry)
{
	double	posx;
	double	posy;
	double	*pi90;

	posx = cub->ray.posx;
	posy = cub->ray.posy;
	pi90 = &cub->ray.rad90;
	if (key == KEY_A)
		set_key_a(cub, dirx, diry);
	if (key == KEY_D)
	{
		posx -= (*dirx * cos(-*pi90) + *diry * -sin(-*pi90)) * cub->ray.m_spd;
		posy -= (*dirx * sin(-*pi90) + *diry * cos(-*pi90)) * cub->ray.m_spd;
		if (cub->world.map[(int)posy][(int)posx] != '1')
		{
			cub->ray.posx = posx;
			cub->ray.posy = posy;
		}
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
