#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include <X11/Xlib.h>

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


int input(int keycode, t_vars *vars)
{
	if (keycode == 100 || keycode == 65363)
		vars->player.x += 64;
	else if (keycode == 97 || keycode == 65361)
		vars->player.x -= 64;
	else if (keycode == 119 || keycode == 65362)
		vars->player.y -= 64;
	else if (keycode == 115 || keycode == 65364)
		vars->player.y += 64;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->player.x, vars->player.y);
	return(0);
}

int main()
{
	t_vars vars;

	int i = 0;
	vars.player.x = 0;
	vars.player.y = 0;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "char.xpm", &i, &i);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 64, 64);
	mlx_key_hook(vars.mlx_win, input, &vars);
	mlx_loop(vars.mlx);
}