/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:55:34 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/25 01:25:31 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	data_init(t_fractol *fractol)
{
	fractol->iteration = 500;
	fractol->zoom = 30.0;
	fractol->offset_x = -0.4;
	fractol->offset_y = 0;
}

void	init_fractol(t_fractol *fractol, char *name)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		ft_printf("TO DO RETURN ERROR DONT FORGET !!");
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
}
