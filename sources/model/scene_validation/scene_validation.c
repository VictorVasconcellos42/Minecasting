/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:30:57 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/29 18:29:59 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	texture_validation(char **texture)
{
	texture_null(texture);
	texture_little(texture);
	texture_xpm(texture);
	texture_path(texture);
}
