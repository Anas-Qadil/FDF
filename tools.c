/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:07:46 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/07 19:14:07 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_movement(int keycode, t_fdf **matrix)
{
	if (keycode == 123)
		PRM.move_x -= 50;
	if (keycode == 126)
		PRM.move_y -= 50;
	if (keycode == 124)
		PRM.move_x += 50;
	if (keycode == 125)
		PRM.move_y += 50;
	if (keycode == 69)
		PRM.zoom += 1;
	if (keycode == 78)
		PRM.zoom -= 1;
}

int	handle_key(int keycode, t_fdf **matrix)
{
	mlx_clear_window(PRM.mlx, PRM.win);
	handle_movement(keycode, matrix);
	if (keycode == 49)
	{
		if (PRM.is_iso == 1)
			PRM.is_iso = 0;
		else
			PRM.is_iso = 1;
	}
	if (keycode == 0)
		PRM.angle = PRM.angle - 0.10;
	if (keycode == 11)
		PRM.angle = PRM.angle + 0.10;
	handle_matrix(matrix);
	if (keycode == 53)
		exit(-1);
	return (1);
}

void	set_param(t_fdf *a, t_fdf *b, t_fdf *param)
{
	a->x = a->x * param->zoom;
	a->y = a->y * param->zoom;
	b->x = b->x * param->zoom;
	b->y = b->y * param->zoom;
	if (param->is_iso == 1)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x = a->x + param->move_x;
	a->y = a->y + param->move_y;
	b->x = b->x + param->move_x;
	b->y = b->y + param->move_y;
}

float	ft_abs(float dx, float dy)
{
	float	max;

	if (dx > dy)
		max = dx;
	else
		max = dy;
	return (max);
}

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}
