/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:53:25 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/03 16:30:49 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	octant_1(t_mlx mlx, int x, int y, int x2, float m)
{
	float	e;

	e = 0;
	while (x <= x2)
	{
		my_mlx_pixel_put(&mlx.img, x, y, 0xffffff);
		if (e + m < 0.5)
			e += m;
		else
		{
			y++;
			e = e + m -1;
		}
		x++;
	}
}

//Trace une droite entre le point 1 et 2
void	bresenham_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int		dx;
	int		dy;
	float	m;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	m = dy / dx;
	if (x1 < x2 && 0 <= m && m <= 1)
		octant_1(mlx, x1, y1, x2, m);
}
