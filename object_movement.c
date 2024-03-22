/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:56 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 20:31:00 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	move_object(t_point *object, t_matrix matrix)
{
	while (object)
	{
		object->result = vector_x_matrix(object->result, matrix);
		object = object->next;
	}
}

void	isometric_object(t_point *object, int scale)
{
	t_matrix	scale_mat;
	t_matrix	rot_mat_x;
	t_matrix	rot_mat_z;

	scale_mat = create_scale(scale);
	rot_mat_x = create_rotation_x(M_PI * 3 / 10);
	rot_mat_z = create_rotation_z(M_PI_4);
	while (object)
	{
		object->result = vector_x_matrix(object->vector, scale_mat);
		object->result = vector_x_matrix(object->result, rot_mat_z);
		object->result = vector_x_matrix(object->result, rot_mat_x);
		object = object->next;
	}
}
//		printf("\n###Operacion###\nAntes de operar:\n");
//		print_point(object);
//		printf("Despues de operar:\n");
//		print_point(object);

void	paralel_object(t_point *object, int scale)
{
	t_matrix	scale_mat;

	scale_mat = create_scale(scale);
	while (object)
	{
		object->result = vector_x_matrix(object->vector, scale_mat);
		object = object->next;
	}
}
