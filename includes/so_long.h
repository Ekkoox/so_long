/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:16:15 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/08 18:57:39 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

typedef struct s_player {
	int x;
	int y;
}				t_player;

typedef struct s_position {
	void *img_floor;
	void *img_object;
	void *img_wall;
	void *img_exit;
	void *img_start;
}

typedef struct s_vars {
	void *mlx;
	void *mlx_win;
	void *img;
	t_player player;
}				t_vars;

int input(int keycode, t_vars *vars);
int cross_close(t_vars *vars);
char *read_map(char *path);
char **split_map(char *path);

#endif