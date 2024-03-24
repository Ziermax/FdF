/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:56:48 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 18:56:36 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	create_rotation_x(float angle)
{
	t_vector	rot_x;
	t_vector	rot_y;
	t_vector	rot_z;
	t_matrix	matrix;

	rot_x = create_vector(1, 0x00000000, 0x00000000);
	rot_y = create_vector(0, cos(angle), sin(angle));
	rot_z = create_vector(0, -sin(angle), cos(angle));
	matrix = create_matrix(rot_x, rot_y, rot_z);
	return (matrix);
}

t_matrix	create_rotation_y(float angle)
{
	t_vector	rot_x;
	t_vector	rot_y;
	t_vector	rot_z;
	t_matrix	matrix;

	rot_x = create_vector(cos(angle), 0, -sin(angle));
	rot_y = create_vector(0x00000000, 1, 0x00000000);
	rot_z = create_vector(sin(angle), 0, cos(angle));
	matrix = create_matrix(rot_x, rot_y, rot_z);
	return (matrix);
}

t_matrix	create_rotation_z(float angle)
{
	t_vector	rot_x;
	t_vector	rot_y;
	t_vector	rot_z;
	t_matrix	matrix;

	rot_x = create_vector(cos(angle), sin(angle), 0);
	rot_y = create_vector(-sin(angle), cos(angle), 0);
	rot_z = create_vector(0x00000000, 0x00000000, 1);
	matrix = create_matrix(rot_x, rot_y, rot_z);
	return (matrix);
}

t_matrix	create_scale(float scale, int percentage)
{
	t_vector	scale_x;
	t_vector	scale_y;
	t_vector	scale_z;

	scale_x = create_vector(scale, 0, 0);
	scale_y = create_vector(0, scale, 0);
	scale_z = create_vector(0, 0, scale);
	if (percentage != 100)
	{
		scale_x.x = scale_x.x * percentage / 100;
		scale_y.y = scale_y.y * percentage / 100;
		scale_z.z = scale_z.z * percentage / 100;
	}
	return (create_matrix(scale_x, scale_y, scale_z));
}
