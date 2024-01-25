/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:06 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/25 18:34:10 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	input_up(int keycode, t_vars *vars)
{
	int			moveX;
	int			moveY;
	
	moveX = 1;
	moveY = 0;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_right_char,
			vars->player.x * 64, vars->player.y * 64);
	}
}

static void	input_left(int keycode, t_vars *vars)
{
	int			moveX;
	int			moveY;
	
	moveX = 0;
	moveY = -1;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_up_char,
			vars->player.x * 64, vars->player.y * 64);
	}
}
static void	input_right(int keycode, t_vars *vars)
{
	int			moveX;
	int			moveY;
	
	moveX = 0;
	moveY = 1;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_down_char,
			vars->player.x * 64, vars->player.y * 64);
	}
}

static void	input_down(int keycode, t_vars *vars)
{
	int			moveX;
	int			moveY;
	
	moveX = -1;
	moveY = 0;
	if (!wall_colision(vars, moveX, moveY) && handle_key(keycode) == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor,
			vars->player.x * 64, vars->player.y * 64);
		vars->player.x += moveX;
		vars->player.y += moveY;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_left_char,
			vars->player.x * 64, vars->player.y * 64);
	}
}

int	input(int keycode, t_vars *vars)
{
	// static int	count;
	
	if (keycode == KEY_A || keycode == KEY_LEFT)
		input_left(keycode, vars);
 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
 		input_right(keycode, vars);
 	else if (keycode == KEY_S || keycode == KEY_DOWN)
 		input_down(keycode, vars);
 	else if (keycode == KEY_W || keycode == KEY_UP)
 		input_up(keycode, vars);
	// ft_printf("%d\n", ++count);
	return(0);
}
