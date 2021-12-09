/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:49:12 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/08 20:56:40 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_fdf *param)
{
	param->zoom = 20;
	param->z_zoom = 4;
	param->angle = 0.8;
	param->win_x = 2000;
	param->win_y = 1080;
	param->is_iso = 1;
	param->move_x = param->win_x / 3;
	param->move_y = param->win_y / 5;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->win_x, param->win_y, "FDF");
}

void	draw(t_fdf a, t_fdf b, t_fdf *param)
{
	float	dx;
	float	dy;
	float	max;

	set_param(&a, &b, param);
	dx = b.x - a.x;
	dy = b.y - a.y;
	max = ft_abs(fmodule(dx), fmodule(dy));
	dx = dx / max;
	dy = dy / max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx, param->win, a.x, a.y, (a.color));
		a.x = a.x + dx;
		a.y = a.y + dy;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	handle_matrix(t_fdf **matrix)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				draw(matrix[y][x], matrix[y + 1][x], &PRM);
			if (!matrix[y][x].is_last)
				draw(matrix[y][x], matrix[y][x + 1], &PRM);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_fdf	**matrix;
	void	*mlx;
	void	*win;

	if (argc != 2)
		return (-1);
	matrix = read_maps(argv[1]);
	if (matrix == NULL)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, 2000, 1000, "FDF");
		mlx_loop(mlx);
	}
	else
	{
		set_default(&PRM);
		handle_matrix(matrix);
		mlx_key_hook(PRM.win, handle_key, matrix);
		mlx_loop(PRM.mlx);
	}
}
