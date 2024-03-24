/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:44:55 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 18:25:14 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "matrix.h"
#include "keyboard.h"

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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	move_view(t_object *object, t_vars *vars, int direction)
{
	move_object(object->points, 20, direction);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	isometric_view(t_object	*object, t_vars *vars)
{
	isometric_object(object->points, object->scale);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	paralel_view(t_object *object, t_vars *vars)
{
	paralel_object(object->points, object->scale);
	clear_image(vars, vars->img);
	draw_object(object, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
