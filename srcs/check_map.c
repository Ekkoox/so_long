/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:25:56 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/15 18:23:50 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_start(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	vars->count.count_P = 0;
	while (vars->map[y] != NULL)
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
				vars->count.count_P++;
			x++;
		}
		x = 0;
		y++;
	}
	return (vars->count.count_P);
}

static int	count_exit(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	vars->count.count_E = 0;
	while (vars->map[y] != NULL)
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'E')
				vars->count.count_E++;
			x++;
		}
		x = 0;
		y++;
	}
	return (vars->count.count_E);
}

static int	check_other_characters(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (vars->map[y] != NULL)
	{
		while (vars->map[y][x])
		{
			if (BONUS != 1 && vars->map[y][x] != '1' && vars->map[y][x] != '0'
				&& vars->map[y][x] != 'C' && vars->map[y][x] != 'E'
				&& vars->map[y][x] != 'P')
				return (0);
			if (BONUS == 1 && vars->map[y][x] != '1' && vars->map[y][x] != '0'
				&& vars->map[y][x] != 'C' && vars->map[y][x] != 'E'
				&& vars->map[y][x] != 'P' && vars->map[y][x] != 'M')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	error_map(t_vars *vars)
{
	if (count_start(vars) != 1 || count_exit(vars) != 1
		|| count_object(vars) == 0 || check_other_characters(vars) == 0)
	{
		ft_printf("!!! ERROR !!! Invalid map !\n");
		ft_free(vars->map, count_ligne_split(vars->map));
		return (0);
	}
	if (check_first_line(vars) == 0 || check_last_column(vars) == 0
		|| check_last_line(vars) == 0 || check_first_column(vars) == 0)
	{
		ft_printf("!!! ERROR !!! The map is not surrounded by obstacles !\n");
		ft_free(vars->map, count_ligne_split(vars->map));
		return (0);
	}
	return (1);
}
