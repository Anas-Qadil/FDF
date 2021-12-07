/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:22:40 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/07 23:03:11 by aqadil           ###   ########.fr       */
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
# define PRM matrix[0][0]
# define BUFFER_SIZE 1000

typedef struct s_fdf {
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	int				zoom;
	int				z_zoom;
	double			angle;
	float			x;
	float			y;
	float			z;
	int				is_last;
	unsigned int	color;
	int				is_iso;
	int				move_x;
	int				move_y;
}				t_fdf;

int		get_width(int fd);
int		get_height(int fd);
void	fill_the_matrix(char *line, t_fdf **matrix, int y);
t_fdf	**read_maps(char *file);
t_fdf	**allocate_things(char *file);
char	*get_next_line(int fd);
char	*read_the_buffer(char *str, int fd);
char	*get_line(char *str);
char	*remove_readed_line(char *str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
void	isometric(t_fdf *dot, double angle);
void	set_param(t_fdf *a, t_fdf *b, t_fdf *param);
void	handle_matrix(t_fdf **matrix);
void	draw(t_fdf a, t_fdf b, t_fdf *param);
float	ft_abs(float dx, float dy);
void	set_default(t_fdf *param);
void	error_handle(int flag);
float	fmodule(float i);
int		handle_key(int keycode, t_fdf **matrix);
void	free_everything(t_fdf **matrix);

#endif