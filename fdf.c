/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:49:12 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/30 16:38:06 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//itoa

static int	sizef(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*fill_min_int(void)
{
	char	*str;

	str = malloc(12 * sizeof(char ));
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static void	fill_the_array(char *str, int size, int sign, int n)
{
	while (--size != -1)
	{
		if (sign == 1 && size == 0)
			break ;
		str[size] = (n % 10) + 48;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		size;

	sign = 0;
	if (n == -2147483648)
		return (fill_min_int());
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	size = sizef(n);
	str = (char *)malloc((size + 1 + sign) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (sign == 1)
	{
		str[0] = '-';
		size++;
	}
	fill_the_array(str, size, sign, n);
	str[size] = '\0';
	return (str);
}


//end itoa

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keycode, t_vars *vars)
{
	char **map  = malloc(2000);
	static int i = 0;
	static int j = 0;
	while (i < 20)
		map[i++] = "XXXXXXXXXXXXX";
	static int x1 = 300;
	static int y1 = 0;
	static int x = 0;
	static int y = 0;

	static int a = 1800;
	static int b = 3;

	static int k = 0;
	static int l = 950;

	char *str = ft_itoa(keycode);

	if (keycode == 49)
	{
		l = l + 100;
	}
	if (keycode == 0)
	{
		mlx_string_put(vars->mlx, vars->win, x, y, 000000, "XXXXXXXXXXXXX");
		x = x - 5;
		y = y -5;
	}
	if (keycode == 2)
	{
		mlx_string_put(vars->mlx, vars->win, a, b, 000000, "XXXXXXXXXXXXX"); // puuting string in the middle of the window
		a = a + 5;
		b = b - 5;
	}
	if (keycode == 13)
	{
		mlx_string_put(vars->mlx, vars->win, l, k, 000000, "XXXXXXXXXXXXX"); // puuting string in the middle of the window
		k = k - 5;
	}
	if (y < 1000 && keycode == 123)
	{	
		mlx_string_put(vars->mlx, vars->win, x, y, 16711680, "XXXXXXXXXXXXX"); // puuting string in the middle of the window
		x = x + 5;
		y = y + 5;
	}
	else if (b < 1000 && keycode == 124)
	{
		mlx_string_put(vars->mlx, vars->win, a, b, 15774330, "XXXXXXXXXXXXX"); // puuting string in the middle of the window
		a = a - 5;
		b = b + 5;
	}	
	else if (k < 1000 && keycode == 126)
	{
		mlx_string_put(vars->mlx, vars->win, l, k, 65280, "XXXXXXXXXXXXX"); // puuting string in the middle of the window
		k = k + 5;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		kill(getpid(), SIGINT);
	}
	return (1);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	
	vars.mlx = mlx_init(); // create the connection
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF"); // create a window and return a void pointer to it
	
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	int i = 10;
	int j = 1280;
	int x = 1280;
	int y = 500;
	// while(i < 500 && j > 10)
	// {
	// 	my_mlx_pixel_put(&img, 1280, i, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, j, 500, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, 791, i, 0x00FF0000);
	// 	my_mlx_pixel_put(&img, j, 10, 0x00FF0000);
	// 	j--;
	// 	i++;
	// }
	// // right.....
	// x = 1280;
	// y = 10;
	// while (x <= 1290 && y >= 0)
	// {
	// 	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 	x++;
	// 	y--;
	// }
	// // left ..
	// x = 790;
	// y = 10;
	// while (x <= 800 && y >= 0)
	// {
	// 	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 	x++;
	// 	y--;
	// }

	// lte7t
	int point1x = 500;
	int point1y = 500;

	int point2x = 1500;
	int point2y = 800;
	
	x = 1280;
	y = 500;
	while(point1x < point2x || point1y < point2y)
	{
		my_mlx_pixel_put(&img, point1x, point1y, 0x00FFFFFF);
		if (point1x != point2x)
			point1x++;
		if (point2y != point1y)
			point1y++;
	}
	
	while (x <= 1380 && y >= 400)
	{
		
		my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
		x++;
		y--;
	}

	// point1(500, 500);
	// point2(1500, 800);
	// x = 1000
	// y = 650



	// y = 400;
	// while (y >= 0)
	// {
	// 	my_mlx_pixel_put(&img, 1380, y, 0x00FF0000);
	// 	y--;
	// }
	


	
	// trying to connect two points
	
	mlx_pixel_put(vars.mlx, vars.win, 300, 300, 16711680);
	mlx_pixel_put(vars.mlx, vars.win, 301, 301, 16711680);
	mlx_pixel_put(vars.mlx, vars.win, 302, 302, 16711680);
	mlx_pixel_put(vars.mlx, vars.win, 303, 303, 16711680);
	mlx_pixel_put(vars.mlx, vars.win, 304, 304, 16711680);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars); // getting keyboard input and doing somthing about it
	
	

	mlx_loop(vars.mlx); // loop the connection to keep everything up and running
}