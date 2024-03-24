/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel<       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:38:35 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 18:20:52 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	proportional_trgb(int percentage, int color, int max_color)
{
	int	diff;

	diff = max_color - color;
	color = color + diff * percentage / 100;
	return (color);
}

int	proportional_color(int percentage, int color, int max_color)
{
	int	new_t;
	int	new_r;
	int	new_g;
	int	new_b;
	int	nw_color;

	if (color == max_color)
		return (color);
	new_t = proportional_trgb(percentage,
			color >> 24 & 255, max_color >> 24 & 255);
	new_r = proportional_trgb(percentage,
			color >> 16 & 255, max_color >> 16 & 255);
	new_g = proportional_trgb(percentage,
			color >> 8 & 255, max_color >> 8 & 255);
	new_b = proportional_trgb(percentage,
			color & 255, max_color & 255);
	nw_color = new_t << 24 | new_r << 16 | new_g << 8 | new_b;
	return (nw_color);
}

int	height_map_color(int percentage)
{
	percentage = percentage * 100 / 666;
	if (percentage < -100)
		return (proportional_color(100 - percentage, BLUE, BLACK));
	if (percentage < 0)
		return (proportional_color(-percentage, GREEN, BLUE));
	if (percentage < 100)
		return (proportional_color(percentage, GREEN, YELLOW));
	if (percentage <= 150)
		return (proportional_color(percentage - 100, YELLOW, RED));
	else
		return (proportional_color(percentage - 150, ORANGE, PURPLE));
}
