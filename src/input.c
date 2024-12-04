/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:10:03 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 18:49:46 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse(int button, int x, int y, t_fractol *fractol)
{
	double	actual_pos_x;
	double	actual_pos_y;

	actual_pos_x = x_to_plan(x, fractol);
	actual_pos_y = y_to_plan(y, fractol);
	if (button == 4)
		fractol->zoom /= 1.1;
	else if (button == 5)
		fractol->zoom *= 1.1;
	else
		return (0);
	fractol->offset_x += actual_pos_x - x_to_plan(x, fractol);
	fractol->offset_y += actual_pos_y - y_to_plan(y, fractol);
	precalcul_coord(fractol);
	fractol_render(fractol);
	return (0);
}

int	keyboard(int keycode, t_fractol *fractol)
{
	if (keycode == 65361)
		fractol->offset_x -= 0.1 / fractol->zoom;
	else if (keycode == 65363)
		fractol->offset_x += 0.1 / fractol->zoom;
	else if (keycode == 65362)
		fractol->offset_y += 0.1 / fractol->zoom;
	else if (keycode == 65364)
		fractol->offset_y -= 0.1 / fractol->zoom;
	else if (keycode == 65436)
		fractol->image->colors *= 5;
	else if (keycode == 65307)
		exit_application(fractol);
	else
		return (0);
	precalcul_coord(fractol);
	fractol_render(fractol);
	return (0);
}
