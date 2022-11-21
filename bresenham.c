/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:53:25 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/21 16:22:04 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	vertical_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	while (y1 < y2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y1, 0xffffff);
		y1++;
	}
}

void	horizontal_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	while (x1 < x2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y1, 0xffffff);
		x1++;
	}
}

void	bresenham_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int tmpx;
	int	tmpy;
	
	if (x1 > x2)
	{
		tmpx = x1;
		tmpy = y1;
		x1 = x2;
		y1 = y2;
		x2 = tmpx;
		y2 = tmpy;
	}
	if (x1 == x2)
		vertical_line(mlx, x1, y1, x2, y2);
	else if (y1 == y2)
		horizontal_line(mlx, x1, y1, x2, y2);
	else if (x2 > x1 && y2 > y1)
	{
		if (x2 - x1 > y2 - y1)
			octant_0(mlx, x1, y1, x2, y2);
		else
			octant_1(mlx, x1, y1, x2, y2);
	}
	else if (x2 > x1 && y1 > y2)
	{
		if (x2 - x1 > y1 - y2)
			octant_7(mlx, x1, y1, x2, y2);
		else
			octant_6(mlx, x1, y1, x2, y2);
	}
}
