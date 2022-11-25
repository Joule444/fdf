/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/11/25 15:59:29 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>
 
int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_info	info;
	//Verifie si arguments valables
	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (0);
		
	mlx = mlx_win_init();
	
	mlx.point = lst_init(argv[1]);	
	info.start_x = 500;
	info.start_y = 0;
	info.zoom = 40;
	draw_points(mlx, *mlx.point, info);
	draw_lines(mlx, *mlx.point, info);
	my_lstclear(mlx.point);
	free(mlx.point);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}
