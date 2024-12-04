/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:00:52 by mosmont           #+#    #+#             */
/*   Updated: 2024/12/04 18:11:10 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n)
	{
		if (*s1 != *s2 || *s1 == '\0')
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}

double	ft_strtod(char *str, t_fractol *fractol)
{
	double	result;
	int		sign;
	double	i;

	result = 0.0;
	sign = 1;
	i = 10;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '.')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str++ - '0') / (i);
		i *= 10;
	}
	if (*str != '\0')
		print_usage(fractol);
	return (result * sign);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*final;

	final = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!final)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return ((char *)final);
}
