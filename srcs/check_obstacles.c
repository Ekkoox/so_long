/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obstacles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:13:34 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/31 18:33:41 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_line(t_vars *vars)
{
	int	x;

	x = 0;
	while (vars->map[0][x] == '1')
		x++;
	return (vars->map[0][x] == '\0');
}

int	check_last_line(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = ft_strlen(vars->map[0]);
	while (vars->map[y] != NULL)
		y++;
	y--;
	while (x >= 0 && vars->map[y][x - 1] == '1')
		x--;
	return (x == 0);
}

int	check_first_column(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[y] && vars->map[y][0] == '1')
		y++;
	return (vars->map[y] == NULL);
}

int	check_last_column(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[y] != NULL && vars->map[y][ft_strlen(vars->map[y]) - 1] == '1')
	{
		y++;
	}
	return (vars->map[y] == NULL);
}

int	check_size(t_vars *vars)
{
	int first_line;
	int last_line;

	first_line = ft_strlen(vars->map[0]);
	last_line = ft_strlen(vars->map[count_ligne_split(vars->map) - 1]);
	if (first_line != last_line)
	{
		ft_printf("!!! ERROR !!! The map is not rectangular !\n");
		ft_free(vars->map, count_ligne_split(vars->map));
		return(0);		
	}
	return(1);
}

// gerer lerror des lignes vides