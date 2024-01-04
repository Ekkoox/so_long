/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:16:15 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/04 21:20:27 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/mlx/mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h> 

typedef struct s_player {
	int x;
	int y;
}				t_player;

typedef struct s_vars {
	void *mlx;
	void *mlx_win;
	void *img;
	t_player player;
}				t_vars;

#endif