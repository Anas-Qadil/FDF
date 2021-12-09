/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:05:08 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/08 16:12:21 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(int fd)
{
	char	*line;
	int		width;
	int		i;

	i = 0;
	if (fd < 0)
		error_handle(1);
	width = 0;
	line = get_next_line(fd);
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] == '\0')
			break ;
		width++;
		while (line[i] != ' ' && line[i])
			i++;
	}
	free(line);
	return (width);
}

int	get_height(int fd)
{
	int		height;
	char	*line;

	if (fd < 0)
		error_handle(1);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
	}
	free(line);
	return (height);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
