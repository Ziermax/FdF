/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:05:28 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 21:04:43 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"
#include "draw.h"

void	draw_straight_line_x(int x[2], int y[2], int color[2], t_data *img)
{
	int	pixel_y;

	if (x[0] >= LENGHT || x[0] < 0)
		return ;
	pixel_y = y[0];
	while (pixel_y < y[1] || pixel_y > y[1])
	{
		if (pixel_y < HEIGTH && pixel_y >= 0)
		my_mlx_pixel_put(img, x[0], pixel_y, color[0]);
		if (pixel_y < y[1])
			pixel_y += 1;
		else
			pixel_y -= 1;
	}
}

void	draw_straight_line_y(int x[2], int y[2], int color[2], t_data *img)
{
	int	pixel_x;

	if (y[0] >= HEIGTH || y[0] < 0)
		return ;
	pixel_x = x[0];
	while (pixel_x < x[1] || pixel_x > x[1])
	{
		if (pixel_x < LENGHT && pixel_x >= 0)
			my_mlx_pixel_put(img, pixel_x, y[0], color[0]);
		if (pixel_x < x[1])
			pixel_x += 1;
		else
			pixel_x -= 1;
	}
}
