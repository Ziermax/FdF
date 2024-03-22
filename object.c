/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:23:31 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/20 18:46:53 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"
#include "object.h"

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
	point->color = WHITE;
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
	int		min_z;
	int		max_z;

	min_z = 0;
	max_z = 0;
	point = object->points;
	object->upleft = point;
	while (point)
	{
		set_object_height(point, 0);
		set_corners(point, object);
		set_connections(point);
		point->vector.x = point->vector.x - (object->columns - 1) / 2;
		point->vector.y = point->vector.y - (object->rows - 1) / 2;
		point = point->next;
	}
	object->slices = set_object_height(NULL, 1);
	set_color(object);
	printf("base: %d\n", min_z);
}
