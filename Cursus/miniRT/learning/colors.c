#include <mlx.h>

int		create_trgb(int t, int r, int g, int b)
{
	return (b << 24 | g << 16 | r << 8 | t);
}