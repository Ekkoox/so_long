/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:08 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/16 16:28:22 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	back_track_bonus(char **split, int x, int y)
{
	if (BONUS == 1)
	{
		if (split[y][x] == 'E')
			split[y][x] = 'e';
		if (split[y][x] == 'M')
			split[y][x] = 'm';
		else
			split[y][x] = 'G';
		if (split[y - 1][x] != '1' && split[y - 1][x] != 'G'
			&& split[y][x] != 'e' && split[y][x] != 'm')
			back_track_bonus(split, x, y - 1);
		if (split[y + 1][x] != '1' && split[y + 1][x] != 'G'
			&& split[y][x] != 'e' && split[y][x] != 'm')
			back_track_bonus(split, x, y + 1);
		if (split[y][x - 1] != '1' && split[y][x - 1] != 'G'
			&& split[y][x] != 'e' && split[y][x] != 'm')
			back_track_bonus(split, x - 1, y);
		if (split[y][x + 1] != '1' && split[y][x + 1] != 'G'
			&& split[y][x] != 'e' && split[y][x] != 'm')
			back_track_bonus(split, x + 1, y);
	}
}

int	death_char(t_vars *vars)
{
	if (vars->map[vars->player.y][vars->player.x] == 'M')
		return (1);
	return (0);
}
