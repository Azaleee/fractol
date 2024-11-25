/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:27:17 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/25 00:47:27 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"

# include <stdlib.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_image
{
	int			size_line;
	int			endian;
	int			bpp;
	void		*image;
	char		*data;
}				t_image;

typedef struct s_fractol 
{
	void	*mlx;
	void	*windows;
	int		iteration;
	double	zoom;
	double	offset_x;
	double	offset_y;
	t_image	*image;
}				t_fractol;

void	init_fractol(t_fractol *fractol, char *name);
void	fractol_render(t_fractol *fractol);

#endif