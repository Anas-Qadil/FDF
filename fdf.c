/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:49:12 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/04 00:15:58 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int matrix[100][100] = {
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,100,0,0,0},
                {0,0,10,10,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0},
                {0,0,10,10,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0},
                {0,0,10,10,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0},
                {0,0,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0},
                {0,0,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                };


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

void the_freaking_3d(float *x, float *y, int z)
{
    *x = ((*x - *y) * cos(0.8));
    *y = ((*x + *y) * sin(0.8) - z);
}

void draw_line(float x1, float x2, float y1, float y2, t_vars *vars)
{
    int z = 0;
    
    z = vars->trick[(int)y1][(int)x1];
    int z1 = 0;
    z1 = vars->trick[(int)y2][(int)x2];
    int color;
    if (z || z1)
        color = 15774330;
    else
        color = 16777215;

    x1 = (x1 * vars->zoom);
    x2 = (x2 * vars->zoom);
    y1 = (y1 * vars->zoom);
    y2 = (y2 * vars->zoom);
    
    the_freaking_3d(&x1, &y1, z);
    the_freaking_3d(&x2, &y2, z1);
    
    x1 += vars->move_x;
    x2 += vars->move_x;
    y1 += vars->move_y;
    y2 += vars->move_y;
    
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
        mlx_pixel_put(vars->mlx, vars->win, x1, y1, color);
        x1 = x1 + dx;
        y1 = y1 + dy;
    }
}

void draw_in_2d(float x1, float x2, float y1, float y2, t_vars *vars)
{
    int z = 0; 
    
    z = vars->trick[(int)y1][(int)x1];
    int z1 = 0;
    z1 = vars->trick[(int)y2][(int)x2];
    int color;
    if (z || z1)
        color = 15774330;
    else
        color = 16777215;
        
    x1 = x1 * vars->zoom;
    x2 = x2 * vars->zoom;
    y1 = y1 * vars->zoom;
    y2 = y2 * vars->zoom;
    
    x1 += vars->move_x;;
    x2 += vars->move_x;
    y1 += vars->move_y;
    y2 += vars->move_y;
    
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
        mlx_pixel_put(vars->mlx, vars->win, x1, y1, color);
        x1 = x1 + dx;
        y1 = y1 + dy;
    }
}

void okey(t_vars *vars)
{
    int x = 0;
    int y = 0;

    while (y < 10)
    {
        x = 0;
        while (x < 19)
        {
            if (x < 19 - 1)
                draw_line(x, x + 1, y, y, vars);
            if (y < 10 - 1)
                draw_line(x, x, y, y + 1, vars);
            x++;
        }
        y++; 
    }
}

void okey_in_2d(t_vars *vars)
{
    int x = 0;
    int y = 0;
    

    while (y < 10)
    {
        x = 0;
        while (x < 19)
        {
            if (x < 19 - 1)
                draw_in_2d(x, x + 1, y, y, vars);
            if (y < 10 - 1)
                draw_in_2d(x, x, y, y + 1, vars);
            x++;
        }
        y++; 
    }
}

void    handle_2d_keys(int keycode, t_vars vars)
{
    
}

int handle_key(int keycode, t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);
    if (keycode == 49)
    {
        vars->whichone = 2;
        okey_in_2d(vars);
    }
    else if (keycode == 36)
    {
        vars->whichone = 3;
        okey(vars);
    }
    if (keycode == 126 )
    {
        vars->move_y -= 100;
        if (vars->whichone == 3)
            okey(vars);
        else 
            okey_in_2d(vars);
    }
    if (keycode == 125)
    {
        vars->move_y += 100;
        if (vars->whichone == 3)
            okey(vars);
        else 
            okey_in_2d(vars);
    }
    if (keycode == 123)
    {
        vars->move_x -= 100;
        if (vars->whichone == 3)
            okey(vars);
        else 
            okey_in_2d(vars);
    }
    if (keycode == 124)
    {
        vars->move_x += 100;
        if (vars->whichone == 3)
            okey(vars);
        else 
            okey_in_2d(vars);
    }
    if (keycode == 69)
    {
        vars->zoom += 1;
        if (vars->whichone == 3)
            okey(vars);
        else 
            okey_in_2d(vars);
    }
    if (keycode == 78)
    {
        if (vars->zoom)
            vars->zoom -= 1;
        if (vars->whichone == 3)
            okey(vars);
        else 
            okey_in_2d(vars);
    }
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        kill(getpid(), SIGINT);
    }
    return (1);
}

void    setdefault(t_vars *vars)
{
    vars->move_x = 500;
    vars->move_y = 500;
    vars->whichone = 2;
    vars->zoom = 10;
}

int	main(int argc, char **argv)
{
    void *nothing;
    t_vars	*vars;
    vars = (t_vars *)malloc(sizeof(t_vars));
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FDF");
    setdefault(vars);
    // test reading from maps file
	int	i, j;
	
	
	read_file(argv[1], vars);
	i = 0;
	while (i <= vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			printf("%3d", vars->trick[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}


    // end test 

    okey_in_2d(vars);
    
    mlx_key_hook(vars->win, handle_key, vars);
    mlx_loop(vars->mlx);
}