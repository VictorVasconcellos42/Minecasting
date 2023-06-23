/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:57:37 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/23 14:24:44 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_data_integration(t_ray *ray)

{
    printf("---------------------------------------\n");
    printf("PLAYER POS X: %f\tPLAYER POS Y: %f\n", ray->posx, ray->posy);
    printf("VISION DIRX: %f\tVISION DIRY: %f\n", ray->dirx, ray->diry);
    printf("---------------------------------------\n");
}
