/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:04:18 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 17:45:04 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_point	*find_farthest_corner(t_object *object, int *case_flag)
{
	float	min;
	t_point	*min_point;

	min = object->upleft->result.z;
	min_point = object->upleft;
	*case_flag = UP_LEFT;
	if (min > object->upright->result.z)
	{
		min = object->upright->result.z;
		min_point = object->upright;
		*case_flag = UP_RIGHT;
	}
	if (min > object->downleft->result.z)
	{
		min = object->downleft->result.z;
		min_point = object->downleft;
		*case_flag = DOWN_LEFT;
	}
	if (min > object->downright->result.z)
	{
		min = object->downright->result.z;
		min_point = object->downright;
		*case_flag = DOWN_RIGHT;
	}
	return (min_point);
}

void	draw_points(t_object *object, t_data *img)
{
	t_point	*point;
	int		x;
	int		y;

	point = object->points;
	while (point)
	{
		x = point->result.x + LENGHT / 2;
		y = point->result.y + HEIGTH / 2;
		if (x < LENGHT && x >= 0 && y < HEIGTH && y >= 0)
			my_mlx_pixel_put(img, x, y, point->color);
		point = point->next;
	}
}

void	draw_object(t_object *object, t_data *img)
{
	t_point	*farthest_corner;
	int		corner_case;
	int		x;
	int		y;

	if (object->only_points < 0)
		return (draw_points(object, img));
	x = object->points->result.x + LENGHT / 2;
	y = object->points->result.y + HEIGTH / 2;
	if (x >= 0 && x < LENGHT && y >= 0 && y < HEIGTH)
		my_mlx_pixel_put(img, x, y, object->points->color);
	farthest_corner = find_farthest_corner(object, &corner_case);
	if (corner_case == UP_LEFT)
		draw_from_upleft(farthest_corner, img);
	else if (corner_case == UP_RIGHT)
		draw_from_upright(farthest_corner, img);
	else if (corner_case == DOWN_LEFT)
		draw_from_downleft(farthest_corner, img);
	else if (corner_case == DOWN_RIGHT)
		draw_from_downright(farthest_corner, img);
}
