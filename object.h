/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:56:57 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/24 16:22:55 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "fdf.h"

typedef struct s_text
{
	char			*line;
	struct s_text	*next;
}	t_text;

//void	print_text(t_text *text);
void	free_text(t_text **text);
void	free_points(t_point **obj_points);
t_text	*read_file(char *filename);
int		get_number(char **text);
int		is_separator(char c);
t_point	*create_point(void);
void	set_object(t_object *object);
int		set_object_height(t_point *point, int done);
void	set_corners(t_point *point, t_object *object);
void	set_connections(t_point *point);
void	reset_colors(t_object *object, int *allow_flag);
void	set_color(t_object *object);

#endif
