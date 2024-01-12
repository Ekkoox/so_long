/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:31:42 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/12 19:00:14 by enschnei         ###   ########.fr       */
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
				vars->player.x = x * 64;
				vars->player.y = y * 64;
				return;
			}
			x++;
		}
		y++;	
	}
}