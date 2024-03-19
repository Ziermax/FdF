/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel<       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:38:35 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/19 19:11:57 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

	new_t = proportional_trgb(percentage,
			color >> 24 & 255, max_color >> 24 & 255);
	new_r = proportional_trgb(percentage,
			color >> 16 & 255, max_color >> 16 & 255);
	new_g = proportional_trgb(percentage,
			color >> 8 & 255, max_color >> 8 & 255);
	new_b = proportional_trgb(percentage,
			color & 255, max_color & 255);
	nw_color = new_t << 24 | new_r << 16 | new_g << 8 | new_b;
	printf(" | Percentage: '%d' color: %#x\n", percentage, nw_color);
	return (nw_color);
}

int	height_map_color(int percentage)
{
	percentage = percentage * 100 / 200;
	printf("Percentage: '%d' ", percentage);
	if (percentage < 0)
	{
		printf("Opcion 0");
		return (proportional_color(percentage, 0, BLUE));
	}
	if (percentage < 100)
	{
		printf("Opcion 1");
		return (proportional_color(percentage, BLUE, LBLUE));
	}
	if (percentage < 200)
	{
		printf("Opcion 2");
		return (proportional_color(percentage - 100, LBLUE, GREEN));
	}
	if (percentage < 300)
	{
		printf("Opcion 3");
		return (proportional_color(percentage - 200, GREEN, YELLOW));
	}
	if (percentage < 400)
	{
		printf("Opcion 4");
		return (proportional_color(percentage - 300, YELLOW, RED));
	}
	if (percentage <= 500)
	{
		printf("Opcion 5");
		return (proportional_color(percentage - 400, RED, PINK));
	}
	return (proportional_color(percentage, RED + BLUE, 0));
}
