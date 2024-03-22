/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel<       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:38:35 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/20 19:32:42 by mvelazqu         ###   ########.fr       */
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
	percentage = percentage * 100 / 588;
	if (percentage < 0)
		return (proportional_color(-percentage, GREEN, BLUE));
	if (percentage < 20)
		return (GREEN);
	if (percentage < 120)
		return (proportional_color(percentage - 20, GREEN, YELLOW));
	if (percentage <= 170)
		return (proportional_color(percentage - 120, YELLOW, RED));
	else
		return (proportional_color(percentage - 150, ORANGE, PURPLE));
}
/*
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
		return (proportional_color(percentage - 400, RED, PURPLE));
	}
	return (proportional_color(percentage, RED + BLUE, 0));
}*/
