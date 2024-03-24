/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:58:44 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 19:46:38 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "display.h"
#include "keyboard.h"

int	destroy_and_leave(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_points(&vars->object->points);
	exit(0);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		destroy_and_leave(vars);
	if (keycode == KEY_SHIFT)
	{
		vars->object->only_points *= -1;
		move_view(vars->object, vars, -1);
	}
	if (keycode == KEY_1)
		isometric_view(vars->object, vars);
	if (keycode == KEY_2)
		paralel_view(vars->object, vars);
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_W
		|| keycode == KEY_S)
		move_view(vars->object, vars, keycode);
	if (keycode == KEY_PLUS || keycode == KEY_EQUAL || keycode == KEY_MINUS
		|| keycode == KEY_HYPHEN)
		scale_view(vars->object, vars, keycode);
	if (keycode == KEY_Q || keycode == KEY_E || keycode == KEY_UP
		|| keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_view(vars->object, vars, keycode);
	return (0);
}

void	display_window(t_object *obj)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, LENGHT, HEIGTH, "fdf");
	vars.object = obj;
	img.img = mlx_new_image(vars.mlx, LENGHT, HEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	vars.img = &img;
	isometric_view(vars.object, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_event, &vars);
	mlx_hook(vars.win, 17, 0, destroy_and_leave, &vars);
	mlx_loop(vars.mlx);
}

float	get_scale(int rows, int columns)
{
	float	row_scale;
	float	column_scale;

	row_scale = HEIGTH * 0.8 / rows;
	column_scale = LENGHT * 0.8 / columns;
	if (row_scale < column_scale)
		return (row_scale);
	else
		return (column_scale);
}

int	main(int argc, char **argv)
{
	t_object	object;

	if (argc != 2)
		return (0);
	object = make_object(argv[1]);
	if (!object.points)
		return (1);
	object.scale = get_scale(object.rows, object.columns);
	object.only_points = 1;
	display_window(&object);
	free_points(&object.points);
}
