/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:56:57 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/23 16:46:32 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

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
