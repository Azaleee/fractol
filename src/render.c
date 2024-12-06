/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:10:58 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 20:00:49 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	pixel_render(t_fractol *fractol, int x, int y, int color)
{
	unsigned int	pixel;

	pixel = (y * fractol->image->size_line + x * (fractol->image->bpp / 8));
	*(unsigned int *)(fractol->image->data + pixel) = color;
}

int	render_color(t_fractol *fractol, int i, double magnitude_squared)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == fractol->iteration)
		return (0x000000);
	t = (double)i / fractol->iteration;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	update_position(int x, int y, t_fractol *fractol)
{
	if (fractol->fractol_type == 0)
	{
		fractol->c.x = fractol->precalcul_x[x];
		fractol->c.y = fractol->precalcul_y[y];
	}
	else
	{
		fractol->z.x = fractol->precalcul_x[x];
		fractol->z.y = fractol->precalcul_y[y];
	}
}

void	calcult(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			i;
	double		magnitude_squared;

	i = 0;
	magnitude_squared = 0;
	z = fractol->z;
	c = fractol->c;
	temp = 0;
	update_position(x, y, fractol);
	while (i < fractol->iteration && magnitude_squared <= 4)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		magnitude_squared = z.x * z.x + z.y * z.y;
		i++;
	}
	pixel_render(fractol, x, y, render_color(fractol, i, magnitude_squared));
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			calcult(x, y, fractol);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx,
		fractol->windows, fractol->image->image, 0, 0);
}
