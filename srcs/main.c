/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:12 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/16 17:57:57 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	(void)ac;
	vars.map = split_map(av[1]);
	check_size(&vars);
	error_map(&vars);
	get_start_position(&vars);
	ft_splitdup(&vars);
	back_track(vars.cpy_map, vars.player.x, vars.player.y);
	back_track_bonus(vars.cpy_map, vars.player.x, vars.player.y);
	impossible_map(&vars);
	impossible_map_bonus(&vars);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, ft_strlen(vars.map[0]) * 64,
			count_ligne_split(vars.map) * 64, "so_long enschnei");
	set_up_img(&vars);
	print_texture1(&vars);
	print_texture2(&vars);
	mlx_hook(vars.mlx_win, 33, 131072, squid_game, &vars);
	mlx_hook(vars.mlx_win, 2, 1L, esc_close, &vars);
	mlx_key_hook(vars.mlx_win, input, &vars);
	mlx_loop(vars.mlx);
}
