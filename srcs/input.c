/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/05 17:50:03 by enschnei         ###   ########.fr       */
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

int main()
{
	t_vars vars;

	int i = 0;
	vars.player.x = 0;
	vars.player.y = 0;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "char.xpm", &i, &i);
	mlx_hook(vars.mlx_win, 33, 131072, cross_close, &vars);
	mlx_key_hook(vars.mlx_win, input, &vars);
	mlx_loop(vars.mlx);
}
