/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:22:40 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/04 00:19:17 by aqadil           ###   ########.fr       */
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

#define BUFFER_SIZE 1


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int     move_x;
	int     move_y;
	int		z_scale;
	int     zoom;
	int		whichone;
	int 	**trick;
	int		height;
	int 	width;
}				t_vars;

t_vars	vars;

void okey(t_vars *vars);
void okey_in_2d(t_vars *vars);
void draw_line(float x1, float x2, float y1, float y2, t_vars *vars);
void the_freaking_3d(float *x, float *y, int z);
void ft_putnbr(int nb);
int	close_window(int keycode, t_vars *vars);
void ft_putchar(char c);
void draw_in_2d(float x1, float x2, float y1, float y2, t_vars *vars);
// reading 
int	get_width(int fd);
int	get_height(int fd);
void	fill_matrix(int *m_line, char *line);
void	read_file(char *file, t_vars *vars);

//end reading


char	*get_next_line(int fd);


char	*read_the_buffer(char *str, int fd);
char	*get_line(char *str);
char	*remove_readed_line(char *str);

int	ft_atoi(const char *str);
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

// right (+) = 69
// right (-) = 78

