/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:31:42 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/15 18:23:37 by enschnei         ###   ########.fr       */
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

int	wall_colision(t_vars *vars, int move_x, int move_y)
{
	size_t	new_x;
	size_t	new_y;

	new_x = vars->player.x + move_x;
	new_y = vars->player.y + move_y;
	if (new_x < 0 || new_x >= ft_strlen(vars->map[0]) || new_y < 0
		|| new_y >= count_ligne_split(vars->map)
		|| vars->map[new_y][new_x] == '1')
		return (1);
	if (count_object(vars) != 0 && vars->map[new_y][new_x] == 'E')
		return (1);
	return (0);
}

int	count_object(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	vars->count.count_C = 0;
	while (vars->map[y] != NULL)
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				vars->count.count_C++;
			x++;
		}
		x = 0;
		y++;
	}
	return (vars->count.count_C);
}

int	finish_map(t_vars *vars)
{
	int	object;

	object = count_object(vars);
	if (vars->map[vars->player.y][vars->player.x] == 'C')
	{
		vars->map[vars->player.y][vars->player.x] = '0';
		object--;
	}
	if (object == 0 && vars->map[vars->player.y][vars->player.x] == 'E')
		return (1);
	return (0);
}
