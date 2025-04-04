#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITERATIONS 100

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fractal_type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_complex	julia_k;
}	t_data;

// Initialization functions
void	init_data(t_data *data);
int		init_window(t_data *data);

// Fractal calculation functions
int		mandelbrot(t_complex c, int max_iter);
int		julia(t_complex z, t_complex k, int max_iter);
int		burning_ship(t_complex c, int max_iter);

// Rendering functions
void	render_fractal(t_data *data);
void	pixel_put(t_data *data, int x, int y, int color);

// Event handling functions
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		close_window(t_data *data);

// Utility functions
int		create_trgb(int t, int r, int g, int b);
void	print_usage(void);

#endif
