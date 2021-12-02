/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:49:12 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/02 18:03:07 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int matrix[100][100] = {
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,10,10,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0},
				{0,0,10,10,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0},
				{0,0,10,10,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0},
				{0,0,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0},
				{0,0,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
				};


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	float	x1;
	float	x2;
	float 	y1;
	float	y2;
}				t_vars;

t_vars	vars;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	close_window(int keycode, t_vars *vars)
{
	float x1 = 1000, y1 = 1000, x2 = 1, y2 = 1;
	float dx = x2 - x1;
	float dy = y2 - y1;
	float max;

	if (dx > dy)
		max = dx;
	else
		max = dy;
	if (max < 0 )
		max = -max;
	dx = dx / max;
	dy = dy / max;
	if (keycode == 0)
	{
		while ((int)(x1 - x2) || (int)(y1 - y2))
		{
			mlx_pixel_put(vars->mlx, vars->win, x1, y1, 15774330);
			x1 = x1 + dx;
			y1 = y1 + dy;
		}
	}
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		kill(getpid(), SIGINT);
	}
	return (1);
}
void ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

// int handle(int keycode , int **matrix)
// {
// 	//mlx_clear_window(vars.mlx, vars.win);
	
// 	vars.x1 += 10;
// 	vars.y1 += 10;
// 	vars.x2 += 10;
// 	vars.y2 += 10;
// 	float dx = vars.x2 - vars.x1;
// 	float dy = vars.y2 - vars.y1;
// 	float max;
	
	
// 	if (dx > dy)
// 		max = dx;
// 	else
// 		max = dy;
// 	if (max < 0 )
// 		max = -max;
// 	dx = dx / max;
// 	dy = dy / max;
// 	if (keycode == 0)
// 	{
// 		while ((int)(vars.x1 - vars.x2) || (int)(vars.y1 - vars.y2))
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, vars.x1, vars.y1, 15774330);
// 			vars.x1 = vars.x1 + dx;
// 			vars.y1 = vars.y1 + dy;
// 		}
// 	}
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(vars.mlx, vars.win);
// 		kill(getpid(), SIGINT);
// 	}
// 	return (1);
// }

void the_freaking_3d(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void draw_line(float x1, float x2, float y1, float y2)
{
	int z = 0; 
	
	z = matrix[(int)y1][(int)x1];
	int z1 = 0;
	z1 = matrix[(int)y2][(int)x2];
	int color;
	ft_putnbr(z1);
	ft_putchar('\n');
	
	if (z || z1)
		color = 15774330;
	else
		color = 16777215;
		
	// 3d
	the_freaking_3d(&x1, &y1, z);
	the_freaking_3d(&x2, &y2, z1);
	
	
	x1 = x1 * 10;
	x2 = x2 * 10;
	y1 = y1 * 10;
	y2 = y2 * 10;

	x1 += 150;
	x2 += 150;
	y1 += 150;
	y2 += 150;
	
	float dx = x2 - x1;
	float dy = y2 - y1;
	float max;

	if (dx > dy)
		max = dx;
	else
		max = dy;
	if (max < 0 )
		max = -max;
	dx = dx / max;
	dy = dy / max;

	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(vars.mlx, vars.win, x1, y1, color);
		x1 = x1 + dx;
		y1 = y1 + dy;
	}
}

int okey(int keycode, int *nothing)
{
	int x = 0;
	int y = 0;
	
	float x1 = 0, y1 = 10;
	float x2 = 400, y2 = 300;
	/*draw_line(x1, x2, y1, y2);
	int z = 10;
	the_freaking_3d(&x1, &y1, z);
	the_freaking_3d(&x2, &y2, z);
	draw_line(x1, x2, y1, y2);*/
	//draw_line(0, 500, 1, 500);

	if (keycode == 0)
	{
		while (y < 10)
		{
			x = 0;
			while (x < 19)
			{
				if (x < 19 - 1)
					draw_line(x, x + 1, y, y);
				if (y < 10 - 1)
				    draw_line(x, x, y, y + 1);
				x++;
			}
			y++;
		}
	}
	if (keycode == 53)
	{
		mlx_destroy_window(vars.mlx, vars.win);
		kill(getpid(), SIGINT);
	}
	return (1);
}

int	main(void)
{
	void *nothing;
	vars.x1 = 1000, vars.y1 = 1000, vars.x2 = 1, vars.y2 = 1;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");

	
	mlx_key_hook(vars.win, okey, nothing);
	

	mlx_string_put(vars.mlx, vars.win, 500, 500, 15774330, "XXXXXXXXXXXXX");
	mlx_loop(vars.mlx);
}
