/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:58:44 by akahir            #+#    #+#             */
/*   Updated: 2025/04/08 13:58:44 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"

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

// Fractal calculation functions
int		mandelbrot(t_complex c, int max_iter);
int		julia(t_complex z, t_complex k, int max_iter);

// Rendering functions
void	ft_render_fractal(t_data *data);

// Event handling functions
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		close_window(t_data *data);

// Util functions
double	ft_atoi(const char *str);
int ft_strcmp(const char *s1, const char *s2);
void mlx_functions(t_data data);

#endif
