/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:09:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/21 17:21:04 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define BLUE 0xFF
# define LBLUE 0xFFFF
# define GREEN 0xFF00
# define YELLOW 0xFFFF00
# define ORANGE 0x80FF00
# define RED 0xFF0000
# define PURPLE 0x8000FF
# define PINK 0xFF00FF
# define BLACK 0x0
# define WHITE 0x00ffFFff

int	proportional_color(int percentage, int color, int max_color);
int	height_map_color(int percentage);

#endif
