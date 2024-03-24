/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:05:28 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 16:53:35 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "color.h"

void	draw_straight_line_x(int x[2], int y[2], int color[2], t_data *img)
{
	int	pixel_y;
	int	pixel_color;

	if (x[0] >= LENGHT || x[0] < 0)
		return ;
	pixel_y = y[0];
	while (pixel_y < y[1] || pixel_y > y[1])
	{
		pixel_color = proportional_color(
				(pixel_y - y[0]) * 100 / (y[1] - y[0]), color[0], color[1]);
		if (pixel_y < HEIGTH && pixel_y >= 0)
			my_mlx_pixel_put(img, x[0], pixel_y, pixel_color);
		if (pixel_y < y[1])
			pixel_y += 1;
		else
			pixel_y -= 1;
	}
}

void	draw_straight_line_y(int x[2], int y[2], int color[2], t_data *img)
{
	int	pixel_x;
	int	pixel_color;

	if (y[0] >= HEIGTH || y[0] < 0)
		return ;
	pixel_x = x[0];
	while (pixel_x < x[1] || pixel_x > x[1])
	{
		pixel_color = proportional_color(
				(pixel_x - x[0]) * 100 / (x[1] - x[0]), color[0], color[1]);
		if (pixel_x < LENGHT && pixel_x >= 0)
			my_mlx_pixel_put(img, pixel_x, y[0], pixel_color);
		if (pixel_x < x[1])
			pixel_x += 1;
		else
			pixel_x -= 1;
	}
}
