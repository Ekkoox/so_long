/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/17 18:36:37 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars->mlx);
	exit(0);
}

int esc_close(int keycode, t_vars *vars)
{	
	if(keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		free(vars->mlx);
		exit(0);
	}
	return(0);
}

int	input(int keycode, t_vars *vars)
{
	if (keycode == 100 || keycode == 65363)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor, vars->player.x * 64, vars->player.y * 64);
		vars->player.x += 1;
	}
	else if (keycode == 97 || keycode == 65361)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor, vars->player.x * 64, vars->player.y * 64);
		vars->player.x -= 1;
	}
	else if (keycode == 119 || keycode == 65362)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor, vars->player.x * 64, vars->player.y * 64);
		vars->player.y -= 1;
	}
	else if (keycode == 115 || keycode == 65364)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor, vars->player.x * 64, vars->player.y * 64);
		vars->player.y += 1;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_char, vars->player.x * 64, vars->player.y * 64);
	return (0);
}
