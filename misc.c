/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:03:34 by kezekiel          #+#    #+#             */
/*   Updated: 2022/02/11 18:36:42 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, \
				0xffffff, "TRANSLATE MAP : UP / DOWN / LEFT / RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 0, 20, \
				0xffffff, "EXIT : Q/ESC");
	mlx_string_put(fdf->mlx, fdf->win, 0, 40, \
				0xffffff, "ZOOM IN/OUT : +/-");
	mlx_string_put(fdf->mlx, fdf->win, 0, 60, \
				0xffffff, "ALTITUDE : </>");
	mlx_string_put(fdf->mlx, fdf->win, 0, 80, \
				0xffffff, "ISOMETRIC/PARALLEL PROJECTION : I/P");
}

void	hook_collection(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, key_event, fdf);
	mlx_hook(fdf->win, 17, 0, close_fdf, fdf);
}

void	get_dda_slope(t_fdf *fdf, t_dot *a, t_dot *b)
{
	int	i;

	i = 0;
	fdf->dot->x_dir = 1;
	fdf->dot->y_dir = 1;
	if (a[i].x > b[i].x)
		fdf->dot->x_dir = -1;
	if (a[i].y > b[i].y)
		fdf->dot->y_dir = -1;
	fdf->dot->dx = ft_absolute(b[i].x - a[i].x);
	fdf->dot->dy = ft_absolute(b[i].y - a[i].y);
	if (fdf->dot->dx > fdf->dot->dy)
		fdf->dot->steps = fdf->dot->dx;
	else
		fdf->dot->steps = fdf->dot->dy;
	fdf->dot->x_inc = fdf->dot->dx / fdf->dot->steps;
	fdf->dot->y_inc = fdf->dot->dy / fdf->dot->steps;
}

void	fdf_line_len(t_fdf *fdf)
{
	if (fdf->nb_dots > 10000)
	{
		fdf->line_len = 1;
	}
	else if (fdf->nb_dots > 900)
	{
		fdf->line_len = 5;
	}
}

int	hex_to_dec(char *elements)
{
	int	nb;
	int	len;
	int	base;
	int	decimal;

	len = ft_strlen(elements) - 1;
	base = 1;
	decimal = 0;
	while (len >= 0)
	{
		if (ft_isdigit(elements[len]))
			nb = elements[len] - '0';
		else
			nb = ft_toupper(elements[len]) - 'A' + 10;
		decimal += nb * base;
		base *= 16;
		len--;
	}
	return (decimal);
}
