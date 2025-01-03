/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:54:46 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 20:51:26 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	x_to_plan(int x, t_fractol *fractol)
{
	return ((x * fractol->scale_x + (-2)) / fractol->zoom + fractol->offset_x);
}

double	y_to_plan(int y, t_fractol *fractol)
{
	return ((-y * fractol->scale_y + 2) / fractol->zoom + fractol->offset_y);
}
