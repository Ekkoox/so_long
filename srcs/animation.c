/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:06 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/26 17:03:26 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_right(int keycode, t_vars *vars)
{
	int	moveX;
	int	moveY;

	moveX = 1;
	moveY = 0;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->imgs.img_right_char, vars->player.x * 64, vars->player.y
			* 64);
		return (1);
	}
	return (0);
}

int	input_up(int keycode, t_vars *vars)
{
	int	moveX;
	int	moveY;

	moveX = 0;
	moveY = -1;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->imgs.img_up_char, vars->player.x * 64, vars->player.y * 64);
		return (1);
	}
	return (0);
}
int	input_down(int keycode, t_vars *vars)
{
	int	moveX;
	int	moveY;

	moveX = 0;
	moveY = 1;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->imgs.img_down_char, vars->player.x * 64, vars->player.y * 64);
		return (1);
	}
	return (0);
}

int	input_left(int keycode, t_vars *vars)
{
	int	moveX;
	int	moveY;

	moveX = -1;
	moveY = 0;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->imgs.img_left_char, vars->player.x * 64, vars->player.y * 64);
		return (1);
	}
	return (0);
}
