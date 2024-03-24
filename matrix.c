/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:18:44 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 16:52:55 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_vector	create_vector(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_matrix	create_matrix(t_vector vec_x, t_vector vec_y, t_vector vec_z)
{
	t_matrix	matrix;

	matrix.vec_x = vec_x;
	matrix.vec_y = vec_y;
	matrix.vec_z = vec_z;
	return (matrix);
}

t_vector	vector_x_matrix(t_vector vec, t_matrix mat)
{
	t_vector	n_vec;

	n_vec.x = vec.x * mat.vec_x.x + vec.y * mat.vec_y.x + vec.z * mat.vec_z.x;
	n_vec.y = vec.x * mat.vec_x.y + vec.y * mat.vec_y.y + vec.z * mat.vec_z.y;
	n_vec.z = vec.x * mat.vec_x.z + vec.y * mat.vec_y.z + vec.z * mat.vec_z.z;
	return (n_vec);
}
