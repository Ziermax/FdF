/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:56:24 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 19:20:38 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

int	set_object_height(t_point *point, int done)
{
	static int	min_z;
	static int	max_z;

	if (done)
		return (max_z - min_z);
	if (point->vector.z > 0 && point->vector.z > max_z)
		max_z = point->vector.z;
	else if (point->vector.z < 0 && point->vector.z < min_z)
		min_z = point->vector.z;
	return (0);
}

void	set_corners(t_point *point, t_object *object)
{
	if (point->vector.x == object->columns - 1 && point->vector.y == 0)
		object->upright = point;
	if (point->vector.x == 0 && point->vector.y == object->rows - 1)
		object->downleft = point;
}

void	set_connections(t_point *point)
{
	static t_point	*above;
	static t_point	*tmp;
	static int		y;

	if (point->vector.y > y)
	{
		y += 1;
		above = tmp;
	}
	if (point->vector.x == 0)
		tmp = point;
	if (point->next && point->next->vector.y == y)
	{
		point->right = point->next;
		point->next->left = point;
	}
	if (above)
	{
		point->up = above;
		above->down = point;
		above = above->next;
	}
}

void	reset_colors(t_object *object, int *allow_flag, int stop)
{
	t_point	*point;
	int		i;

	point = object->points;
	*allow_flag = 0;
	i = 1;
	while (point && i < stop)
	{
		point->color = WHITE;
		point = point->next;
		i++;
	}
}

void	set_color(t_object *object)
{
	t_point	*point;
	int		z_range;
	int		z;
	int		allow;
	int		i;

	allow = 1;
	point = object->points;
	z_range = object->slices;
	i = 1;
	while (point)
	{
		z = point->vector.z;
		if (allow && (unsigned int)point->color != WHITE)
			reset_colors(object, &allow, i);
		if (allow && z_range)
			point->color = height_map_color(z * 1000 / z_range);
		point = point->next;
		i++;
	}
}
