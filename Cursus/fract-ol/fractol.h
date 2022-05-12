/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:10:05 by marvin            #+#    #+#             */
/*   Updated: 2021/06/15 13:51:50 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# include <pthread.h>

typedef struct s_map
{
	int			y_min;
	double		d_r;
	double		d_i;
	double		z_r;
	double		z_i;
}				t_map;

typedef struct s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sz_l;
	int			endian;
	int			sz_i;
	int			fractal;
	t_map		*map;
	double		zd_r;
	double		zd_i;
	double		julia_r;
	double		julia_i;
	double		os_i;
	double		os_r;
	double		zoom;
	int			r;
	int			g;
	int			b;
	int			lock;
	int			imax;
	int			threads_max;
	int			threads_min;
	double		winx;
	double		winy;
}				t_env;

int				key_hook(int keycode, void *e_void);
int				mouse_hook(int button, int x, int y, void *e_void);
int				cursor_hook(int x, int y, void *e_void);
int				check_arg(char *arg);
int				check_mandelbrot(char *str);
int				check_julia(char *str);
int				check_black_hole(char *str);
void			init_env(t_env *e, int x);
void			draw(t_env *e);
void			mouse_hook2(int x, int y, t_env *e);
void			compute(int x, int y, t_env *e);
void			mandelbrot_compute(int x, int y, t_env *e);
void			julia_compute(int x, int y, t_env *e);
void			black_hole_compute(int x, int y, t_env *e);
void			pixel_put(t_env *e, int i, int x, int y);
void			*draw_0(void *e_void);
void			*draw_1(void *e_void);
void			*draw_2(void *e_void);
void			*draw_3(void *e_void);
void			*draw_4(void *e_void);
void			*draw_5(void *e_void);
void			*draw_6(void *e_void);
void			*draw_7(void *e_void);

#endif
