/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:56:25 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 20:27:46 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define LENGHT 1920
# define HEIGTH 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_point
{
	t_vector		vector;
	t_vector		result;
	int				color;
	int				printed;
	struct s_point	*up;
	struct s_point	*down;
	struct s_point	*left;
	struct s_point	*right;
	struct s_point	*next;
}	t_point;

typedef struct s_object
{
	t_point	*points;
	int		rows;
	int		columns;
	int		slices;
	float	scale;
	int		win_hei;
	int		win_len;
	t_point	*upleft;
	t_point	*upright;
	t_point	*downleft;
	t_point	*downright;
}	t_object;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_object	*object;
}	t_vars;

void		print_point(t_point *obj);
void		print_object(t_point *obj);
void		print_info(t_object info);
void		my_mlx_pixel_put(t_data *img, int x, int y, int color);
void		free_points(t_point **obj_points);
t_object	make_object(char *file);
void		isometric_object(t_point *object, int scale);
void		paralel_object(t_point *object, int scale);
void		draw_object(t_object *object, t_data *img);

#endif
