/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:44:55 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/23 20:07:45 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "matrix.h"
#include "keyboard.h"

void	clear_image(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < LENGHT)
			my_mlx_pixel_put(img, x++, y, 0);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	rotate_view(t_object *object, t_vars *vars, int direction)
{
	t_matrix	matrix;

	if (direction == KEY_Q)
		matrix = create_rotation_z(M_PI_2 / -6);
	else if (direction == KEY_E)
		matrix = create_rotation_z(M_PI_2 / 6);
	else if (direction == KEY_UP)
		matrix = create_rotation_x(M_PI_2 / 6);
	else if (direction == KEY_DOWN)
		matrix = create_rotation_x(M_PI_2 / -6);
	else if (direction == KEY_LEFT)
		matrix = create_rotation_y(M_PI_2 / -6);
	else
		matrix = create_rotation_y(M_PI_2 / 6);
	transform_object(object->points, matrix);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	scale_view(t_object *object, t_vars *vars, int direction)
{
	t_matrix	matrix;
	int			percentage;

	if (direction == KEY_PLUS || direction == KEY_EQUAL)
		percentage = 110;
	else
		percentage = 90;
	matrix = create_scale(1, percentage);
	transform_object(object->points, matrix);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	move_view(t_object *object, t_vars *vars, int direction)
{
	move_object(object->points, 20, direction);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	isometric_view(t_object	*object, t_vars *vars)
{
	isometric_object(object->points, 1 + object->scale * 2);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	paralel_view(t_object *object, t_vars *vars)
{
	paralel_object(object->points, 1 + object->scale * 2);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
/*
void	paralel_view(t_object *obj, t_vars *vars)
{
	t_data	img;

	paralel_object(obj->points, 1 + obj->scale * 2);
	img.img = mlx_new_image(vars->mlx, obj->win_len, obj->win_hei);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_object(obj, &img);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	vars->img = &img;
}

void	isometric_view(t_object *obj, t_vars *vars)
{
	t_data	img;

	isometric_object(obj->points, 1 + obj->scale * 2);
	img.img = mlx_new_image(vars->mlx, obj->win_len, obj->win_hei);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_object(obj, &img);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	vars->img = &img;
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	vars->img = &img;
}*/
