/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:28:53 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 19:17:46 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	check_arg(ac, av, fractol);
	init_fractol(fractol, fractol->name);
	precalcul_coord(fractol);
	fractol_render(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
