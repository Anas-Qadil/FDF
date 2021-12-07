/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:25:37 by aqadil            #+#    #+#             */
/*   Updated: 2021/12/07 22:49:05 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handle(int flag)
{
	if (flag == 1)
		write(1, "File Name Does Not Exist !!", 28);
	exit(-1);
}

void	isometric(t_fdf *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	if (dot->z <= 10)
		dot->y = (dot->x + dot->y) * sin(angle) - dot->z * 10;
	else
		dot->y = (dot->x + dot->y) * sin(angle) - dot->z * 2;
}
