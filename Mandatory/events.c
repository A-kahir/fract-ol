#include "fractol.h"

int	close_window(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	else if (keycode == 123)
		data->offset_x -= 0.1 / data->zoom;
	else if (keycode == 124)
		data->offset_x += 0.1 / data->zoom;
	else if (keycode == 125)
		data->offset_y += 0.1 / data->zoom;
	else if (keycode == 126)
		data->offset_y -= 0.1 / data->zoom;
	else if (keycode == 24)
		data->zoom *= 1.2;
	else if (keycode == 27)
		data->zoom /= 1.2;
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - WIDTH / 2.0) / (0.5 * WIDTH * data->zoom) + data->offset_x;
	mouse_im = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * data->zoom) + data->offset_y;
	if (button == 4 || button == 5)
	{
		if (button == 4)
		{
			data->zoom *= 1.2;
			data->offset_x = mouse_re - (mouse_re - data->offset_x) / 1.2;
			data->offset_y = mouse_im - (mouse_im - data->offset_y) / 1.2;
		}
		else if (button == 5)
		{
			data->zoom /= 1.2;
			data->offset_x = mouse_re - (mouse_re - data->offset_x) * 1.2;
			data->offset_y = mouse_im - (mouse_im - data->offset_y) * 1.2;
		}
		render_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}