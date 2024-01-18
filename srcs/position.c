/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:31:42 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/18 17:29:08 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_start_position(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'P')
			{
				vars->player.x = x;
				vars->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
int	wall_colision(t_vars *vars, int moveX, int moveY)
{
	int	newX;
	int	newY;

	// int len;
	newX = vars->player.x + moveX;
	newY = vars->player.y + moveY;
	if (newX < 0 || newX >= 30 || newY < 0 || newY >= 16
		|| vars->map[newY][newX] == '1') // modifier les valeurs
		return (1);
	return (0);
}

// void	harvest_object(t_vars *vars)
// {

// }