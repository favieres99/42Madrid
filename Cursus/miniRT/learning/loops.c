#include <mlx.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		j;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		render_next_frame(void *img)
{
	img->i++;
	img->j++;
	my_mlx_pixel_put(&img, img->i, img->j, 0x00FF0000);
	return (0);
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img.i = 0;
	img.j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop_hook(mlx, render_next_frame, &img);
	mlx_loop(mlx);
}

