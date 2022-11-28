/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:53:25 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/28 14:42:53 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Trace une ligne verticale
void	vertical_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	while (y1 < y2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y1, mlx.color);
		y1++;
	}
}

//Trace une ligne horizontale
void	horizontal_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	while (x1 < x2)
	{
		my_mlx_pixel_put(&mlx.img, x1, y1, mlx.color);
		x1++;
	}
}

// unsigned int	get_active_color(t_mlx mlx, int z)
// {
// 	int	z_max;
//
// 	z_max = get_z_max(*mlx.point);
// 	printf("z = %d, zmax = %d\n", z, z_max);
// 	if (z >= 0 && z < ((1 / 5) * z_max) + 1)
// 		return (0xFFCCCC);
// 	if (z >= ((1 / 5) * z_max) + 1 && z < ((2 / 5) * z_max) + 1)
// 		return (0xd921cf);
// 	if (z >= ((2 / 5) * z_max) + 1 && z < ((3 / 5) * z_max) + 1)
// 		return (0xe6337a);
// 	if (z >= ((3 / 5) * z_max) + 1 && z < ((4 / 5) * z_max) + 1)
// 		return (0xd95c68);
// 	if (z >= ((4 / 5) * z_max) + 1)
// 		return (0xf46336);
// }

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
	// mlx.color = get_active_color(mlx, get_z(x2, y2, *mlx.point));
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
