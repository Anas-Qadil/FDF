/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:49:12 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/07 00:11:44 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putnbr(nb / 10);
        ft_putchar('8');
    }
    else if (nb < 0)
    {
        ft_putchar('-');
        ft_putnbr(-nb);
    }
    else
    {
        if (nb > 9)
        {
            ft_putnbr(nb / 10);
        }
        ft_putchar(48 + nb % 10);
    }
}


void	isometric(t_vars *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	set_param(t_vars *a, t_vars *b, t_vars *param)
{
    a->x = a->x * param->zoom;
    a->y = a->y * param->zoom;
    b->x = b->x * param->zoom;
    b->y = b->y * param->zoom;
    a->z = a->z * param->z_zoom;
    b->z = b->z * param->z_zoom;
	isometric(a, 0.523599);
	isometric(b, 0.523599);
    a->x = a->x + param->move_x;
    a->y = a->y + param->move_y;
    
    b->x = b->x + param->move_x;
    b->y = b->y + param->move_y;
}

float ft_abs(float dx, float dy)
{
    float max;

    if (dx > dy)
        max = dx;
    else
        max = dy;
    if (max < 0)
        max = -max;
    return (max);
}

void    draw(t_vars a, t_vars b, t_vars *param)
{
    float dx;
    float dy;
    float max;
    
    set_param(&a, &b, param);
   

    dx = b.x - a.x;
    dy = b.y - a.y;
    max = ft_abs(dx, dy);
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

void handle_matrix(t_vars **matrix)
{
    int x = 0;
    int y = 0;

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

int    handle_key(int keycode, t_vars **matrix)
{
    if (keycode == 123)
    {
        PRM.move_x -= 50;
        mlx_clear_window(PRM.mlx, PRM.win);
        handle_matrix(matrix);
    }
    if (keycode == 126)
    {
        PRM.move_y -= 50;
        mlx_clear_window(PRM.mlx, PRM.win);
        handle_matrix(matrix);
    }
    if (keycode == 124)
    {
        PRM.move_x += 50;
        mlx_clear_window(PRM.mlx, PRM.win);
        handle_matrix(matrix);
    }
    if (keycode == 125)
    {
        PRM.move_y += 50;
        mlx_clear_window(PRM.mlx, PRM.win);
        handle_matrix(matrix);
    }
    if (keycode == 69)
    {
        PRM.zoom += 1;
        mlx_clear_window(PRM.mlx, PRM.win);
        handle_matrix(matrix);
    }
    if (keycode == 78)
    {
        PRM.zoom -= 1;
        mlx_clear_window(PRM.mlx, PRM.win);
        handle_matrix(matrix);
    }
    return (1);
}

void	set_default(t_vars *param)
{
	param->win_x = 2000;
	param->win_y = 1000;
    param->zoom = 20;
    param->z_zoom = 1;
    param->move_x = param->win_x / 3;
    param->move_y = param->win_y / 3;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->win_x, param->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	t_vars **matrix;

	matrix = read_maps("./test_maps/pyramide.fdf");
    set_default(&PRM);
    handle_matrix(matrix);

    mlx_key_hook(PRM.win, handle_key, matrix);
    mlx_loop(PRM.mlx);
}
