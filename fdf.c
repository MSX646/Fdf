/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:09:32 by kezekiel          #+#    #+#             */
/*   Updated: 2022/02/11 18:32:46 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(char *title, t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->width = 1280;
	fdf->height = 720;
	fdf->x_offset = 0;
	fdf->y_offset = 0;
	fdf->alt = 0;
	fdf->iso = 1;
	fdf->z_highest = 0;
	fdf->z_lowest = 0;
	fdf->scale = 1;
	fdf->line_len = 20;
	fdf->title = title;
	fdf->img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->w_len, &fdf->end);
	fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->height, "FDF FDF FDF");
}

int	ft_is_valid_file(char *av)
{
	int		len;
	int		v_len;
	char	*valid;

	v_len = 3;
	valid = ".fdf";
	len = ft_strlen(av) - 1;
	while (valid[v_len])
	{
		if (valid[v_len] != av[len])
			return (0);
		v_len--;
		len--;
	}
	return (1);
}

int	check_command_line(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "USAGE: ./fdf <MAP>.fdf\n", 23);
		exit (0);
	}
	else if (ft_is_valid_file(av[1]) == 0)
	{
		write(2, "INCORRECT FILE FORMAT\n", 23);
		exit (0);
	}
	return (0);
}

int	close_fdf(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->dot);
	free(fdf);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	check_command_line(ac, av);
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	init_fdf(av[1], fdf);
	parse_map(av[1], fdf);
	connect_dots(fdf);
	print_info(fdf);
	hook_collection(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
