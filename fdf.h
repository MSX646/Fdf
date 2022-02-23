/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:31 by kezekiel          #+#    #+#             */
/*   Updated: 2022/02/11 18:24:41 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "mlx/mlx.h"

# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ZOOM_OUT 45
# define KEY_ZOOM_IN 61
# define KEY_HIGH 44
# define KEY_LOW 46
# define KEY_I 105
# define KEY_P 112

# define GREEN 0x0000FF00
# define WHITE 0x00FFFFFF

typedef struct s_dot
{
	int		x;
	int		y;
	int		z;
	double	dx;
	double	dy;
	double	steps;
	int		dcol;
	int		drow;
	int		missing;
	int		x_dir;
	int		y_dir;
	double	x_inc;
	double	y_inc;
	double	color;
}	t_dot;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		iso;
	double	scale;
	int		line_len;
	int		w_len;
	int		end;
	int		column;
	int		row;
	int		nb_dots;
	int		nb_cols;
	int		x_offset;
	int		y_offset;
	int		z_highest;
	int		z_lowest;
	char	*title;
	int		alt;
	t_dot	*dot;
	t_dot	*dot_bu;
}	t_fdf;

void	print_info(t_fdf *fdf);
void	init_fdf(char *title, t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	my_mlx_bg_color(t_fdf *fdf);
int		check_command_line(int ac, char **av);
int		ft_is_valid_file(char *av);
void	connect_dots(t_fdf *fdf);
void	get_nb_col(char *av, t_fdf *fdf);
void	get_nb_row(char *av, t_fdf *fdf);
void	parse_map(char *av, t_fdf *fdf);
int		key_arrow_move(int keycode, t_fdf *fdf);
int		key_altitude(int keycode, t_fdf *fdf);
int		key_event(int keycode, t_fdf *fdf);
void	hook_collection(t_fdf *fdf);
void	set_missing_dot_pos(int i, t_fdf *fdf);
void	set_dot_position(char **elements, t_fdf *fdf);
void	back_up_dots(t_fdf *fdf);
void	get_dda_slope(t_fdf *fdf, t_dot *a, t_dot *b);
void	fdf_line_len(t_fdf *fdf);
int		parse_color(char *elements);
int		hex_to_dec(char *elements);
int		key_transform_map(int keycode, t_fdf *fdf);
int		key_change_projection(int keycode, t_fdf *fdf);
void	key_arrow_value(int keycode, t_fdf *fdf);
void	iso(t_fdf *fdf);
void	refresh_map(t_fdf *fdf);
int		close_fdf(t_fdf *fdf);
#endif
