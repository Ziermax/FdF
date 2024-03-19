/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:58:44 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/19 20:38:24 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	print_point(t_point *obj)
{
	printf("(%.2f, %.2f, %.2f)\t| ",
		obj->vector.x, obj->vector.y, obj->vector.z);
	if (obj->color)
		printf("color: %#.8x:%d\n", obj->color, obj->printed);
	else
		printf("color: 0x00000000:%d\n", obj->printed);
	printf(" | lft:[%p] rgt:[%p]\n | up:[%p] dn:[%p]\n",
		obj->left, obj->right, obj->up, obj->down);
}

void	print_object(t_point *obj)
{
	int	i;

	i = 1;
	printf("\nObject Points:\n\n");
	if (!obj)
		printf("No Object created\n");
	while (obj)
	{
		printf("Point %d[%p]:  ", i++, obj);
		print_point(obj);
		obj = obj->next;
	}
	printf("\nEnd Object\n\n");
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//		printf("Point: (%.2f, %.2f, %.2f) | color: %#x\n",
//			obj->vector.x, obj->vector.y, obj->vector.z, obj->color);
//		printf(" | pixel: %d, %d\n", x, y);
void	draw_object(t_data *img, t_point *obj)
{
	int		x;
	int		y;

	while (obj)
	{
		x = obj->vector.x + LENGHT / 2;
		y = obj->vector.y + HEIGTH / 2;
		if (x < LENGHT && x >= 0 && y < HEIGTH && y >= 0)
			my_mlx_pixel_put(img, x, y, obj->color);
		obj = obj->next;
	}
}
//		draw_conections(obj, img);

void	display_window(t_point *obj)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, LENGHT, HEIGTH, "fdf");
	img.img = mlx_new_image(mlx, LENGHT, HEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_object(&img, obj);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
//	cross_line_scree(&img);

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
	isometric_object(object.points, argv[2][0] - '0');
	printf("Hola\n");
	display_window(object.points);
	free_points(&object.points);
}
