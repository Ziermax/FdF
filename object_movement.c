/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:56 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 19:23:22 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "keyboard.h"

void	transform_object(t_point *point, t_matrix matrix)
{
	while (point)
	{
		point->result = vector_x_matrix(point->result, matrix);
		point->printed = 0;
		point = point->next;
	}
}

void	move_object(t_point *point, int distance, int direction)
{
	while (point)
	{
		if (distance && direction != -1 && direction == KEY_A)
			point->result.x += distance;
		else if (distance && direction != -1 && direction == KEY_S)
			point->result.y -= distance;
		else if (distance && direction != -1 && direction == KEY_D)
			point->result.x -= distance;
		else if (distance && direction != -1 && direction == KEY_W)
			point->result.y += distance;
		point->printed = 0;
		point = point->next;
	}
}

void	isometric_object(t_point *point, float scale)
{
	t_matrix	scale_mat;
	t_matrix	rot_mat_x;
	t_matrix	rot_mat_z;

	scale_mat = create_scale(scale, 100);
	rot_mat_x = create_rotation_x(M_PI * 3 / 10);
	rot_mat_z = create_rotation_z(M_PI_4);
	while (point)
	{
		point->result = vector_x_matrix(point->vector, scale_mat);
		point->result = vector_x_matrix(point->result, rot_mat_z);
		point->result = vector_x_matrix(point->result, rot_mat_x);
		point->printed = 0;
		point = point->next;
	}
}

void	paralel_object(t_point *point, float scale)
{
	t_matrix	scale_mat;

	scale_mat = create_scale(scale, 100);
	while (point)
	{
		point->result = vector_x_matrix(point->vector, scale_mat);
		point->printed = 0;
		point = point->next;
	}
}
