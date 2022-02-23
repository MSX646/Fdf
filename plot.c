/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:03:52 by kezekiel          #+#    #+#             */
/*   Updated: 2022/02/11 18:05:40 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf *fdf)
{
	int	i;
	int	x0;
	int	y0;
	int	z0;

	i = 0;
	z0 = 0;
	while (i < fdf->nb_dots)
	{
		x0 = fdf->dot[i].x;
		y0 = fdf->dot[i].y;
		z0 = fdf->dot[i].z;
		if (z0 != 0)
			z0 += fdf->alt * z0;
		fdf->dot[i].x = fdf->x_offset + (x0 - y0) * cos(0.23599);
		fdf->dot[i].y = fdf->y_offset - z0 + (x0 + y0) * sin(8.623599);
		i++;
	}
}

void	refresh_map(t_fdf *fdf)
{
	my_mlx_bg_color(fdf);
	if (fdf->iso == 1)
		iso(fdf);
}

void	my_mlx_bg_color(t_fdf *fdf)
{
	int		i;
	int		color;
	char	*dst;

	color = WHITE;
	i = 0;
	while (i < (fdf->width * fdf->height))
	{
		color = 0x061c59;
		dst = fdf->addr + (i * (fdf->bpp / 8));
		*(unsigned int *)dst = color + 1;
		i++;
	}
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < fdf->width && y >= 0 && y < fdf->height)
	{
		dst = fdf->addr + (y * fdf->w_len + x * (fdf->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
