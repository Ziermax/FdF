/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:58:44 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 20:59:22 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "color.h"
#include "keyboard.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_color(t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < LENGHT)
			my_mlx_pixel_put(img, x++, y, height_map_color(y * 1000 / HEIGTH));
		y++;
	}
}

void	isometric_view(t_object *obj, t_vars *vars)
{
	t_data	img;

	isometric_object(obj->points, 1 + obj->scale * 2);
	img.img = mlx_new_image(vars->mlx, obj->win_len, obj->win_hei);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_object(obj, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
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
}

//	printf("Keycode: %d | last_key: %d | res: %d\n",
//			keycode, last_key, keycode + last_key);
int	key_event(int keycode, t_vars *vars)
{
	static int	last_key;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == KEY_1)
		isometric_view(vars->object, vars);
	if (keycode == KEY_2)
		paralel_view(vars->object, vars);
	last_key = keycode;
	return (0);
}

void	display_window(t_object *obj)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, LENGHT, HEIGTH, "fdf");
	vars.object = obj;
//	isometric_view(obj, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_event, &vars);
	mlx_loop(vars.mlx);
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
	print_info(object);
	object.scale = argv[2][0] - '0';
	object.win_hei = HEIGTH;
	object.win_len = LENGHT;
	display_window(&object);
	free_points(&object.points);
}
