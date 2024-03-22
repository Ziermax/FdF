/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:20:09 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 19:13:44 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fdf.h"

# define UP_LEFT 1
# define UP_RIGHT 2
# define DOWN_LEFT 3
# define DOWN_RIGHT 4

typedef struct s_equation
{
	int	diff_x;
	int	diff_y;
	int	intercept;
	int	pix_x;
	int	pix_y;
	int	pix_color;
}	t_equation;

void	draw_straight_line_x(int x[2], int y[2], int color[2], t_data *img);
void	draw_straight_line_y(int x[2], int y[2], int color[2], t_data *img);
void	draw_points_connections(t_point *point, t_data *img);
void	draw_from_upleft(t_point *point, t_data *img);
void	draw_from_upright(t_point *point, t_data *img);
void	draw_from_downleft(t_point *point, t_data *img);
void	draw_from_downright(t_point *point, t_data *img);

#endif
