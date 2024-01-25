/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/25 18:11:54 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars->mlx);
	exit(0);
}

int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	handle_key(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP || keycode == KEY_S
		|| keycode == KEY_DOWN || keycode == KEY_A || keycode == KEY_LEFT
		|| keycode == KEY_D || keycode == KEY_RIGHT)
		return (1);
	else
		return (0);
	return (1);
}

// int	input(int keycode, t_vars *vars)
// {
// 	int			moveX;
// 	int			moveY;
// 	static int	count;

// 	moveX = 0;
// 	moveY = 0;
// 	if (keycode == KEY_W || keycode == KEY_UP)
// 		moveX = 1;
// 	else if (keycode == KEY_S || keycode == KEY_DOWN)
// 		moveX = -1;
// 	else if (keycode == KEY_A || keycode == KEY_LEFT)
// 		moveY = -1;
// 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
// 		moveY = 1;
// 	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
// 			vars->player.x * 64, vars->player.y * 64);
// 		vars->player.x += moveX;
// 		vars->player.y += moveY;
// 		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_char,
// 			vars->player.x * 64, vars->player.y * 64);
// 		ft_printf("%d\n", ++count);
// 	}
// 	// if (finish_map(vars) == 1)
// 		//faire une fonction qui destroy tout
// 	return (0);
// }
// static int	input_left(int keycode, t_vars *vars)
// {
// 	int			moveX;
// 	int			moveY;
	
// 	moveX = 0;
// 	moveY = 0;
// 	if (keycode == KEY_A || keycode == KEY_LEFT)
// 		moveY = -1;
// 	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
// 	{
// 		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
// 			vars->player.x * 64, vars->player.y * 64);
// 		vars->player.x += moveX;
// 		vars->player.y += moveY;
// 		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_left_char,
// 			vars->player.x * 64, vars->player.y * 64);
// 		// ft_printf("%d\n", ++count);
// 	}
// }

// int	input(int keycode, t_vars *vars)
// {
// 	if (keycode == KEY_A || keycode == KEY_LEFT)
// 		input_left;
// // 	else if (keycode == KEY_S || keycode == KEY_DOWN)
// // 		moveX = -1;
// // 	else if (keycode == KEY_A || keycode == KEY_LEFT)
// // 		moveY = -1;
// // 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
// // 		moveY = 1;
// }
