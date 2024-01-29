/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:13:34 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/29 18:00:12 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_first_line(t_vars *vars)
{
	int	x;

	x = 0;
	while (vars->map[0][x] == '1')
		x++;
	return (vars->map[0][x] == '\0');
}

// int check_last_line(t_vars *vars)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	x = ft_strlen(vars->map[y] - 1);
// 	while (vars->map[y] != NULL)
// 		y++;
// 	while (vars->map[y][x] == '1')
// 		x--;
// 	return (vars->map[y][x] == '\0');
// }

int check_first_column(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[y][0] == '1' && vars->map[y][0])
		y++;
	return (vars->map[y][0] == '\0');
}

// int check_last_coulumn(t_vars *vars)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (vars->map[y] != NULL)
// 		y++;
// 	while (vars->map[y][x] == '1')
// 			x--;
// 	return (vars->map[y][x] == '\0');
// }


