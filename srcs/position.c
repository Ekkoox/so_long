/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:31:42 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/17 17:35:09 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_start_position(t_vars *vars)
{
	int x;
	int y;
	
	y = 0;
	while(vars->map[y] != NULL)
	{
		x = 0;
		while(vars->map[y][x] != '\0')
		{
			if(vars->map[y][x] == 'P')
			{
				vars->player.x = x;
				vars->player.y = y;
				return;
			}
			x++;
		}
		y++;	
	}
}
void delete_char(t_vars *vars)
{
	int x;
	int y;
	int tmp;

	x = vars->player.x;
	y = vars->player.y;
	
	tmp = vars->map[y][x];
	tmp = mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgs.img_floor, (64 * x), (64 * y));
}