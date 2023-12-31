/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:55:35 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/09 19:12:52 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_up_img(t_vars vars)
{
	int x;
	int y;

	x = 64;
	y = 64;
	vars.position.img_floor = mlx_xpm_file_to_image(vars.mlx, "floor.xpm", &x, &y);
	vars.position.img_object = mlx_xpm_file_to_image(vars.mlx, "object.xpmx", &x, &y);
	vars.position.img_wall = mlx_xpm_file_to_image(vars.mlx, "wall.xpm", &x, &y);
	vars.position.img_exit = mlx_xpm_file_to_image(vars.mlx, "exit.xpm", &x, &y);
	vars.position.img_start = mlx_xpm_file_to_image(vars.mlx, "start.xpm", &x, &y);
}

void print_imgs(t_vars vars, char **map)
{
    int    x;
    int    y;

    x = 0;
    y = 0;
    while (map[y] != 0)
    {
        while (map[y][x] != '\0')
        {
            if (map[y][x] == '1')
                mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.position.img_wall, (64 * x), (64 * y));
            if (map[y][x] == '0')
                mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.position.img_floor, (64 * x), (64 * y));
            if (map[y][x] == 'C')
                mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.position.img_object, (64 * x), (64 * y));
            if (map[y][x] == 'E')
                mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.position.img_exit, (64 * x), (64 * y));
            if (map[y][x] == 'P')
                mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.position.img_start, (16 * x), (16 * y));
            x++;
        }
        y++;
        x = 0;
    }
}
