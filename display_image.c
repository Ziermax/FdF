/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:44:55 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/22 20:08:30 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
/*
void	isometric_view(t_object	*object, t_vars *vars)
{
	t_data	*tmp;
	isometric_object(object->points, 1 + object->scale * 2);
	draw_object(object, vars->next_img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->next_img->img, 0, 0);
	tmp = vars->next_img;
	vars->next_img = vars->img;
	vars->img = tmp;
}

void	paralel_view(t_object *object, t_vars *vars)
{
	t_data	*tmp;
	
	paralel_object(object->points, 1 + object->scale * 2);
	draw_object(object, vars->next_img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->next_img->img, 0, 0);
	tmp = vars->next_img;
	vars->next_img = vars->img;
	vars->img = tmp;
}

void	paralel_view(t_object *obj, t_vars *vars)
{
	t_data	img;

	paralel_object(obj->points, 1 + obj->scale * 2);
	img.img = mlx_new_image(vars->mlx, obj->win_len, obj->win_hei);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_object(obj, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}*/
