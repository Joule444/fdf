/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/22 14:36:24 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>

void	draw_points(t_mlx mlx, t_point *point)
{
	while (point)
	{
		printf("%d\n", point->z);
		my_mlx_pixel_put(&mlx.img, point->x, point->y, point->color);
		point = point->next;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_point	**list;

	//Verifie si arguments valables
	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);
		
	mlx = mlx_win_init();
	
	list = lst_init(argv[1]);
	
	draw_points(mlx, *list);
	
	my_lstclear(list);
	free(list);
	
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}
