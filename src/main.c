/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:28:53 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/25 00:33:17 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"



int	main(void)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	init_fractol(fractol, "Test");
	ft_printf("Init : %p", fractol->image->data);
	fractol_render(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}