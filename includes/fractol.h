/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:27:17 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 21:10:51 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"

# include <stdlib.h>
# include <math.h>

# define WIDTH 500
# define HEIGHT 500
# define MAX_ITERATION 100

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
	int			colors;
	void		*image;
	char		*data;
}				t_image;

typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*windows;
	int			iteration;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_complex	z;
	t_complex	c;
	int			fractol_type;
	double		*precalcul_x;
	double		*precalcul_y;
	double		scale_x;
	double		scale_y;
	t_image		*image;
}				t_fractol;

void	init_fractol(t_fractol *fractol, char *name);
void	init_fractol_type(int type, char **av, t_fractol *fractol);
void	data_init(t_fractol *fractol);
void	exit_application(t_fractol *fractol);
int		destroy_fractol(t_fractol *fractol);
void	fractol_render(t_fractol *fractol);
void	precalcul_coord(t_fractol *fractol);
int		animation_render(t_fractol *fractol);

int		keyboard(int keycode, t_fractol *fractol);
int		mouse(int button, int x, int y, t_fractol *fractol);

double	x_to_plan(int x, t_fractol *fractol);
double	y_to_plan(int y, t_fractol *fractol);

void	check_arg(int ac, char **av, t_fractol *fractol);
void	print_usage(t_fractol *fractol);

int		ft_strncmp(const char *str1, const char *str2, size_t n);
double	ft_strtod(char *str, t_fractol *fractol);
char	*ft_strdup(char *s);

#endif