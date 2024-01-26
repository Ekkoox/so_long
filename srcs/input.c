/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/26 17:02:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross_close(t_vars *vars)
{
	squid_game(vars);
	exit(0);
}

int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		squid_game(vars);
		exit(0);
	}
	return (0);
}

int	handle_key(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP || keycode == KEY_S
		|| keycode == KEY_DOWN || keycode == KEY_A || keycode == KEY_LEFT
		|| keycode == KEY_D || keycode == KEY_RIGHT)
		return (1);
	else
		return (0);
	return (1);
}

int	input(int keycode, t_vars *vars)
{
	int			moveX;
	int			moveY;
	int 		stash;
	static int	count;
	
	moveX = 0;
	moveY = 0;
	stash = 0;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		stash = input_left(keycode, vars);
 	else if (keycode == KEY_D || keycode == KEY_RIGHT)
 		stash = input_right(keycode, vars);
 	else if (keycode == KEY_S || keycode == KEY_DOWN)
 		stash = input_down(keycode, vars);
 	else if (keycode == KEY_W || keycode == KEY_UP)
 		stash = input_up(keycode, vars);
	if (finish_map(vars) == 1)
		squid_game(vars);
	if(stash == 1)
		ft_printf("%d\n", ++count);
	return(0);
}
