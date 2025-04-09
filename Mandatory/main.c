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
	write(2, "Usage: ./fractol [fractal_type] [params]\n", 41);
	write(2, "Available fractals:\n", 20);
	write(2, "  mandelbrot\n", 13);
	write(2, "  julia [real] [imaginary]\n", 27);
	write(2, "Examples:\n", 10);
	write(2, "  ./fractol mandelbrot\n", 23);
	write(2, "  ./fractol julia -0.8 0.156\n", 29);
	exit(1);
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
	data->julia_k.real = 0.0;
	data->julia_k.imag = 0.0;
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

	ft_init_data(&data);
	if (argc < 2)
		ft_print_usage();
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		data.fractal_type = 1;
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		data.fractal_type = 2;
		if (argc == 4)
		{
			data.julia_k.real = ft_atoi(argv[2]);
			data.julia_k.imag = ft_atoi(argv[3]);
		}
		else if (argc != 2)
			ft_print_usage();
	}
	else
		ft_print_usage();
	if (!ft_init_window(&data))
		return (write(1, "Error initializing window\n", 27), 1);
	ft_render_fractal(&data);
	mlx_functions(data);
	return (0);
}
