/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:12 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/25 17:35:03 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_vars vars;
	(void)ac;
	
	vars.map = split_map(av[1]);
	if(error_map(&vars) == 0)
		exit(0);
	get_start_position(&vars);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "so_long enschnei");
	set_up_img(&vars);
	print_texture(&vars);
	mlx_hook(vars.mlx_win, 33, 131072, cross_close, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, esc_close, &vars);
	mlx_key_hook(vars.mlx_win, input, &vars);
	if (finish_map(&vars) == 1)
		mlx_destroy_window(vars.mlx, vars.mlx_win);
	mlx_loop(vars.mlx);
}