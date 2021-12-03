/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:05:09 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/03 22:12:40 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(int fd)
{
	char	*line;
	int width;
	int	i = 0;
	
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
	return (width);
}

int	get_height(int fd)
{
	int	height;
	char	*line;

	height  = 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	return (height);
}

void	fill_matrix(int *m_line, char *line)
{
	char	**matrix;
	int	i;

	i = 0;
	matrix = ft_split(line, ' ');
	while (matrix[i])
	{
		m_line[i] = ft_atoi(matrix[i]);
		free(matrix[i]);
		i++;
	}
	m_line[i] = 0;
	free(matrix);
}

void	read_file(char *file, t_vars *vars)
{
	int	fd;
	int	width;
	int height;
	int i;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "MAP NAME DOES NOT EXIST!!\n", 26);
		return ;
	}
	vars->width = get_width(fd);
	vars->height = get_height(fd);
	vars->trick = (int **)malloc(sizeof(int *) * (vars->height + 1));
	i = 0;
	while (i <= vars->height)
		vars->trick[i++] = (int *)malloc(sizeof(int ) * (vars->width + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		fill_matrix(vars->trick[i], line);
		free(line);
		i++;
	}
	vars->trick[i] = 0;
}
// int main(int argc, char **argv)
// {
// 	t_vars *vars;
// 	int	i, j;
	
// 	vars = (t_vars *)malloc(sizeof(t_vars));
// 	read_file(argv[1], vars);
// 	i = 0;
// 	while (i < vars->height)
// 	{
// 		j = 0;
// 		while (j <= vars->width)
// 		{
// 			printf("%3d", vars->trick[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }