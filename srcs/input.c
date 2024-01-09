/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/09 19:05:06 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int cross_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars->mlx);
	exit(0);
}

int input(int keycode, t_vars *vars)
{
	if(keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		free(vars->mlx);
		exit(0);
	}
	else if (keycode == 100 || keycode == 65363)
		vars->player.x += 64;
	else if (keycode == 97 || keycode == 65361)
		vars->player.x -= 64;
	else if (keycode == 119 || keycode == 65362)
		vars->player.y -= 64;
	else if (keycode == 115 || keycode == 65364)
		vars->player.y += 64;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->player.x, vars->player.y);
	return(0);
}
