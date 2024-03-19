/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:23:31 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/19 20:18:33 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_points(t_point	**obj_points)
{
	t_point	*aux;
	t_point	*tmp;

	if (!*obj_points)
		return ;
	aux = *obj_points;
	while (aux)
	{
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
	*obj_points = NULL;
}

t_point	*create_point(void)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->color = 0xFFffFFff;
	point->printed = 0;
	point->up = NULL;
	point->down = NULL;
	point->left = NULL;
	point->right = NULL;
	point->next = NULL;
	return (point);
}

void	set_object(t_object *object)
{
	t_point	*point;
	int		max_z;
	int		min_z;

	max_z = 0;
	min_z = 0;
	point = object->points;
	object->upleft = point;
	while (point->next)
	{
		if (point->vector.z > 0 && point->vector.z > max_z)
			max_z = point->vector.z;
		else if (point->vector.z < 0 && point->vector.z < min_z)
			min_z = point->vector.z;
		if (point->vector.x == object->columns - 1 && point->vector.y == 0)
			object->upright = point;
		if (point->vector.x == 0 && point->vector.y == object->rows - 1)
			object->downleft = point;
		point->vector.x = point->vector.x - (object->columns - 1) / 2;
		point->vector.y = point->vector.y - (object->rows - 1) / 2;
		point = point->next;
	}
	object->slices = max_z - min_z;
}
