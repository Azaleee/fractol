/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:28:53 by mosmont           #+#    #+#             */
/*   Updated: 2025/01/03 18:56:07 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// z = x + yi
// zn+1 = z^2n + c

int	main(int ac, char **av)
{
	t_fractol	*fractol;
	int			error;

	fractol = malloc(sizeof(t_fractol));
	fractol->name = NULL;
	check_arg(ac, av, fractol);
	error = init_fractol(fractol, fractol->name);
	if (error == 1)
		exit_application(fractol);
	precalcul_coord(fractol);
	fractol_render(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
