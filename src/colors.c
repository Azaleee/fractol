/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:52:06 by mosmont           #+#    #+#             */
/*   Updated: 2025/01/03 18:19:06 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	basic_color(double t, int *r, int *g, int *b)
{
	*r = (int)(9 * (1 - t) * t * t * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

void	psy_color(double t, int *r, int *g, int *b)
{
	*r = (int)(255 * fabs(sin(t * 5)));
	*g = (int)(255 * fabs(sin(t * 7)));
	*b = (int)(255 * fabs(sin(t * 9)));
}

void	vortex_color(double t, int *r, int *g, int *b)
{
	*r = (int)(fabs(sin(t * 3)) * 255);
	*g = (int)(fabs(cos(t * 20)) * 255);
	*b = (int)(fabs(sin(t * 7)) * 255);
}

void	inv_polyjssp_color(double t, int *r, int *g, int *b)
{
	*r = (int)(255 * (1 - t) * (1 - t) * 20);
	*g = (int)(255 * t * (1 - t) * 0.2);
	*b = (int)(255 * t * t + 42);
}
