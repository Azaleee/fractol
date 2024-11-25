/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:10:58 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/25 01:22:01 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	pixel_render(t_fractol *fractol, int x, int y, int color)
{
	*(unsigned int*)(fractol->image->data + (y * fractol->image->size_line + x * (fractol->image->bpp / 8))) = color;
}

double	x_to_plan(int x, t_fractol *fractol)
{
	return ((x * ((1.0 - (-2.0)) / (double)WIDTH) + (-2.0)) / fractol->zoom + fractol->offset_x);
}

double	y_to_plan(int y, t_fractol *fractol)
{
	return ((-y * ((1.5 - (-1.5)) / (double)HEIGHT) + 1.5) / fractol->zoom + fractol->offset_y);
}

void	calcult(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex julia_c = {-0.4, 0.6};
	double		temp;
	int			i;
	int			color;

	i = 0;
	z.x = x_to_plan(x, fractol);
	z.y = y_to_plan(y, fractol);
	while (i < fractol->iteration)
	{
		temp = (z.x * z.x) - (z.y * z.y) + julia_c.x;
		z.y = 2 * z.x * z.y + julia_c.y;
		z.x = temp;
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		i++;
	}
	if (i == fractol->iteration)
		color = 0x000000;
	else
		color = (i * 255) / fractol->iteration;
	pixel_render(fractol, x, y, color);
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
	mlx_put_image_to_window(fractol->mlx, fractol->windows, fractol->image->image, 0, 0);
	printf("render\n");
}