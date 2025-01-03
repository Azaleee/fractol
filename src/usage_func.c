/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:49:23 by mosmont           #+#    #+#             */
/*   Updated: 2025/01/03 19:13:48 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_usage(t_fractol *fractol)
{
	ft_printf(BOLD BLUE "==================================\n" RESET);
	ft_printf(BOLD CYAN "            FRACTOL\n" RESET);
	ft_printf(BOLD BLUE "==================================\n" RESET);
	ft_printf("\n");
	ft_printf(BOLD WHITE "Usage instructions:\n" RESET);
	ft_printf(YELLOW "  For Mandelbrot set:\n" RESET);
	ft_printf(GREEN "    fractol mandelbrot\n\n" RESET);
	ft_printf(YELLOW "  For Julia set:\n" RESET);
	ft_printf(GREEN "    fractol julia " WHITE "<c_real> <c_imaginary>\n\n");
	ft_printf(YELLOW "  For Burning Ship set:\n" RESET);
	ft_printf(GREEN "    fractol burningship\n\n" RESET);
	if (fractol->name != NULL)
		free(fractol->name);
	free(fractol);
	exit(0);
}

void	check_arg(int ac, char **av, t_fractol *fractol)
{
	if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 11) == 0))
	{
		fractol->name = ft_strdup("Mandelbrot");
		init_fractol_type(0, av, fractol);
	}
	else if (ac == 4 && (ft_strncmp(av[1], "julia", 6) == 0))
	{
		fractol->name = ft_strdup("Julia");
		init_fractol_type(1, av, fractol);
	}
	else if (ac == 2 && (ft_strncmp(av[1], "burningship", 12) == 0))
	{
		fractol->name = ft_strdup("Burningship OMGGG");
		init_fractol_type(2, av, fractol);
	}
	else
		print_usage(fractol);
}
