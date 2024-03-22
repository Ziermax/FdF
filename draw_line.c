/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:28 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 20:23:27 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"
#include "draw.h"

void	draw_line_x(int x[2], int y[2], int color[2], t_data *img)
{
	t_equation	eq;

	eq.diff_y = (y[1] - y[0]) * 100;
	eq.diff_x = x[1] - x[0];
	if (!eq.diff_x && !eq.diff_y)
		return ;
	eq.pix_x = x[0];
	eq.intercept = y[0];
	eq.intercept = y[0] - eq.diff_y * x[0] / eq.diff_x / 100;
	while (eq.pix_x < x[1] || eq.pix_x > x[1])
	{
		eq.pix_y = eq.diff_y * eq.pix_x / eq.diff_x / 100 + eq.intercept;
		eq.pix_color = proportional_color((eq.pix_x - x[0])
				* 100 / eq.diff_x, color[0], color[1]);
		if (eq.pix_y < HEIGTH && eq.pix_y >= 0
			&& eq.pix_x < LENGHT && eq.pix_x >= 0)
			my_mlx_pixel_put(img, eq.pix_x, eq.pix_y, eq.pix_color);
		eq.pix_x -= 1;
		if (eq.pix_x < x[1])
			eq.pix_x += 2;
	}
}

void	draw_line_y(int x[2], int y[2], int color[2], t_data *img)
{
	t_equation	eq;

	eq.diff_y = y[1] - y[0];
	eq.diff_x = (x[1] - x[0]) * 100;
	if (!eq.diff_x && !eq.diff_y)
		return ;
	eq.pix_y = y[0];
	eq.intercept = y[0];
	eq.intercept = y[0] - eq.diff_y * x[0] * 100 / eq.diff_x;
	while (eq.pix_y < y[1] || eq.pix_y > y[1])
	{
		eq.pix_x = (eq.pix_y - eq.intercept) * eq.diff_x / eq.diff_y / 100;
		eq.pix_color = proportional_color((eq.pix_y - y[0])
				* 100 / eq.diff_y, color[0], color[1]);
		if (eq.pix_y < HEIGTH && eq.pix_y >= 0
			&& eq.pix_x < LENGHT && eq.pix_x >= 0)
			my_mlx_pixel_put(img, eq.pix_x, eq.pix_y, eq.pix_color);
		eq.pix_y -= 1;
		if (eq.pix_y < y[1])
			eq.pix_y += 2;
	}
}

void	draw_connection(t_point *start, t_point *final, t_data *img)
{
	int	x[2];
	int	y[2];
	int	color[2];
	int	diff[2];

	x[0] = start->result.x + LENGHT / 2;
	x[1] = final->result.x + LENGHT / 2;
	y[0] = start->result.y + HEIGTH / 2;
	y[1] = final->result.y + HEIGTH / 2;
	color[0] = start->color;
	color[1] = final->color;
	diff[0] = x[1] - x[0];
	diff[1] = y[1] - y[0];
	if (!diff[0] && diff[1])
		return (draw_straight_line_x(x, y, color, img));
	if (!diff[1] && diff[0])
		return (draw_straight_line_y(x, y, color, img));
	if (diff[0] < 0)
		diff[0] = -diff[0];
	if (diff[1] < 0)
		diff[1] = -diff[1];
	if (diff[0] > diff[1])
		draw_line_x(x, y, color, img);
	else
		draw_line_y(x, y, color, img);
}

void	draw_points_connections(t_point *point, t_data *img)
{
	if (!point)
		return ;
	if (point->up && !point->up->printed)
		draw_connection(point, point->up, img);
	if (point->down && !point->down->printed)
		draw_connection(point, point->down, img);
	if (point->left && !point->left->printed)
		draw_connection(point, point->left, img);
	if (point->right && !point->right->printed)
		draw_connection(point, point->right, img);
	point->printed = 1;
}
