/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:55:34 by mosmont           #+#    #+#             */
/*   Updated: 2025/01/03 19:05:29 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->iteration = MAX_ITERATION;
	fractol->zoom = 1.0;
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->image->colors = 0;
	fractol->precalcul_x = malloc(WIDTH * sizeof(double));
	fractol->precalcul_y = malloc(HEIGHT * sizeof(double));
	fractol->scale_x = ((2 - (-2)) / (double)WIDTH);
	fractol->scale_y = ((2 - (-2)) / (double)HEIGHT);
	fractol->color_scheme = 0;
}

void	init_hook(t_fractol *fractol)
{
	mlx_hook(fractol->windows, 2, 1L << 0, keyboard, fractol);
	mlx_mouse_hook(fractol->windows, mouse, fractol);
	mlx_hook(fractol->windows, 17, 0, destroy_fractol, fractol);
}

void	precalcul_coord(t_fractol *fractol)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		fractol->precalcul_x[x] = x_to_plan(x, fractol);
		x++;
	}
	while (y < HEIGHT)
	{
		fractol->precalcul_y[y] = y_to_plan(y, fractol);
		y++;
	}
}

void	init_fractol_type(int type, char **av, t_fractol *fractol)
{
	if (type == 0 || type == 2)
	{
		if (type == 0)
			fractol->fractol_type = 0;
		else
			fractol->fractol_type = 2;
		fractol->c.x = x_to_plan(0, fractol);
		fractol->c.y = y_to_plan(0, fractol);
		fractol->z.x = 0;
		fractol->z.y = 0;
	}
	else if (type == 1)
	{
		fractol->fractol_type = 1;
		fractol->c.x = ft_strtod(av[2], fractol);
		fractol->c.y = ft_strtod(av[3], fractol);
		fractol->z.x = x_to_plan(0, fractol);
		fractol->z.y = y_to_plan(0, fractol);
	}
}

int	init_fractol(t_fractol *fractol, char *name)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		return (1);
	fractol->windows = mlx_new_window(
			fractol->mlx,
			WIDTH,
			HEIGHT,
			name);
	fractol->image = malloc(sizeof(t_image));
	fractol->image->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->image->data = mlx_get_data_addr(fractol->image->image,
			&fractol->image->bpp,
			&fractol->image->size_line,
			&fractol->image->endian);
	data_init(fractol);
	init_hook(fractol);
	return (0);
}
// unsigned int	calcul_pixel;
// 	unsigned int	calcul_bpp;

// 	calcul_bpp = (fractol->image->bpp / 8);
// 	calcul_pixel = (y * fractol->image->size_line + x * calcul_bpp);
// 	*(unsigned int *)(fractol->image->data + calcul_pixel) = color;