/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:48:48 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/23 18:28:06 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

void	isometric_view(t_object *object, t_vars *vars);
void	paralel_view(t_object *object, t_vars *vars);
void	move_view(t_object *object, t_vars *vars, int direction);
void	scale_view(t_object *object, t_vars *vars, int direction);
void	rotate_view(t_object *object, t_vars *vars, int direction);

#endif
