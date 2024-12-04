/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:57:15 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 19:03:17 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	exit_application(t_fractol *fractol)
{
	if (fractol->windows)
		mlx_destroy_window(fractol->mlx, fractol->windows);
	if (fractol->image)
	{
		mlx_destroy_image(fractol->mlx, fractol->image->image);
		free(fractol->image);
	}
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	free(fractol->precalcul_x);
	free(fractol->precalcul_y);
	free(fractol->name);
	free(fractol);
	exit(0);
}

int	destroy_fractol(t_fractol *fractol)
{
	exit_application(fractol);
	return (0);
}
