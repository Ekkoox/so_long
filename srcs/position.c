/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:31:42 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/23 16:22:02 by enschnei         ###   ########.fr       */
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
	size_t	newX;
	size_t	newY;

	// int count;
	// count = 0;
	newX = vars->player.x + moveX;
	newY = vars->player.y + moveY;
	if (newX < 0 || newX >= ft_strlen(vars->map[0]) || newY < 0
		|| newY >= count_ligne_split(vars->map[0])
		|| vars->map[newY][newX] == '1')
		return (1);
	return (0);
}

// int	harvest_object(t_vars *vars)
// {

// }