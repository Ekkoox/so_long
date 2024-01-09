/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:12 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/09 19:10:14 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_vars vars;
	(void)ac;
	char **map;
	int x;
	int y;
	
	x = 0;
	y = 0;
	map = split_map(av[1]);
	vars.player.x = 0;
	vars.player.y = 0;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "char.xpm", &x, &y);
	mlx_hook(vars.mlx_win, 33, 131072, cross_close, &vars);
	mlx_key_hook(vars.mlx_win, input, &vars);
	// mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, vars.player.x, vars.player.y);
	mlx_loop(vars.mlx);
}