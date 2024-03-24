/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:58:44 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 18:31:23 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "display.h"
#include "keyboard.h"

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
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
	mlx_loop(vars.mlx);
}

void	print_info(t_object info)
{
	printf("###INFO###:\n");
	printf("Point:\t\t%p\n", info.points);
	printf("Rows:\t\t%d\n", info.rows);
	printf("Columns:\t%d\n", info.columns);
	printf("Slices:\t\t%d\n", info.slices);
	printf("Upleft:\t\t%p\n", info.upleft);
	printf("Upright:\t%p\n", info.upright);
	printf("Downleft:\t%p\n", info.downleft);
	printf("Downright:\t%p\n", info.downright);
}

int	main(int argc, char **argv)
{
	t_object	object;

	if (argc != 3)
		return (0);
	if (argv[2][1])
		return (write(1, "Parameters syntax error\n", 24));
	object = make_object(argv[1]);
	if (!object.points)
		return (1);
	object.scale = object.slices * object.rows * object.columns;
	object.scale = argv[2][0] - '0';
	object.scale = object.scale * 10 + 5;
	object.only_points = 1;
	print_info(object);
	display_window(&object);
	free_points(&object.points);
}
