#include "miniRT.h"

int		close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
}

int		main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello world!");
	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
}