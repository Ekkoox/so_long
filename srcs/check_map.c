/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:25:56 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/26 16:23:32 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int count_start(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	x = 0;
	vars->count.count_P = 0;
	while(vars->map[y] != NULL)
	{
		while(vars->map[y][x])
		{
			if(vars->map[y][x] == 'P')
				vars->count.count_P++;
			x++;
		}
		x = 0;
		y++;
	}
	return(vars->count.count_P);
}

static int count_exit(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	x = 0;
	vars->count.count_E = 0;
	while(vars->map[y] != NULL)
	{
		while(vars->map[y][x])
		{
			if(vars->map[y][x] == 'E')
				vars->count.count_E++;
			x++;
		}
		x = 0;
		y++;
	}
	return(vars->count.count_E);
}

void squid_game(t_vars *vars)
{
    if (vars->imgs.img_wall)
        mlx_destroy_image(vars->mlx, vars->imgs.img_wall);
    if (vars->imgs.img_char)
        mlx_destroy_image(vars->mlx, vars->imgs.img_char);
    if (vars->imgs.img_floor)
        mlx_destroy_image(vars->mlx, vars->imgs.img_floor);
    if (vars->imgs.img_exit)
        mlx_destroy_image(vars->mlx, vars->imgs.img_exit);
    if (vars->imgs.img_object)
        mlx_destroy_image(vars->mlx, vars->imgs.img_object);
    mlx_destroy_window(vars->mlx, vars->mlx_win);
    mlx_destroy_display(vars->mlx);
    ft_free(vars->map, count_ligne_split(vars->map) + 1);
    free(vars->mlx);
    exit(0);
}

int error_map(t_vars *vars)
{
	int error_start;
	int error_exit;
	int error_object;

	error_start = count_start(vars);
	error_exit = count_exit(vars);
	error_object = count_object(vars);
	if(error_start != 1 || error_exit != 1 || error_object == 0)
	{
		ft_printf("Invalid map !");
		ft_free(vars->map, count_ligne_split(vars->map));
		return(0);	
	}
	return(1);
}
