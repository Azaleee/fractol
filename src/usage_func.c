/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:49:23 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 19:25:58 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_usage(t_fractol *fractol)
{
	ft_printf("=========================\n");
	ft_printf("\tFractol\n");
	ft_printf("=========================\n");
	ft_printf("For mandelbrot set :\n");
	ft_printf("usage : fractol mandelbrot\n\n");
	ft_printf("For julia set :\n");
	ft_printf("usage : fractol julia c ci");
	if (fractol != NULL)
		free(fractol);
	exit(0);
}

void	check_arg(int ac, char **av, t_fractol *fractol)
{
	if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0))
	{
		fractol->name = ft_strdup("Mandelbrot");
		init_fractol_type(0, av, fractol);
	}
	else if (ac == 4 && (ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 0))
	{
		fractol->name = ft_strdup("Julia");
		init_fractol_type(1, av, fractol);
	}
	else
		print_usage(fractol);
}
