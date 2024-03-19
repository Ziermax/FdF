/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:55:11 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/19 20:11:10 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "object.h"

void	make_point(char **line, t_object *object, int column)
{
	t_point	*point;
	int		z;

	point = create_point();
	if (!point)
		return (free_points(&object->points));
	z = get_number(line);
	point->vector.x = column;
	point->vector.y = object->rows;
	point->vector.z = z;
	if (**line == ',')
	{
		*line += 1;
		point->color = get_number(line);
	}
	if (!object->points)
		object->points = point;
	else
		object->downright->next = point;
	object->downright = point;
}

int	get_points_in_row(char *line, t_object *object)
{
	int	count;

	count = 0;
	while (*line && count != object->columns)
	{
		while (is_separator(*line))
			line++;
		if (*line)
		{
			make_point(&line, object, count);
			count += 1;
		}
		if (!object->points)
			return (0);
		while (*line && !is_separator(*line))
			line++;
	}
	return (count);
}
/*
int	get_points_in_row(char *line, t_object *object)
{
	int	count;

	count = 0;
	while (*line && count != object->columns)
	{
		while (*line == ' ' || (*line >= '\t' && *line <= '\r'))
			line++;
		if (*line)
		{
			printf(" pnt:'%c' ", *line);
			make_point(&line, object, count);
			count += 1;
		}
		if (!object->points)
			return (0);
		while (*line && *line != ' ' && *line < '\t' && *line > '\r')
			printf(" skp:'%c' ", *(line++));
		if (count == 15)
			return (0);
	}
	return (count);
}*/

void	get_points(t_text *text, t_object *object)
{
	t_text	*line;
	int		counted_columns;

	line = text;
	if (!object->columns)
		object->columns = -1;
	while (line)
	{
		counted_columns = get_points_in_row(line->line, object);
		if (!object->points)
			return ;
		if (counted_columns == 0 || counted_columns < object->columns)
			return (free_points(&object->points));
		object->columns = counted_columns;
		object->rows += 1;
		line = line->next;
	}
}

t_object	make_object(char *file)
{
	t_object	object;
	t_text		*text;

	object.points = NULL;
	object.rows = 0;
	object.columns = 0;
	text = read_file(file);
	if (!text)
		return (object);
	get_points(text, &object);
	free_text(&text);
	if (!object.points)
	{
		write(2, "Making object failed\n", 21);
		return (object);
	}
	set_object(&object);
	return (object);
}
