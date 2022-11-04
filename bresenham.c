/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:53:25 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/04 18:40:34 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

// void	octant_1(t_mlx mlx, int x, int y, int x2, float m)
// {
// 	float	e;

// 	e = 0;
// 	while (x <= x2)
// 	{
// 		my_mlx_pixel_put(&mlx.img, x, y, 0xffffff);
// 		if (e + m < 0.5)
// 			e += m;
// 		else
// 		{
// 			y++;
// 			e = e + m -1;
// 		}
// 		x++;
// 	}
// }


void	bresenham_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	while (1)
	{
		my_mlx_pixel_put(&mlx.img, x1, y1, 0xffffff);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	bresenham_row(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	// int		dx;
	// int		dy;
	// float	m;
	int	x;

	// dx = abs(x2 - x1);
	// dy = abs(y2 - y1);
	// m = dy / dx;
	x = x1;
	while (x <= x2)
	{
		my_mlx_pixel_put(&mlx.img, iso_x(x, y1), iso_y(x, y1, 0), 0xffffff);
		x++;
	}
}

void	bresenham_column(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	// int		dx;
	// int		dy;
	// float	m;
	int	y;

	// dx = abs(x2 - x1);
	// dy = abs(y2 - y1);
	// m = dy / dx;
	y = y1;
	while (y <= y2)
	{
		my_mlx_pixel_put(&mlx.img, iso_x(x1, y), iso_y(x1, y, 0), 0xffffff);
		y++;
	}
}