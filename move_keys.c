/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:52 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/05 17:48:58 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	move_up(t_mlx mlx)
{
	t_point	*elem;

	elem = *mlx.point;
	while (elem)
	{
		elem->win_y--;
		elem = elem->next;
	}
	draw_points(mlx, *mlx.point, mlx.info);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
}


void	mlx_move_keys(int keycode, t_mlx mlx)
{
	if (keycode == 119) //W
		move_up(mlx);
	// else if (keycode == 97) //A
	// 	move_left(mlx);
	// else if (keycode == 115) //S
	// 	move_down(mlx);
	// else if (keycode == 100) //D
	// 	move_right(mlx);
}