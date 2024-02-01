/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:16:15 by enschnei          #+#    #+#             */
/*   Updated: 2024/02/01 12:30:13 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_count
{
	int			count_P;
	int			count_E;
	int			count_C;
}				t_count;

typedef struct s_imgs
{
	void		*img_floor;
	void		*img_object;
	void		*img_wall;
	void		*img_exit;
	void		*img_char;
	void		*img_left_char;
	void		*img_right_char;
	void		*img_up_char;
	void		*img_down_char;
}				t_imgs;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	char		*map_x;
	char		*map_y;
	char		**map;
	char		**cpy_map;
	t_player	player;
	t_imgs		imgs;
	t_count		count;
}				t_vars;

enum			keys
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_UP = 65362,
	KEY_S = 115,
	KEY_DOWN = 65364,
	KEY_A = 97,
	KEY_LEFT = 65361,
	KEY_D = 100,
	KEY_RIGHT = 65363,
};

int				input(int keycode, t_vars *vars);
int				input_up(int keycode, t_vars *vars);
int				input_left(int keycode, t_vars *vars);
int				input_right(int keycode, t_vars *vars);
int				input_down(int keycode, t_vars *vars);
int				esc_close(int keycode, t_vars *vars);
int				cross_close(t_vars *vars);
int				wall_colision(t_vars *vars, int moveX, int moveY);
int				error_map(t_vars *vars);
int				finish_map(t_vars *vars);
int				count_object(t_vars *vars);
int				handle_key(int keycode);
int				impossible_map(t_vars *vars);
int				check_first_line(t_vars *vars);
int				check_last_line(t_vars *vars);
int				check_first_column(t_vars *vars);
int				check_last_column(t_vars *vars);
int				check_size(t_vars *vars);
char			**split_map(char *path);
void			squid_game(t_vars *vars);
void			set_up_img(t_vars *vars);
void			print_imgs(t_vars *vars);
void			print_texture(t_vars *vars);
void			get_start_position(t_vars *vars);
void			delete_char(t_vars *vars);
void			ft_splitdup(t_vars *vars);
void			back_track(char **split, int x, int y);
size_t			count_ligne_split(char **split);

#endif