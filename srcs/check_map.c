/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:25:56 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/25 17:17:39 by enschnei         ###   ########.fr       */
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

int error_map(t_vars *vars)
{
	int error_start;
	int error_exit;
	int error_object;

	error_start = count_start(vars);
	error_exit = count_exit(vars);
	error_object = count_object(vars);
	if(error_start >= 2 || error_exit >= 2 || error_object == 0)
	{
		ft_printf("Invalid map !");
		return(0);	
	}
	return(1);
}
