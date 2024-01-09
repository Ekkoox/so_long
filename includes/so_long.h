/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:16:15 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/09 19:08:32 by enschnei         ###   ########.fr       */
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
}				t_position;

typedef struct s_vars {
	void *mlx;
	void *mlx_win;
	void *img;
	t_player player;
	t_position position;
}				t_vars;

int main(int ac, char **av);
int input(int keycode, t_vars *vars);
int cross_close(t_vars *vars);
char **split_map(char *path);
void	set_up_img(t_vars vars);
void print_imgs(t_vars vars, char **map);

#endif