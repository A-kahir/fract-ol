/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:58:35 by akahir            #+#    #+#             */
/*   Updated: 2025/04/08 13:58:35 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_print_usage(void)
{
	write(1, "Usage: ./fractol [fractal_type]\n", 33);
	write(1, "Available fractals_type:\n", 26);
	write(1, "  1: Mandelbrot\n", 17);
	write(1, "  2: Julia\n", 12);
	exit(0);
}

static	void	ft_init_data(t_data *data)
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

static	int	ft_init_window(t_data *data)
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
		ft_print_usage();
	ft_init_data(&data);
	data.fractal_type = ft_atoi(argv[1]);
	if (data.fractal_type < 1 || data.fractal_type > 2)
		ft_print_usage();
	if (!ft_init_window(&data))
		return (write(1, "Error initializing window\n", 27), 1);
	ft_render_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
