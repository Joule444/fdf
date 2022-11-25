/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_octants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:42:06 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/25 14:17:22 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Ligne vers la droite et le bas + horizontale
void	octant_0(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int	a;
	int	dx;
	int	dy;
	int	y;
	int	error;

	dx = x2 - x1;
	dy = y2 - y1;
	a = 2 * dy;
	y = y1;
	error = -dx;
	while (x1 < x2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y, 0xffffff);
		error += a;
		if (error >= 0.0)
		{
			y++;
			error -= 2 * dx;
		}
		x1++;
	}
}

//Ligne vers la droite et le bas + verticale
void	octant_1(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int	a;
	int	dx;
	int	dy;
	int	x;
	int	error;

	dx = x2 - x1;
	dy = y2 - y1;
	a = 2 * dx;
	x = x1;
	error = -dy;
	while (y1 < y2)
	{
		my_mlx_pixel_put(&mlx.img, x, y1, 0xffffff);
		error += a;
		if (error >= 0)
		{
			x++;
			error -= 2 * dy;
		}
		y1++;
	}
}

//Ligne vers la droite et le haut + horizontale
void	octant_7(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int	a;
	int	dx;
	int	dy;
	int	y;
	int	error;

	dx = x2 - x1;
	dy = y1 - y2;
	a = 2 * dy;
	y = y1;
	error = -dx;
	while (x1 != x2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y, 0xffffff);
		error += a;
		if (error >= 0)
		{
			y--;
			error -= 2 * dx;
		}
		x1++;
	}
}

//Ligne vers la droite et le haut + verticale
void	octant_6(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int	a;
	int	dx;
	int	dy;
	int	x;
	int	error;

	dx = x2 - x1;
	dy = y1 - y2;
	a = 2 * dx;
	x = x1;
	error = -dy;
	while (y1 != y2)
	{
		my_mlx_pixel_put(&mlx.img, x, y1, 0xffffff);
		error += a;
		if (error >= 0)
		{
			x++;
			error -= 2 * dy;
		}
		y1--;
	}
}
