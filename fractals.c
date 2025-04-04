#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp;
	int			i;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		i++;
	}
	return (i);
}

int	julia(t_complex z, t_complex k, int max_iter)
{
	double	temp;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		temp = z.real * z.real - z.imag * z.imag + k.real;
		z.imag = 2 * z.real * z.imag + k.imag;
		z.real = temp;
		i++;
	}
	return (i);
}

int	burning_ship(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp;
	int			i;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		z.real = fabs(z.real);
		z.imag = fabs(z.imag);
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		i++;
	}
	return (i);
}