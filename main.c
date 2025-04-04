#include "fractol.h"

void	print_usage(void)
{
	printf("Usage: ./fractol [fractal_type]\n");
	printf("Available fractals:\n");
	printf("  1: Mandelbrot\n");
	printf("  2: Julia\n");
	printf("  3: Burning Ship\n");
	exit(0);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->julia_k.real = -0.8;
	data->julia_k.imag = 0.156;
}

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_usage();
	init_data(&data);
	data.fractal_type = atoi(argv[1]);
	if (data.fractal_type < 1 || data.fractal_type > 3)
		print_usage();
	if (!init_window(&data))
	{
		printf("Error initializing window\n");
		return (1);
	}
	render_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
