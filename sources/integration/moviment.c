/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/07 10:38:37 by thfirmin         ###   ########.fr       */
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
	double	posx;
	double	posy;
	int		bin;

	bin = 0;
	if (key == KEY_W)
		bin = 1;
	if (key == KEY_S)
		bin = -1;
	posx = cub->ray.posx;
	posy = cub->ray.posy;
	posx += (*dirx * (cub->ray.m_spd * 2)) * bin;
	posy += (*diry * (cub->ray.m_spd * 2)) * bin;
	if (cub->world.map[(int)posy][(int)posx] != '1')
	{
		cub->ray.posx += (*dirx * cub->ray.m_spd) * bin; 
		cub->ray.posy += (*diry * cub->ray.m_spd) * bin;
	}
}

static void	horizontal_move(t_cube *cub, int key, double *dirx, double *diry)
{
	double	posx;
	double	posy;
	double	*pi90;
	int		bin;

	bin = 0;
	if (key == KEY_A)
		bin = 1;
	if (key == KEY_D)
		bin = -1;
	posx = cub->ray.posx;
	posy = cub->ray.posy;
	pi90 = &cub->ray.rad90;
	posx -= (*dirx * cos(*pi90 * bin) + *diry * -sin(*pi90 * bin))
		* (cub->ray.m_spd * 2);
	posy -= (*dirx * sin(*pi90 * bin) + *diry * cos(*pi90 * bin))
		* (cub->ray.m_spd * 2);
	if (cub->world.map[(int)posy][(int)posx] != '1')
	{
		cub->ray.posx -= (*dirx * cos(*pi90 * bin) + *diry * -sin(*pi90 * bin))
			* cub->ray.m_spd;
		cub->ray.posy -= (*dirx * sin(*pi90 * bin) + *diry * cos(*pi90 * bin))
			* cub->ray.m_spd;
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
