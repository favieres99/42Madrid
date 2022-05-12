#include <mlx.h>
#include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i = 100, j = 100, k = 0, x = 0, y = 0;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//CUADRADO
	while (i < 160)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i++;
	}
	while (j < 160)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j++;
	}
	while (i >= 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i--;
	}
	while (j >= 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j--;
	}
	//TRIANGULO
	i = 350, j = 100;
	while (i < 390)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF00);
		if (j % 2 == 0)
			i++;
		j++;
	}
	while (i >= 310)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF00);
		i--;
	}
	while (i < 350)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF00);
		if (j % 2 == 0)
			i++;
		j--;
	}
	//HEXAGONO
	i = 100, j = 350;
	while (i < 140)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		i++;
	}
	while (i < 160)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		if (j % 2 == 0)
			i++;
		j++;
	}
	while (i >= 140)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		if (j % 2 == 0)
			i--;
		j++;
	}
	while (i >= 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		i--;
	}
	while (i >= 80)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		if (j % 2 == 0)
			i--;
		j--;
	}
	while (i < 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x000000FF);
		if (j % 2 == 0)
			i++;
		j--;
	}
	//CIRCULO
	while (k < 3600)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
		x = 750 + 300 * cos(k);
		y = 750 + 300 * sin(k);
		k++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}