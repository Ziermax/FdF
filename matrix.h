/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:43:44 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/19 18:59:33 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "fdf.h"

typedef struct s_matrix
{
	t_vector	vec_x;
	t_vector	vec_y;
	t_vector	vec_z;
}	t_matrix;

t_vector	create_vector(float x, float y, float z);
t_matrix	create_matrix(t_vector vec_x, t_vector vec_y, t_vector vec_z);
t_matrix	create_rotation_x(float angle);
t_matrix	create_rotation_y(float angle);
t_matrix	create_rotation_z(float angle);
t_matrix	create_scale(int scale);
t_vector	vector_x_matrix(t_vector vec, t_matrix mat);
void		move_object(t_point *object, t_matrix matrix);

#endif