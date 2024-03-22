/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:14:16 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 18:43:15 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_from_upleft(t_point *point, t_data *img)
{
	t_point	*aux;

	while (point)
	{
		aux = point->down;
		while (point)
		{
			draw_points_connections(point, img);
			point = point->right;
		}
		point = aux;
	}
}

void	draw_from_upright(t_point *point, t_data *img)
{
	t_point	*aux;

	while (point)
	{
		aux = point->left;
		while (point)
		{
			draw_points_connections(point, img);
			point = point->down;
		}
		point = aux;
	}
}

void	draw_from_downleft(t_point *point, t_data *img)
{
	t_point	*aux;

	while (point)
	{
		aux = point->up;
		while (point)
		{
			draw_points_connections(point, img);
			point = point->right;
		}
		point = aux;
	}
}

void	draw_from_downright(t_point *point, t_data *img)
{
	t_point	*aux;

	while (point)
	{
		aux = point->right;
		while (point)
		{
			draw_points_connections(point, img);
			point = point->up;
		}
		point = aux;
	}
}
/*	if (!point)
		return ;
	draw_points_connections(point, img);
	if (point->left && !point->left->printed)
		draw_from_downright(point->left, img);
	if (point->up && !point->up->printed)
		draw_from_downright(point->up, img);
}*/
