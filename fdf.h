/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:22:40 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/06 23:50:57 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
#include "libft/libft.h"
#define PRM matrix[0][0]
#define BUFFER_SIZE 10000


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	// window
	int		win_x;
	int		win_y;
	
	int		scale;
	int		z_scale;
	double	angle;
	float	x;
	float	y;
	float	z;
	
	int		is_last;
	unsigned int	color;

	int		is_iso;
	
	int     move_x;
	int     move_y;
	
	int     zoom;
	int     z_zoom;
}				t_vars;


t_vars	vars;

void ft_putnbr(int nb);
void ft_putchar(char c);
// reading 
int	get_width(int fd);
int	get_height(int fd);
void	error_handle(int flag);
void	fill_the_matrix(char *line, t_vars **matrix, int y);
t_vars	**read_maps(char *file);
t_vars	**allocate_things(char *file);

//end reading
// error handling
void	error_handle(int flag);
//

char	*get_next_line(int fd);


char	*read_the_buffer(char *str, int fd);
char	*get_line(char *str);
char	*remove_readed_line(char *str);

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);


# endif

// keycode a = 0;
// keycode b = 11;
// keycode esc = 53;
// espace = 49;
// entre = 36;


// letf arrow    123
// up arrow      126
// right arrow   124
// down arrow    125

// right (+) = 69
// right (-) = 78

