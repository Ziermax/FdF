/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:04:18 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 20:29:16 by mvelazqu         ###   ########.fr       */
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

void	draw_object(t_object *object, t_data *img)
{
	t_point	*farthest_corner;
	int		corner_case;

	farthest_corner = find_farthest_corner(object, &corner_case);
	if (corner_case == UP_LEFT)
		draw_from_upleft(farthest_corner, img);
	if (corner_case == UP_RIGHT)
		draw_from_upright(farthest_corner, img);
	if (corner_case == DOWN_LEFT)
		draw_from_downleft(farthest_corner, img);
	if (corner_case == DOWN_RIGHT)
		draw_from_downright(farthest_corner, img);
}
//	printf("farthest corner: [%p] case:%d\n", farthest_corner, corner_case);
