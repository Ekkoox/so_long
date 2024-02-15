/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:55:35 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/15 18:22:52 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_up_img(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->imgs.img_char = mlx_xpm_file_to_image(vars->mlx, "sprite/char.xpm",
			&x, &y);
	vars->imgs.img_left_char = mlx_xpm_file_to_image(vars->mlx,
			"sprite/char_left.xpm", &x, &y);
	vars->imgs.img_right_char = mlx_xpm_file_to_image(vars->mlx,
			"sprite/char_right.xpm", &x, &y);
	vars->imgs.img_up_char = mlx_xpm_file_to_image(vars->mlx,
			"sprite/char_up.xpm", &x, &y);
	vars->imgs.img_down_char = mlx_xpm_file_to_image(vars->mlx,
			"sprite/char_down.xpm", &x, &y);
	vars->imgs.img_floor = mlx_xpm_file_to_image(vars->mlx, "sprite/floor.xpm",
			&x, &y);
	vars->imgs.img_object = mlx_xpm_file_to_image(vars->mlx,
			"sprite/object.xpm", &x, &y);
	vars->imgs.img_wall = mlx_xpm_file_to_image(vars->mlx, "sprite/wall.xpm",
			&x, &y);
	vars->imgs.img_exit = mlx_xpm_file_to_image(vars->mlx, "sprite/exit.xpm",
			&x, &y);
	vars->imgs.img_enemy = mlx_xpm_file_to_image(vars->mlx, "sprite/enemy.xpm",
			&x, &y);
}

void	print_texture1(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (vars->map[y] != 0)
	{
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.img_wall, (64 * x), (64 * y));
			else if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.img_floor, (64 * x), (64 * y));
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.img_object, (64 * x), (64 * y));
			x++;
		}
		y++;
		x = 0;
	}
}

void	print_texture2(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (vars->map[y] != 0)
	{
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.img_exit, (64 * x), (64 * y));
			else if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.img_char, (64 * x), (64 * y));
			else if (BONUS == 1 && vars->map[y][x] == 'M')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.img_enemy, (64 * x), (64 * y));
			x++;
		}
		y++;
		x = 0;
	}
}
