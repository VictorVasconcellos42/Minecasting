/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:25:01 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/19 16:25:54 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parse.h"

int	main(int argc, char **argv)

{
	t_cube	cube;
	int		fd;

	fd = error_menu(argv, argc);
	get_file(fd, &cube);
}
