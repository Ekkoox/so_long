/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/18 17:00:26 by enschnei         ###   ########.fr       */
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

int input(int keycode, t_vars *vars) 
{
    int moveX; 
	int moveY;
	
	moveX = 0;
	moveY = 0;
    if (keycode == 100 || keycode == 65363)
        moveX = 1;
    else if (keycode == 97 || keycode == 65361)
        moveX = -1;
    else if (keycode == 119 || keycode == 65362)
        moveY = -1;
    else if (keycode == 115 || keycode == 65364)
        moveY = 1;
    if (!wall_colision(vars, moveX, moveY)) 
	{
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor, vars->player.x * 64, vars->player.y * 64);
        vars->player.x += moveX;
        vars->player.y += moveY;
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_char, vars->player.x * 64, vars->player.y * 64);
    }
    return 0;
}
