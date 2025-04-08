#include "fractol.h"

static void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static int create_trgb(int t, int r, int b)
{
    return (t << 24 | r << 16 | b);
}

static int get_color(int iterations, int max_iter)
{
    double t;
    int r;
	int b;

    if (iterations == max_iter)
        return (0);

    t = (double)iterations / max_iter;
    r = (int)(60 * (1 - t) * t * t * 255);
    b = (int)(255 * (1 - t) * (1 - t) * (1 - t) * t);
    return (create_trgb(0, r, b));
}

void	render_fractal(t_data *data)
{
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;
	int			iterations;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) / (0.5 * WIDTH * data->zoom)
				+ data->offset_x;
			c.imag = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * data->zoom)
				+ data->offset_y;
			if (data->fractal_type == 1)
				iterations = mandelbrot(c, MAX_ITERATIONS);
			else if (data->fractal_type == 2)
			{
				z.real = c.real;
				z.imag = c.imag;
				iterations = julia(z, data->julia_k, MAX_ITERATIONS);
			}
			pixel_put(data, x, y, get_color(iterations, MAX_ITERATIONS));
			x++;
		}
		y++;
	}
}