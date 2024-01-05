/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:05:25 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/05 13:12:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int print_img(t_vars vars)
{
	int i;

	i = 0;
	if (vars.img == 0)
		vars.img = mlx_xpm_file_to_image(vars.mlx, "floor.xpm", &i, &i);
	else if (vars.img == 1)
		vars.img = mlx_xpm_file_to_image(vars.mlx, "wall.xpm", &i, &i);
	else if (vars.img == "C")
		vars.img = mlx_xpm_file_to_image(vars.mlx, "object.xpm", &i, &i);
	else if (vars.img == "E")
		vars.img = mlx_xpm_file_to_image(vars.mlx, "exit.xpm", &i, &i);
	else if	(vars.img == "P")
		vars.img = mlx_xpm_file_to_image(vars.mlx, "start.xpm", &i, &i);
}