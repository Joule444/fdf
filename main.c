/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:28:03 by jthuysba          #+#    #+#             */
/*   Updated: 2022/12/02 17:04:45 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h>
 
t_info	scale(t_mlx mlx)
{
	t_info	info;
	
	info.start_x = 700;
	info.start_y = -100;
	if (my_lstsize(*mlx.point) < 100)
		info.zoom = 60;
	if (my_lstsize(*mlx.point) >= 100 && my_lstsize(*mlx.point) <= 200)
		info.zoom = 37;
	if (my_lstsize(*mlx.point) > 200 && my_lstsize(*mlx.point) <= 300)
		info.zoom = 35;
	if (my_lstsize(*mlx.point) > 300 && my_lstsize(*mlx.point) <= 400)
		info.zoom = 30;
	if (my_lstsize(*mlx.point) > 400 && my_lstsize(*mlx.point) <= 500)
		info.zoom = 20;
	if (my_lstsize(*mlx.point) > 500 && my_lstsize(*mlx.point) <= 2000)
		info.zoom = 19;
	if (my_lstsize(*mlx.point) > 2000 && my_lstsize(*mlx.point) <= 3000)
		info.zoom = 13;
	if (my_lstsize(*mlx.point) > 3000 && my_lstsize(*mlx.point) <= 10000)
		info.zoom = 9;
	if (my_lstsize(*mlx.point) > 10000 && my_lstsize(*mlx.point) <= 50000)
		info.zoom = 4;
	if (my_lstsize(*mlx.point) > 50000 && my_lstsize(*mlx.point) <= 100000)
		info.zoom = 3;
	if (my_lstsize(*mlx.point) > 100000)
		info.zoom = 2;
	return (info);
}

int	mlx_escape(int keycode, t_mlx mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.mlx_win);
		mlx_destroy_window(mlx.mlx_ptr, mlx.mlx_win);
		mlx_destroy_display(mlx.mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	return (printf("Bye !"), 0);
}

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
	
	info = scale(mlx);
	mlx.color = 0xf4f867;
	
	draw_points(mlx, *mlx.point, info);
	draw_lines(mlx, *mlx.point, info);
	
	my_lstclear(mlx.point);
	free(mlx.point);
	
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 1L<<0, mlx_escape, &mlx.img);
	mlx_loop(mlx.mlx_ptr);
}
