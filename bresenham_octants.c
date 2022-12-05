/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_octants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:42:06 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/05 15:06:49 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Ligne vers la droite et le bas + horizontale
void	octant_0(t_mlx mlx, t_point *p1, t_point *p2)
{
	int	x;
	int	y;
	int	a;
	int	dx;
	int	dy;
	int	error;

	x = p1->win_x;
	y = p1->win_y;
	dx = p2->win_x - p1->win_x;
	dy = p2->win_y - p1->win_y;
	a = 2 * dy;
	error = -dx;
	while (x < p2->win_x)
	{
		my_mlx_pixel_put(&mlx.img, x, y, mlx.color);
		error += a;
		if (error >= 0)
		{
			y++;
			error -= 2 * dx;
		}
		x++;
	}
}

//Ligne vers la droite et le bas + verticale
void	octant_1(t_mlx mlx, t_point *p1, t_point *p2)
{
	int	x;
	int	y;
	int	a;
	int	dx;
	int	dy;
	int	error;

	x = p1->win_x;
	y = p1->win_y;
	dx = p2->win_x - p1->win_x;
	dy = p2->win_y - p1->win_y;
	a = 2 * dx;
	error = -dy;
	while (y < p2->win_y)
	{
		my_mlx_pixel_put(&mlx.img, x, y, mlx.color);
		error += a;
		if (error >= 0)
		{
			x++;
			error -= 2 * dy;
		}
		y++;
	}
}

//Ligne vers la droite et le haut + horizontale
void	octant_7(t_mlx mlx, t_point *p1, t_point *p2)
{
	int	x;
	int	y;
	int	a;
	int	dx;
	int	dy;
	int	error;

	x = p1->win_x;
	y = p1->win_y;
	dx = p2->win_x - p1->win_x;
	dy = p1->win_y - p2->win_y;
	a = 2 * dy;
	error = -dx;
	while (x != p2->win_x)
	{
		my_mlx_pixel_put(&mlx.img, x, y, mlx.color);
		error += a;
		if (error >= 0)
		{
			y--;
			error -= 2 * dx;
		}
		x++;
	}
}

//Ligne vers la droite et le haut + verticale
void	octant_6(t_mlx mlx, t_point *p1, t_point *p2)
{
	int	x;
	int	y;
	int	a;
	int	dx;
	int	dy;
	int	error;

	x = p1->win_x;
	y = p1->win_y;
	dx = p2->win_x - p1->win_x;
	dy = y - p2->win_y;
	a = 2 * dx;
	error = -dy;
	while (y != p2->win_y)
	{
		my_mlx_pixel_put(&mlx.img, x, y, mlx.color);
		error += a;
		if (error >= 0)
		{
			x++;
			error -= 2 * dy;
		}
		y--;
	}
}
