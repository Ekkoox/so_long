/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:16:15 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/12 19:14:31 by enschnei         ###   ########.fr       */
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

typedef struct s_imgs {
	void *img_floor;
	void *img_object;
	void *img_wall;
	void *img_exit;
	void *img_char;
}				t_imgs;

typedef struct s_vars {
	void 		*mlx;
	void 		*mlx_win;
	char 		**map;
	t_player	player;
	t_imgs		imgs;
}				t_vars;

int 	input(int keycode, t_vars *vars);
int 	cross_close(t_vars *vars);
char	**split_map(char *path);
void	set_up_img(t_vars *vars);
void	print_imgs(t_vars *vars);
void 	print_texture(t_vars *vars);
void 	get_start_position(t_vars *vars);

#endif