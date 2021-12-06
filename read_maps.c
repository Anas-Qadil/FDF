/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:05:09 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/06 20:14:18 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int HexadecimalToDecimal(char *hex) {
    int p = 0; 
    int decimal = 0;
    int r; 
	int	i;
	unsigned int result;
	
	i = ft_strlen(hex) - 1;
	while(i >= 2)
	{
		if(hex[i]>='0'&&hex[i]<='9'){
			r = hex[i] - '0';
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F'){
			r = hex[i] - 'A' + 10;
		}
		else
		{
			r = hex[i] - 'a' + 10;
		}
		decimal = decimal + r * pow(16 , p);
		++p;
		i--;
	}
	result = (unsigned int)(decimal);
    return (result);
}


int	get_width(int fd)
{
	char	*line;
	int width;
	int	i = 0;

	if (fd < 0)
		error_handle(1);
	width = 0;
	line = get_next_line(fd);
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		width++;
		while (line[i] != ' ' && line[i])
			i++;
	}
	free(line);
	return (width);
}

int	get_height(int fd)
{
	int	height;
	char	*line;

	if (fd < 0)
		error_handle(1);
	height  = 0;
	while ((line = get_next_line(fd)))
	{
		height++;
	}
	free(line);
	return (height);
}

void	fill_the_matrix(char *line, t_vars **matrix, int y)
{
	char	**m;
	int	x;
	char	**color;

	m = ft_split(line, ' ');
	x = 0;
	while (m[x])
	{
		if (ft_strchr(m[x], ','))
		{	
			color = ft_split(m[x], ',');
			matrix[y][x].color = HexadecimalToDecimal(color[1]);
		}else
			matrix[y][x].color = 0xFFFFFF;
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].z = ft_atoi(m[x]);
		matrix[y][x].is_last = 0;
		free(m[x++]);
	}
	free(m);
	matrix[y][--x].is_last = 1;
}

void	error_handle(int flag)
{
	if (flag == 1)
		write(1, "File Name Does Not Exist !!", 29);
	exit(-1);
}

t_vars	**allocate_things(char *file)
{
	t_vars	**matrix;
	int	width;
	int	height;
	int	fd;
	char 	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handle(1);
	width = get_width(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	height = get_height(fd);
	int i = -1;
	matrix = malloc(sizeof(t_vars *) * (height + 1));
	while (++i < height)
		matrix[i] = malloc(sizeof(t_vars) * (width + 1));
	close(fd);
	return (matrix);
}

t_vars	**read_maps(char *file)
{
	t_vars	**matrix;
	int		y;
	int		fd;
	char	*line;

	matrix = allocate_things(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handle(1);
	y = 0;
	while ((line = get_next_line(fd)))
	{
		fill_the_matrix(line, matrix, y);
		y++;
	}
	free(line);
	matrix[y] = 0;
	close(fd);
	return (matrix);
}

// int	main(int argc, char **argv)
// {
// 	t_vars **matrix;

// 	matrix = read_maps("./test_maps/test.fdf");
//     int i = 0;
// 	int j = 0;
// 	int height = get_height(open("./test_maps/test.fdf", O_RDONLY));
// 	int width = get_width(open("./test_maps/test.fdf", O_RDONLY));
// 	while (matrix[i])
// 	{
// 		j = 0;
// 		while (1)
// 		{
// 			printf("%3.0f |", matrix[i][j].x);
// 			printf("%3.0f |", matrix[i][j].y);
// 			printf("%3.0f |", matrix[i][j].z);
// 			printf("%d |", matrix[i][j].color);
// 			printf("\n");
// 			if (matrix[i][j].is_last == 1)
// 				break;
// 			j++;
// 		}
// 		i++;
// 		printf("\n");
// 	}
	
// }