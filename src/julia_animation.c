/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:15:33 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 20:58:53 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	animation_render(t_fractol *fractol)
{
	int	i;
	
	fractol->z.x = x_to_plan(0, fractol);
	fractol->z.y = y_to_plan(0, fractol);
	fractol->c.x = -2.0;
	fractol->c.y = -2.0;
	i = 0;
	while (fractol->c.x < 2.0)
	{
		fractol->c.y = -2.0;
		while (fractol->c.y < 2.0)
		{
			if (i % 10 == 9)
				fractol_render(fractol);
			fractol->c.y += 0.1;
			i++;
		}
		fractol->c.x += 0.1;
	}
	if (fractol->c.x >= 2.0 && fractol->c.y >= 2.0)
		exit(0);
	return (0);
}
