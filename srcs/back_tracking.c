/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:30:47 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/26 18:13:47 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void valide_map(char **split, int x, int y)
{
	split[y][x] = 'G';
	if (split[y - 1][x] != '1')
		valide_map(split, x, y - 1);
	if (split[y + 1][x] != '1')
		valide_map(split, x, y + 1);
	if (split[y][x - 1] != '1')
		valide_map(split, x - 1, y);
	if (split[y][x + 1] != '1')
		valide_map(split, x + 1, y);
}
// pense a free les images de tes deplacement