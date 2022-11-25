/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:53:25 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/25 17:27:41 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Trace une ligne verticale
void	vertical_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	while (y1 < y2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y1, mlx.active_color);
		y1++;
	}
}

//Trace une ligne horizontale
void	horizontal_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	while (x1 < x2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y1, mlx.active_color);
		x1++;
	}
}

void	get_active_color(t_mlx mlx, int z)
{
	int	z_max;

	z_max = get_z_max(*mlx.point);
	printf("%d\n", z);
	if (z >= 0 && z < (1 / 5) * z_max)
		mlx.active_color = 0x810202;
	if (z >= (1 / 5) * z_max && z < (2 / 5) * z_max)
		mlx.active_color = 0xfe900;
	if (z >= (2 / 5) * z_max && z < (3 / 5) * z_max)
		mlx.active_color = 0xFAA4D;
	if (z >= (3 / 5) * z_max && z < (4 / 5) * z_max)
		mlx.active_color = 0xF7276;
	if (z >= (4 / 5) * z_max && z <= z_max)
		mlx.active_color = 0x9423A;
}

//Trace une ligne du point 1 au point 2
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
	get_active_color(mlx, get_z(x2, y2, *mlx.point));
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
