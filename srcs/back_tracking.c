/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:30:47 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/05 14:37:59 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_splitdup(t_vars *vars)
{
	size_t	len;
	size_t	y;

	len = count_ligne_split(vars->map);
	y = 0;
	vars->cpy_map = malloc(sizeof(char *) * (len + 1));
	if (!vars->cpy_map)
		return (free(vars->cpy_map));
	while (y < len)
	{
		vars->cpy_map[y] = ft_strdup(vars->map[y]);
		if (!vars->cpy_map[y])
			return (free(vars->cpy_map[y]));
		y++;
	}
	vars->cpy_map[y] = NULL;
}

void	back_track(char **split, int x, int y)
{
	if (split[y][x] == 'E')
		split[y][x] = 'e';
	else
		split[y][x] = 'G';
	if (split[y - 1][x] != '1' && split[y - 1][x] != 'G' && split[y][x] != 'e')
		back_track(split, x, y - 1);
	if (split[y + 1][x] != '1' && split[y + 1][x] != 'G' && split[y][x] != 'e')
		back_track(split, x, y + 1);
	if (split[y][x - 1] != '1' && split[y][x - 1] != 'G' && split[y][x] != 'e')
		back_track(split, x - 1, y);
	if (split[y][x + 1] != '1' && split[y][x + 1] != 'G' && split[y][x] != 'e')
		back_track(split, x + 1, y);
}

int	impossible_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->cpy_map[y])
	{
		x = 0;
		while (vars->cpy_map[y][x])
		{
			if (vars->cpy_map[y][x] == 'C' || vars->cpy_map[y][x] == 'E')
			{
				ft_printf("!!! ERROR !!! The map can't be finished !\n");
				ft_free(vars->map, count_ligne_split(vars->map));
				ft_free(vars->cpy_map, count_ligne_split(vars->cpy_map));
				exit(0);
			}
			x++;
		}
		y++;
	}
	return (0);
}
