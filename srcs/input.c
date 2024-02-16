/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:56:19 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/16 17:14:35 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_img(t_vars *vars)
{
	if (vars->imgs.wall)
		mlx_destroy_image(vars->mlx, vars->imgs.wall);
	if (vars->imgs.chara)
		mlx_destroy_image(vars->mlx, vars->imgs.chara);
	if (vars->imgs.left_char)
		mlx_destroy_image(vars->mlx, vars->imgs.left_char);
	if (vars->imgs.right_char)
		mlx_destroy_image(vars->mlx, vars->imgs.right_char);
	if (vars->imgs.up_char)
		mlx_destroy_image(vars->mlx, vars->imgs.up_char);
	if (vars->imgs.down_char)
		mlx_destroy_image(vars->mlx, vars->imgs.down_char);
	if (vars->imgs.floor)
		mlx_destroy_image(vars->mlx, vars->imgs.floor);
	if (vars->imgs.exit)
		mlx_destroy_image(vars->mlx, vars->imgs.exit);
	if (vars->imgs.object)
		mlx_destroy_image(vars->mlx, vars->imgs.object);
	if (vars->imgs.enemy)
		mlx_destroy_image(vars->mlx, vars->imgs.enemy);
}

int	squid_game(t_vars *vars)
{
	destroy_img(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	ft_free(vars->map, count_ligne_split(vars->map));
	ft_free(vars->cpy_map, count_ligne_split(vars->cpy_map));
	free(vars->mlx);
	exit(0);
	return (69);
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
	int			stash;
	static int	count;

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
	{
		ft_printf("GOOD JOB ! You finish the map with %d step !\n", count);
		squid_game(vars);
	}
	if (death_char(vars) == 1)
	{
		ft_printf("!!! GAME OVER !!! YOU ARE DEAD !\n");
		squid_game(vars);
	}
	if (stash == 1)
		ft_printf("%d\n", ++count);
	return (0);
}
