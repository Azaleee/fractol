/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:10:58 by mosmont           #+#    #+#             */
/*   Updated: 2025/01/03 19:13:57 by mosmont          ###   ########.fr       */
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
	int		test;

	if (i == fractol->iteration)
		return (0x000000);
	t = (double)i / fractol->iteration;
	if (fractol->color_scheme == 0)
		basic_color(t, &r, &g, &b);
	else if (fractol->color_scheme == 1)
		psy_color(t, &r, &g, &b);
	else if (fractol->color_scheme == 2)
		vortex_color(t, &r, &g, &b);
	else if (fractol->color_scheme == 3)
		inv_polyjssp_color(t, &r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}

void	update_position(int x, int y, t_fractol *fractol)
{
	if (fractol->fractol_type == 0 || fractol->fractol_type == 2)
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
	temp = 0;
	update_position(x, y, fractol);
	z = fractol->z;
	c = fractol->c;
	while (i < fractol->iteration && magnitude_squared <= 4)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		if (fractol->fractol_type == 0 || fractol->fractol_type == 1)
			z.y = 2 * z.x * z.y + c.y;
		else
			z.y = fabs(2 * z.x * z.y) + c.y;
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
