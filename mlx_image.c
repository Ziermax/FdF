/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:40:34 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 16:46:54 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < LENGHT)
			my_mlx_pixel_put(img, x++, y, 0);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
