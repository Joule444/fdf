/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:53:25 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/09 16:27:55 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

//Trace une ligne verticale
void	vertical_line(t_mlx mlx, t_point *p1, t_point *p2)
{
	int	y;

	y = p1->win_y;
	while (y < p2->win_y)
	{
		my_mlx_pixel_put(&mlx.img, p1->win_x, y, mlx.color);
		y++;
	}
}

//Trace une ligne horizontale
void	horizontal_line(t_mlx mlx, t_point *p1, t_point *p2)
{
	int	x;

	x = p1->win_x;
	while (x < p2->win_x)
	{
		my_mlx_pixel_put(&mlx.img, x, p1->win_y, mlx.color);
		x++;
	}
}

//Trace une ligne du point 1 au point 2
void	bresenham_line(t_mlx mlx, t_point *p1, t_point *p2)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = p1->win_x;
	y1 = p1->win_y;
	x2 = p2->win_x;
	y2 = p2->win_y;
	if (x1 == x2)
		vertical_line(mlx, p1, p2);
	else if (y1 == y2)
		horizontal_line(mlx, p1, p2);
	else if (x2 > x1 && y2 > y1 && x2 - x1 > y2 - y1)
		octant_0(mlx, p1, p2);
	else if (x2 > x1 && y2 > y1 && x2 - x1 <= y2 - y1)
		octant_1(mlx, p1, p2);
	else if (x2 > x1 && y1 > y2 && x2 - x1 > y1 - y2)
		octant_7(mlx, p1, p2);
	else if (x2 > x1 && y1 > y2 && x2 - x1 <= y1 - y2)
		octant_6(mlx, p1, p2);
}
