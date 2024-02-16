/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:55:35 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/16 18:06:12 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	secure_img(t_vars *vars)
{
	if (!vars->imgs.chara)
		squid_game(vars);
	if (!vars->imgs.left_char)
		squid_game(vars);
	if (!vars->imgs.right_char)
		squid_game(vars);
	if (!vars->imgs.up_char)
		squid_game(vars);
	if (!vars->imgs.down_char)
		squid_game(vars);
	if (!vars->imgs.floor)
		squid_game(vars);
	if (!vars->imgs.object)
		squid_game(vars);
	if (!vars->imgs.wall)
		squid_game(vars);
	if (!vars->imgs.exit)
		squid_game(vars);
	if (!vars->imgs.enemy)
		squid_game(vars);
}

void	set_up_img(t_vars *vars)
{
	int	x;

	x = 64;
	vars->imgs.chara = mlx_xpm_file_to_image(vars->mlx, "sprite/char.xpm", &x,
			&x);
	vars->imgs.left_char = mlx_xpm_file_to_image(vars->mlx,
			"sprite/char_left.xpm", &x, &x);
	vars->imgs.right_char = mlx_xpm_file_to_image(vars->mlx,
			"sprite/char_right.xpm", &x, &x);
	vars->imgs.up_char = mlx_xpm_file_to_image(vars->mlx, "sprite/char_up.xpm",
			&x, &x);
	vars->imgs.down_char = mlx_xpm_file_to_image(vars->mlx,
			"sprite/char_down.xpm", &x, &x);
	vars->imgs.floor = mlx_xpm_file_to_image(vars->mlx, "sprite/floor.xpm", &x,
			&x);
	vars->imgs.object = mlx_xpm_file_to_image(vars->mlx, "sprite/object.xpm",
			&x, &x);
	vars->imgs.wall = mlx_xpm_file_to_image(vars->mlx, "sprite/wall.xpm", &x,
			&x);
	vars->imgs.exit = mlx_xpm_file_to_image(vars->mlx, "sprite/exit.xpm", &x,
			&x);
	vars->imgs.enemy = mlx_xpm_file_to_image(vars->mlx, "sprite/enemy.xpm", &x,
			&x);
	secure_img(vars);
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
					vars->imgs.wall, (64 * x), (64 * y));
			else if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.floor, (64 * x), (64 * y));
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.object, (64 * x), (64 * y));
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
					vars->imgs.exit, (64 * x), (64 * y));
			else if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.chara, (64 * x), (64 * y));
			else if (BONUS == 1 && vars->map[y][x] == 'M')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgs.enemy, (64 * x), (64 * y));
			x++;
		}
		y++;
		x = 0;
	}
}
