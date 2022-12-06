/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:52 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/06 17:08:18 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	mlx_move_keys(int keycode, t_mlx mlx)
{
	// t_point	*elem;

	if (keycode == 119)
	{
		print_list(mlx.point);
		// while (elem)
		// {
		// 	elem->win_y--;
		// 	elem = elem->next;
		// }
	}
	// else if (keycode == 97) //A
	// 	printf("A %d\n", keycode);
	// else if (keycode == 115) //S
	// 	printf("S %d\n", keycode);
	// else if (keycode == 100) //D
	// 	printf("D %d\n", keycode);
}